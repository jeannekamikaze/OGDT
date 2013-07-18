#pragma once

#include <OGDT/OGDT.h>

namespace OGDT
{

/*
Struct: vec3
A vector in 3D space.
*/
struct DECLDIR vec3
{
    /*
    Variable: x
    The x coordinate.
    */
    float x;

    /*
    Variable: y
    The y coordinate.
    */
    float y;

    /*
    Variable: z
    The z coordinate.
    */
    float z;
    
    /*
    Constructor: vec3
    Construct a vector and set it to the origin.
    */
    vec3 () : x (0), y (0), z (0) {}
    
    /*
    Constructor: vec3
    Construct a vector from the given coordinates.
    */
    vec3 (float _x, float _y, float _z)
        : x (_x), y (_y), z (_z) {}
    
    /*
    Constructor: vec3
    Construct a vector from the given value.

    The vector's coordinates are all set to the given value.
    */
    vec3 (float val) : x (val), y (val), z (val) {}
    
    /*
    Function: normalise
    Normalise the vector.
    */
    void normalise ();

    /*
    operator: const float*
    Return a const float pointer to the given vector's values.
    */
    operator const float* () const { return (float*) this; }
};

/*
Operator: -
Negate the given vector.
*/
DECLDIR vec3 operator- (vec3);

/*
Operator: +
Add two vectors.
*/
DECLDIR vec3 operator+ (vec3, vec3);

/*
Operator: -
Subtract two vectors.
*/
DECLDIR vec3 operator- (vec3, vec3);

/*
Operator: *
Modulate two vectors (component-wise multiplication).
*/
DECLDIR vec3 operator* (vec3, vec3);

/*
Operator: /
Divide two vectors component-wise.
*/
DECLDIR vec3 operator/ (vec3, vec3);

/*
Operator: +=
Add two vectors.
*/
DECLDIR void operator += (vec3&, vec3);

/*
Operator: -=
Subtract two vectors.
*/
DECLDIR void operator -= (vec3&, vec3);

/*
Operator: *=
Modulate two vectors (component-wise multiplication).
*/
DECLDIR void operator *= (vec3&, vec3);

/*
Operator: /=
Divide two vectors component-wise.
*/
DECLDIR void operator /= (vec3&, vec3);

/*
Function: norm
Return the vector's magnitude.
*/
DECLDIR float norm (vec3 v);

/*
Function: norm2
Return the vector's squared magnitude.
*/
DECLDIR float norm2 (vec3 v);

/*
Function: normalise
Return the given vector divided by its magnitude.
*/
DECLDIR vec3 normalise (vec3 v);

/*
Function: dot
Return given vectors' dot product.
*/
DECLDIR float dot (vec3 a, vec3 b);

/*
Function: cross
Return the given vectors' cross product.
*/
DECLDIR vec3 cross (vec3 a, vec3 b);

/*
Constant: right3
The (1, 0, 0) vector.
*/
const vec3 right3 = vec3 (1.0f, 0.0f, 0.0f);

/*
Constant: up3
The (0, 1, 0) vector.
*/
const vec3 up3 = vec3 (0.0f, 1.0f, 0.0f);

/*
Constant: forward3
The (0, 0, -1) vector.
*/
const vec3 forward3 = vec3 (0.0f, 0.0f, -1.0f);

/*
Constant: zero3
The (0, 0, 0) vector.
*/
const vec3 zero3 = vec3 (0.0f, 0.0f, 0.0f);

} // namespace OGDT
