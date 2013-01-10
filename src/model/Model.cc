#include <OGDT/model/Model.h>
#include <OGDT/model/Animation.h>
#include "MorphModel.h"
#include "MorphModel_render.h"
#include "MD2/MD2_load.h"
#include <OGDT/Exception.h>
#include <OGDT/gl_utils.h>
#include <assimp/DefaultLogger.hpp>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/matrix4x4.h>
#include <assimp/scene.h>
#include <vector>


using namespace OGDT;
using namespace Assimp;
using namespace std;


struct Model::_impl
{
private:

    _impl (const _impl&);
    _impl& operator= (const _impl&);

public:

    bool clean;

    Assimp::Importer* importer;
    const aiScene* scene;
    MorphModel* morph_model;
    vector<GLuint> textures;
    vector<Animation> animations;

    _impl () :
        clean (true), importer (nullptr), scene (nullptr), morph_model (nullptr)
    {
    }

    ~_impl ()
    {
        if (importer) delete importer;
        if (clean && morph_model)
        {
            model_free (morph_model);
            delete morph_model;
        }
    }
};


std::string get_extension (const std::string& path)
{
    size_t i;
    for (i = path.length() - 1; i >= 0; --i)
    {
        if (path[i] == '.') break;
    }
    return path.substr (i+1, path.length() - i - 1);
}


std::string get_dir (const std::string& path)
{
    size_t n = path.size();
    size_t i;
    for (i = n-1; i >= 0; --i)
    {
        if (path[i] == '/' || path[i] == '\\') break;
    }
    return path.substr (0, i);
}


void assimp_load (const char* path, Assimp::Importer*& importer, const aiScene*& scene, std::vector<GLuint>& textures)
{
    // Load scene.
    importer = new Assimp::Importer;

    scene = importer->ReadFile (path, aiProcessPreset_TargetRealtime_MaxQuality);

    if (!scene)
    {
        const char* err = importer->GetErrorString();
        DefaultLogger::get()->error (err);
        throw EXCEPTION (err);
    }

    // Load textures.
    unsigned nmat = scene->mNumMaterials;
    textures.reserve (nmat);
    std::string dir = get_dir (path);

    for (unsigned i = 0; i < nmat; ++i)
    {
        const aiMaterial* mat = scene->mMaterials[i];
        aiString path;
        if (mat->GetTexture (aiTextureType_DIFFUSE, 0, &path) == AI_SUCCESS)
        {
            std::string file = dir;
            file += '/';
            file += path.C_Str();
            GLuint tex = load_texture (file.c_str());
            textures.push_back (tex);
        }
    }
}


void load_md2 (const char* path, MorphModel*& model)
{
    ostringstream os;
    os << "Failed loading " << path << ": ";
    model = new MorphModel;
    Model_error_code result = MD2_load (path, false, false, model);
    switch (result)
    {
    case Model_Success:break;
    case Model_Read_Error: os << "read error"; throw EXCEPTION (os);
    case Model_Memory_Allocation_Error: os << "memory allocation error"; throw EXCEPTION (os);
    case Model_File_Not_Found: os << "file not found"; throw EXCEPTION (os);
    case Model_File_Mismatch: os << "file mismatch"; throw EXCEPTION (os);
    default: break;
    }
}


void render (const aiScene* scene, const vector<GLuint>& textures, const aiMesh* mesh)
{
    unsigned tex = mesh->mMaterialIndex;
    glBindTexture (GL_TEXTURE_2D, textures[tex]);

    for (unsigned f = 0; f < mesh->mNumFaces; ++f)
    {
        const aiFace& face = mesh->mFaces[f];
        GLenum face_mode;
        switch (face.mNumIndices)
        {
        case 1:  face_mode = GL_POINTS; break;
        case 2:  face_mode = GL_LINES; break;
        case 3:  face_mode = GL_TRIANGLES; break;
        case 4:  face_mode = GL_QUADS; break;
        default: face_mode = GL_POLYGON; break;
        }

        glBegin (face_mode);
        for (unsigned i = 0; i < face.mNumIndices; ++i)
        {
            unsigned j = face.mIndices[i];
            if (mesh->HasVertexColors(0)) glColor4fv ((GLfloat*) &mesh->mColors[0][j]);
            if (mesh->HasTextureCoords(0)) glTexCoord2fv ((GLfloat*) &mesh->mTextureCoords[0][j]);
            if (mesh->HasNormals()) glNormal3fv ((GLfloat*) &mesh->mNormals[j].x);
            glVertex3fv (&mesh->mVertices[j].x);
        }
        glEnd ();
    }
}


