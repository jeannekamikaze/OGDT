#pragma once

namespace OGDT
{

/*
Constant: DEFAULT_VBO_SIZE
*/
const int DEFAULT_VBO_SIZE = 2048;

/*
Class: Geometry
*/
class Geometry
{
    Geometry (const Geometry&);
    Geometry& operator= (const Geometry&);
    
    struct impl;
    impl* my;
    
public:
    
    /*
    Typedef: U32
    An unsigned 32 bit integer.
    */
#if defined(__GNUG__)
    typedef __UINT32_TYPE__ U32;
#else
    typedef unsigned __int32 U32;
#endif
    
    /*
    Enum: vertex_attrib
    A vertex attribute.
    
    position - (1) Indicates that vertices have position vectors.
    normal - (2) Indicates that vertices have normal vectors.
    texcoord0 - (4) Indicates that vertices have a primary texture coordinate.
    2^N - (8, 16, 32..) Indicates that vertices have extra texture coordinates.
    */
    enum vertex_attrib
    {
        position  = 1,
        normal    = 2,
        texcoord0 = 4,
        // 8, 16, 32... remaining tex coords
    };

    /*
    Typedef: vertex_layout
    An integer describing a vertex layout.
    
    A vertex layout value should be a bitwise OR of vertex_attrib values.
    
    Example:
    
    To denote that vertices have positions and normals
    
    > Geometry::vertex_layout layout = Geometry::position | Geometry::normal;
    
    Example:
    
    If vertices have extra texture coordinates, use consecutive powers of 2
    
    > Geometry::vertex_layout layout = Geometry::texcoord0 | 8 | 16 | ...;
    
    */
    typedef int vertex_layout;

    /*
    Constructor: Geometry
    Construct a new geometry pool.
    */
    Geometry (vertex_layout layout, int loc_position, int loc_normal,
              int* loc_tex_coords, int num_tex_coords,
              int vertex_vbo_size = DEFAULT_VBO_SIZE);
    
    ~Geometry ();
    
    /*
    Function: flush
    Flush recently added objects to the GPU.
    */
    void flush ();
    
    /*
    Function: addObject
    Add an object to the geometry pool.
    
    Parameters:
    
    vertices - The object's vertices.
    num_floats - The number of floats in the vertices array.
    indices - The object's indices.
    num_indices - The number of indices in the indices array.
    */
    void addObject
        (const float* vertices, int num_floats,
         const U32* indices, int num_indices);
    
    /*
    Function: render
    Render the geometry pool.
    */
    void render () const;
};

} // namespace OGDT
