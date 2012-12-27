#include "MorphModel_render.h"
#include <OGDT/gl.h>


static void lerp (const vec3* v1, const vec3* v2, float p, vec3* out)
{
    out->x = v1->x + p * (v2->x - v1->x);
    out->y = v1->y + p * (v2->y - v1->y);
    out->z = v1->z + p * (v2->z - v1->z);
}


static void normal_lerp (const vec3* n1, const vec3* n2, float p, vec3* out)
{
    out->x = (1.0f - p) * n1->x + p * n2->x;
    out->y = (1.0f - p) * n1->y + p * n2->y;
    out->z = (1.0f - p) * n1->z + p * n2->z;
}


void MorphModel_render (const MorphModel* model, unsigned frame1, unsigned frame2, float p)
{
	triangle* t;
	texCoord *t1, *t2, *t3;
	vec3 no1, no2, no3;
	vec3 p1, p2, p3;
	vec3 *v11, *v12, *v13;
    vec3 *v21, *v22, *v23;
	vec3 *n11, *n12, *n13;
	vec3 *n21, *n22, *n23;
	unsigned i;
    
    vec3* verts = model->vertices;
    vec3* v1 = verts + frame1 * model->numVertices;
    vec3* v2 = verts + frame2 * model->numVertices;
    
    vec3* normals = model->normals;
    vec3* n1 = normals + frame1 * model->numVertices;
    vec3* n2 = normals + frame2 * model->numVertices;
    
    triangle* triangle  = model->triangles;
    texCoord* texCoords = model->texCoords;
    
    glBegin (GL_TRIANGLES);
    
    for (i = 0; i < model->numTriangles; ++i)
    {
        t = &triangle[i];
        
        v11 = &v1[t->vertexIndices[0]];
        v12 = &v1[t->vertexIndices[1]];
        v13 = &v1[t->vertexIndices[2]];
        
        v21 = &v2[t->vertexIndices[0]];
        v22 = &v2[t->vertexIndices[1]];
        v23 = &v2[t->vertexIndices[2]];
        
        lerp (v11, v21, p, &p1);
        lerp (v12, v22, p, &p2);
        lerp (v13, v23, p, &p3);
        
        t1 = &texCoords[t->textureIndices[0]];
        t2 = &texCoords[t->textureIndices[1]];
        t3 = &texCoords[t->textureIndices[2]];
        
        n11 = &n1[t->vertexIndices[0]];
        n12 = &n1[t->vertexIndices[1]];
        n13 = &n1[t->vertexIndices[2]];
        
        n21 = &n2[t->vertexIndices[0]];
        n22 = &n2[t->vertexIndices[1]];
        n23 = &n2[t->vertexIndices[2]];
        
        normal_lerp (n11, n21, p, &no1);
        normal_lerp (n12, n22, p, &no2);
        normal_lerp (n13, n23, p, &no3);
        
        glNormal3f   (no1.x, no1.y, no1.z);
        glTexCoord2f (t1->s, t1->t);
        glVertex3f   (p1.x, p1.y, p1.z);
        
        glNormal3f   (no2.x, no2.y, no2.z);
        glTexCoord2f (t2->s, t2->t);
        glVertex3f   (p2.x, p2.y, p2.z);
        
        glNormal3f   (no3.x, no3.y, no3.z);
        glTexCoord2f (t3->s, t3->t);
        glVertex3f   (p3.x, p3.y, p3.z);
    }
    
    glEnd ();
}


void MorphModel_render_static (const MorphModel* model, unsigned int currentFrame)
{
	triangle* t;
	vec3 *v1, *v2, *v3;
	vec3 *n1, *n2, *n3;
	texCoord *t1, *t2, *t3;
	unsigned i;

    vec3* v = model->vertices + currentFrame * model->numVertices;
    vec3* n = model->normals + currentFrame * model->numVertices;
    triangle* triangle  = model->triangles;
    texCoord* texCoords = model->texCoords;
    
    glBegin (GL_TRIANGLES);
    
    for (i = 0; i < model->numTriangles; ++i)
    {
        t = &triangle[i];
        
        v1 = &v[t->vertexIndices[0]];
        v2 = &v[t->vertexIndices[1]];
        v3 = &v[t->vertexIndices[2]];
        
        t1 = &texCoords[t->textureIndices[0]];
        t2 = &texCoords[t->textureIndices[1]];
        t3 = &texCoords[t->textureIndices[2]];
        
        n1 = &n[t->vertexIndices[0]];
        n2 = &n[t->vertexIndices[1]];
        n3 = &n[t->vertexIndices[2]];
        
        glNormal3f   (n1->x, n1->y, n1->z);
        glTexCoord2f (t1->s, t1->t);
        glVertex3f   (v1->x, v1->y, v1->z);
        
        glNormal3f   (n2->x, n2->y, n2->z);
        glTexCoord2f (t2->s, t2->t);
        glVertex3f   (v2->x, v2->y, v2->z);
        
        glNormal3f   (n3->x, n3->y, n3->z);
        glTexCoord2f (t3->s, t3->t);
        glVertex3f   (v3->x, v3->y, v3->z);
    }
    
    glEnd ();
}
