#include <OGDT/Geometry.h>
#include <OGDT/gl.h>
#include <vector>

#include <cstdio>

#if defined(__GNUG__)
    typedef __UINT8_TYPE__ U8;
#else
    typedef unsigned __int8 U8;
#endif

using namespace OGDT;

struct buffer
{
    GLuint vao;
    GLuint vbo_vertices;
    GLuint vbo_indices;
    int index_count; // Number of indices in vbo_indices.
};

buffer create_buffer () {
    buffer b;
    glGenVertexArrays(1, &b.vao);
    glGenBuffers(1, &b.vbo_vertices);
    glGenBuffers(1, &b.vbo_indices);
    b.index_count = 0;
    return b;
}

struct Geometry::impl
{
    int vertex_vbo_size; // Vertex VBO size in bytes
    std::vector<float> vertices;
    std::vector<int> indices;
    std::vector<buffer> buffers;
    
    int vertex_vbo_offset; // Offset in bytes into the current vertex vbo.
    U32 index_vbo_offset; // Offset in bytes into the current index vbo.
    
    int vertex_size; // Vertex size in bytes.
    vertex_layout layout;
    
    // Attribute locations.
    GLint loc_position;
    GLint loc_normal;
    GLint loc_tex_coords[30];
    GLint num_tex_coords;
};

Geometry::Geometry
    (vertex_layout layout, int loc_position, int loc_normal
    ,int* loc_tex_coords, int num_tex_coords
    ,int vertex_vbo_size): my (new impl) {
    
    my->vertex_vbo_size = vertex_vbo_size;
    my->vertex_vbo_offset = 0;
    my->index_vbo_offset = 0;
    
    // Vertex layout and size
    my->layout = layout;
    int vertex_size = 0;
    if (layout & position) vertex_size += 3;
    if (layout & normal)   vertex_size += 3;
    layout = layout >> 2;
    while (layout != 0) {
        vertex_size += 2; // tex coord
        layout = layout >> 1;
    }
    my->vertex_size = vertex_size*4;
    
    // Attribute locations
    my->loc_position = loc_position;
    my->loc_normal = loc_normal;
    for (int i = 0; i < num_tex_coords; ++i) {
        my->loc_tex_coords[i] = loc_tex_coords[i];
    }
    my->num_tex_coords = num_tex_coords;
}
    
Geometry::~Geometry () {
    for (buffer& b : my->buffers) {
        glDeleteVertexArrays(1, &b.vao);
        glDeleteBuffers(1, &b.vbo_vertices);
        glDeleteBuffers(1, &b.vbo_indices);
    }
    delete my;
}

void Geometry::flush () {
    if (my->vertex_vbo_offset > 0) {
        buffer& b = my->buffers.back();
        b.index_count = my->indices.size();
        // Transfer vertices
        glBindBuffer(GL_ARRAY_BUFFER, b.vbo_vertices);
        glBufferData(GL_ARRAY_BUFFER, my->vertices.size()*4, &my->vertices[0], GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // Transfer indices
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, b.vbo_indices);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, my->indices.size()*4, &my->indices[0], GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        // Set up vao
        int vertex_size = my->vertex_size;
        glBindVertexArray(b.vao);
        glBindBuffer(GL_ARRAY_BUFFER, b.vbo_vertices);
        int layout = my->layout;
        U8* offset = (U8*) 0;
        if (my->loc_position != -1 && layout & position) {
            glEnableVertexAttribArray(my->loc_position);
            glVertexAttribPointer(my->loc_position, 3, GL_FLOAT, false, vertex_size, offset);
            offset += 3*4;
        }
        if (my->loc_normal != -1 && layout & normal) {
            glEnableVertexAttribArray(my->loc_normal);
            glVertexAttribPointer(my->loc_normal, 3, GL_FLOAT, false, vertex_size, offset);
            offset += 3*4;
        }
        layout = layout >> 2;
        for (int i = 0; layout > 0 && my->loc_tex_coords[i] != -1; ++i, layout = layout >> 1) {
            glEnableVertexAttribArray(my->loc_tex_coords[i]);
            glVertexAttribPointer(my->loc_tex_coords[i], 2, GL_FLOAT, false, vertex_size, offset);
            offset += 2*4;
        }
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        // Reset
        my->vertices.clear();
        my->indices.clear();
        my->vertex_vbo_offset = 0;
        my->index_vbo_offset = 0;
        printf("flush\n");
    }
}

void Geometry::addObject
    (const float* vertices, int num_floats
    ,const U32* indices, int num_indices) {
    // Initialise the buffer list if empty.
    if (my->buffers.size() == 0) {
        my->buffers.push_back(create_buffer());
    }
    // Make sure there is enough space.
    else {
        int nbytes_mem = my->vertices.size()*4;
        int nbytes_new = num_floats*4;
        bool enough_verts = nbytes_mem + nbytes_new < my->vertex_vbo_size;
        if (!enough_verts) {
            flush();
            my->buffers.push_back(create_buffer());
        }
    }
    
    // Copy data into vectors.
    my->vertices.reserve(my->vertices.size() + num_floats);
    my->indices.reserve(my->indices.size() + num_indices);
    for (int i = 0; i < num_floats; ++i, vertices++) {
        my->vertices.push_back(*vertices);
    }
    U32 offset = my->vertex_vbo_offset / my->vertex_size;
    for (int i = 0; i < num_indices; ++i, indices++) {
        // Transform indices by current vertex vbo offset.
        my->indices.push_back(*indices + offset);
    }
    
    my->vertex_vbo_offset += num_floats*4;
    my->index_vbo_offset += num_indices;
}

void Geometry::render () const {
    static int d = 0;
    for (const buffer& b : my->buffers) {
        glBindVertexArray(b.vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, b.vbo_indices);
        glDrawElements(GL_TRIANGLES, b.index_count, GL_UNSIGNED_INT, 0);
        if (d == 0) printf("rendering %d indices\n", b.index_count);
    }
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    d = 1;
}
