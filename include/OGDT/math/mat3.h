#pragma once

namespace OGDT
{

struct vec2;
struct vec3;

/*
Class: mat3
A column-major 3x3 matrix.
*/
class mat3
{
    float val[3][3];

public:

    /*
    Constructor: mat3
    Construct a matrix and set it to the identity.
    */
    mat3 ();

    /*
    Constructor: mat3
    Construct a matrix from the given values.
    */
    mat3 (float m00, float m10, float m20
         ,float m01, float m11, float m21
         ,float m02, float m12, float m22);

    /*
    Constructor: mat3
    Construct a matrix from the given vectors.

    Each of the vectors represents a column of the matrix.
    */
    mat3 (const vec3& v0
         ,const vec3& v1
         ,const vec3& v2);

    /*
    Constructor: mat3
    Construct a transformation matrix from the given vectors.
    */
    mat3 (const vec2& right, const vec2& up, const vec2& position);

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
    vec2& v0 ();

    /*
    Function: v1
    Return a mutable reference to the matrix's second column.
    */
    vec2& v1 ();

    /*
    Function: v2
    Return a mutable reference to the matrix's third column.
    */
    vec2& v2 ();

    /*
    Function: v0
    Return the matrix's first column.
    */
    const vec2& v0 () const;

    /*
    Function: v1
    Return the matrix's second column.
    */
    const vec2& v1 () const;

    /*
    Function: v2
    Return the matrix's third column.
    */
    const vec2& v2 () const;

    /*
    Operator: *
    Multiply two matrices.
    */
    mat3 operator* (const mat3&);

    /*
    Operator: *=
    Multiply two matrices and accumulate the result in the first operand.
    */
    void operator*= (const mat3&);

    /*
    Operator: const float*
    Return a const float pointer to the matrix's data.
    */
    operator const float* () const { return (float*) val; }

    /*
    Function: transl
    Return the translation component of the matrix.
    */
    mat3 transl () const;

    /*
    Function: rot
    Return the rotation component of the matrix.
    */
    mat3 rot () const;

    /*
    Function: rot
    Create a rotation matrix.

    Parmeters:

    angle - The angle of rotation in degrees.
    */
    static mat3 rot (float angle);

    /*
    Function: scale
    Create a scale matrix.

    Parameters:

    s - A vector specifying the scale factor on each axis.
    */
    static mat3 scale (vec3 s);

    /*
    Function: scale
    Create a scale matrix.

    Parameters:

    sx - The scale factor on the X axis.
    sy - The scale factor on the Y axis.
    sz - The scale factor on the Z axis.
    */
    static mat3 scale (float x, float y, float z);

    /*
    Function: transl
    Create a translation matrix.

    Parameters:

    offset - A vector specifying the translation along each axis.
    */
    static mat3 transl (vec2 offset);

    /*
    Function: transl
    Create a translation matrix.

    Parameters:

    x - The amount of translation along the X axis.
    y - The amount of translation along the Y axis.
    */
    static mat3 transl (float x, float y);

    /*
    Constant: reflectx
    The X-axis reflection matrix.
    */
    static const mat3 reflectx;

    /*
    Constant: reflecty
    The Y-axis reflection matrix.
    */
    static const mat3 reflecty;

    /*
    Constant: reflectz
    The Z-axis reflection matrix.
    */
    static const mat3 reflectz;

    /*
    Constant: id
    The identity matrix.
    */
    static const mat3 id;
};

mat3 inverse (const mat3&);

mat3 transpose (const mat3&);

vec3 operator* (const mat3&, vec3);

} // namespace OGDT