void render (const aiScene* scene, const vector<GLuint>& textures, const aiNode* node)
{
    // Apply the node's transform.
    aiMatrix4x4 transf = node->mTransformation;
    transf.Transpose();
    glPushMatrix ();
    glMultMatrixf ((float*) &transf);

    // Draw meshes in this node.
    //glPushMatrix ();
    //glScalef (t.sx, t.sy, t.sz);
    for (unsigned i = 0; i < node->mNumMeshes; ++i)
    {
        const aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        render (scene, textures, mesh);
    }
    //glPopMatrix ();

    // Render children.
    for (unsigned i = 0; i < node->mNumChildren; ++i)
    {
        render (scene, textures, node->mChildren[i]);
    }

    glPopMatrix ();
}


void render (const aiScene* scene, const vector<GLuint>& textures)
{
    const aiNode* root = scene->mRootNode;
    if (root)
    {
        ::render (scene, textures, root);
        glBindTexture (GL_TEXTURE_2D, 0);
    }
}


Model::Model (const char* path) : impl (new _impl)
{
    std::string ext = get_extension (path);
    if (ext == "md2" ||ext == "MD2")
    {
        load_md2 (path, impl->morph_model);
        
        unsigned n = impl->morph_model->numAnimations;
        impl->animations.reserve (n);

        animation* anims = impl->morph_model->animations;

        for (unsigned i = 0; i < n; ++i)
        {
            animation* anim = &anims[i];
            Animation a (anim->name, anim->end - anim->start + 1, i);
            impl->animations.push_back (a);
        }
    }
    else assimp_load (path, impl->importer, impl->scene, impl->textures);
}


Model::~Model ()
{
    for (GLuint& tex : impl->textures) glDeleteTextures (impl->textures.size(), &tex);
    delete impl;
}


void Model::render (float t, const Animation* anim) const
{
    if (impl->scene) ::render (impl->scene, impl->textures);
    else
    {
        if (anim)
        {
            unsigned i = anim->id;
            animation* a = &impl->morph_model->animations[i];
            unsigned f1 = a->start + (unsigned) t;
            unsigned f2 = f1 == a->end ? a->start : f1 + 1;
            float p = t - (unsigned) t;
            MorphModel_render (impl->morph_model, f1, f2, p);
        }
        else
        {
            MorphModel_render_static (impl->morph_model, 0);
        }
    }
}


bool Model::isAnimated () const
{
    if (impl->morph_model) return impl->morph_model->numFrames > 1;
    else return false;
}


const Animation* Model::getAnimation (const char* name) const
{
    for (size_t i = 0; i < impl->animations.size(); ++i)
    {
        if (strcmp (impl->animations[i].name, name) == 0)
        {
            return &impl->animations[i];
        }
    }
    return nullptr;
}


void Model::scale (float sx, float sy, float sz)
{
    if (impl->morph_model) model_scale (impl->morph_model, sx, sy, sz);
}


void Model::pitch (float angle)
{
    if (impl->morph_model) model_pitch (impl->morph_model, angle);
}

    
void Model::yaw (float angle)
{
    if (impl->morph_model) model_yaw (impl->morph_model, angle);
}

    
void Model::roll (float angle)
{
    if (impl->morph_model) model_roll (impl->morph_model, angle);
}


void Model::toGround ()
{
    if (impl->morph_model) model_to_ground (impl->morph_model);
}


void computeAABB (const aiScene* scene, unsigned frame, float& xmin, float& xmax, float& ymin, float& ymax, float& zmin, float& zmax)
{
    bool init = true;
    for (unsigned i = 0; i < scene->mNumMeshes; ++i)
    {
        const aiMesh* mesh = scene->mMeshes[i];
        for (unsigned v = 0; v < mesh->mNumVertices; ++v)
        {
            const aiVector3D& p = mesh->mVertices[v];
            if (init)
            {
                xmin = xmax = p.x;
                ymin = ymax = p.y;
                zmin = zmax = p.z;
                init = false;
            }
            else
            {
                xmin = min (xmin, p.x);
                xmax = max (xmax, p.x);
                ymin = min (ymin, p.y);
                ymax = max (ymax, p.y);
                zmin = min (zmin, p.z);
                zmax = max (zmax, p.z);
            }
        }
    }
}


void Model::computeAABB (const char* anim, float& xmin, float& xmax, float& ymin, float& ymax, float& zmin, float& zmax) const
{
    if (impl->morph_model)
    {
        model_compute_anim_aabb (impl->morph_model, anim, &xmin, &xmax, &ymin, &ymax, &zmin, &zmax);
    }
}


void Model::computeAABB (float& xmin, float& xmax, float& ymin, float& ymax, float& zmin, float& zmax, unsigned frame) const
{
    if (impl->scene) ::computeAABB (impl->scene, frame, xmin, xmax, ymin, ymax, zmin, zmax);
    else model_compute_aabb (impl->morph_model, frame, &xmin, &xmax, &ymin, &ymax, &zmin, &zmax);
}
