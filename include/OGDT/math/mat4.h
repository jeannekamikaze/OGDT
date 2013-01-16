#pragma once

#include <OGDT/OGDT.h>
#include <OGDT/math/mat3.h>
#include <OGDT/math/vec3.h>
#include <OGDT/math/vec4.h>

namespace OGDT
{

/*
Class: mat4
A 4x4 column-major matrix.
*/
class DECLDIR mat4
{
    float val[4][4];
    
public:
    
    /*
    Constructor: mat4
    Construct a matrix and set it to the identity.
    */
    mat4 ();
    
    /*
    Constructor: mat4
    Construct a matrix from the given values.
    */
    mat4 (float m00, float m10, float m20, float m30
         ,float m01, float m11, float m21, float m31
         ,float m02, float m12, float m22, float m32
         ,float m03, float m13, float m23, float m33);
    
    /*
    Constructor: mat4
    Construct a matrix from the given vectors.
    
    Each of the vectors represents a column of the matrix.
    */
    mat4 (const vec4& v0
         ,const vec4& v1
         ,const vec4& v2
         ,const vec4& v3);
    
    /*
    Constructor: mat4
    Construct a transformation matrix from the given vectors.
    */
    mat4 (const vec3& right, const vec3& up, const vec3& forward, const vec3& position);

    /*
    Operator: ()
    Return a mutable reference to the value at the specified position.
    */
    float& operator () (int row, int col);
    
    /*
    Operator: ()
    Access the value at the specified position.
    */
    float operator() (int row, int col) const;

    /*
    Function: v0
    Return a mutable reference to the matrix's first column.
    */
    vec3& v0 ();
    
    /*
    Function: v1
    Return a mutable reference to the matrix's second column.
    */
    vec3& v1 ();
    
    /*
    Function: v2
    Return a mutable reference to the matrix's third column.
    */
    vec3& v2 ();
    
    /*
    Function: v3
    Return a mutable reference to the matrix's fourth column.
    */
    vec3& v3 ();
    
    /*
    Function: v0
    Return the matrix's first column.
    */
    const vec3& v0 () const;
    
    /*
    Function: v1
    Return the matrix's second column.
    */
    const vec3& v1 () const;
    
    /*
    Function: v2
    Return the matrix's third column.
    */
    const vec3& v2 () const;
    
    /*
    Function: v3
    Return an immutable reference to the matrix's fourth column.
    */
    const vec3& v3 () const;
    
    /*
    Operator: *
    Multiply two matrices.
    */
    mat4 operator* (const mat4&);
    
    /*
    Operator: *=
    Multiply two matrices and accumulate the result in the first operand.
    */
    void operator*= (const mat4&);

    /*
    Operator: const float*
    Return a const float pointer to the matrix's data.
    */
    operator const float* () const { return (float*) val; }

    /*
    Function: transl
    Return the translation component of the matrix.
    */
    mat4 transl () const;

    /*
    Function: rot
    Return the rotation component of the matrix.
    */
    mat4 rot () const;
    
    /*
    Function: to33
    Return the upper 3x3 portion of the matrix.
    */
    mat3 to33 () const;
    
    /*
    Function: rotx
    Create an X-axis rotation matrix.

    Parmeters:

    angle - The angle of rotation in degrees.
    */
    static mat4 rotx (float angle);
    
    /*
    Function: roty
    Create a Y-axis rotation matrix.

    Parmeters:

    angle - The angle of rotation in degrees.
    */
    static mat4 roty (float angle);
    
    /*
    Function: rotz
    Create a Z-axis rotation matrix.

    Parmeters:

    angle - The angle of rotation in degrees.
    */
    static mat4 rotz (float angle);
    
    /*
    Function: rot
    Create a rotation matrix.

    Parmeters:

    angle - The angle of rotation in degrees.
    axis  - The axis of rotation.
    */
    static mat4 rot (float angle, const vec3& axis);
    
    /*
    Function: rot
    Create a rotation matrix.

    angle - The angle of rotation in degrees.
    x - X component of the axis of rotation.
    y - Y component of the axis of rotation.
    z - Z component of the axis of rotation.
    */
    static mat4 rot (float angle, float x, float y, float z);
    
    /*
    Function: scale
    Create a scale matrix.
    
    Parameters:

    s - A vector specifying the scale factor on each axis.
    */
    static mat4 scale (const vec3& s);
    
    /*
    Function: scale
    Create a scale matrix.

    Parameters:

    sx - The scale factor on the X axis.
    sy - The scale factor on the Y axis.
    sz - The scale factor on the Z axis.
    */
    static mat4 scale (float sx, float sy, float sz);
    
    /*
    Function: transl
    Create a translation matrix.

    Parameters:

    offset - A vector specifying the translation along each axis.
    */
    static mat4 transl (const vec3& offset);
    
    /*
    Function: transl
    Create a translation matrix.

    Parameters:

    x - The amount of translation along the X axis.
    y - The amount of translation along the Y axis.
    z - The amount of translation along the Z axis.
    */
    static mat4 transl (float x, float y, float z);
    
    /*
    Constant: reflectx
    The X-axis reflection matrix.
    */
    static const mat4 reflectx;
    
    /*
    Constant: reflecty
    The Y-axis reflection matrix.
    */
    static const mat4 reflecty;
    
    /*
    Constant: reflectz
    The Z-axis reflection matrix.
    */
    static const mat4 reflectz;

    /*
    Constant: id
    The identity matrix.
    */
    static const mat4 id;

    /*
    Function: transform
    Create a transformation matrix from the given forward vector.
    */
    static mat4 transform (vec3 forward);
    
    /*
    Function: lookAt
    Create a transformation matrix.

    Parameters:

    position - The object's position.
    target - The point the object is looking at.
    */
    static mat4 lookAt (const vec3& position, const vec3& target);
    
    /*
    Function: ortho
    Create an orthographic projection matrix.

    Parameters:

    left - The coordinate for the left vertical clipping plane.
    right - The coordinate for the right vertical clipping plane.
    bottom - The coordinate for the bottom horizontal clipping plane.
    top - The coordinate for the top horizontal clipping plane.
    near - The distance to the near clipping plane.
    far - The distance to the far clipping plane.
    */
    static mat4 ortho (float left, float right, float bottom, float top, float near, float far);
    
    /*
    Function: perspective
    Create a perspective projection matrix.

    Parameters:

    fovy - The vertical field of view angle in degrees.
    aspect - The aspect ratio that determines the field of view in the x-direction.
    near - Distance to the near clipping plane.
    far - Distance to the far clipping plane.
    */
    static mat4 perspective (float fovy, float aspect, float near, float far);
};

DECLDIR mat4 inverse (const mat4& m);

DECLDIR mat4 inverse_transform (const mat4& m);

DECLDIR mat4 transpose (const mat4& m);

DECLDIR vec3 transform (const mat4&, vec3, float w);

} // namespace OGDT
