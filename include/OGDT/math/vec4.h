#pragma once

namespace OGDT
{

/*
Struct: vec4
A vector in 4D space.
*/
struct vec4
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
    Variable: w
    The w coordinate.
    */
    float w;

    /*
    Constructor: vec4
    Construct a vector and set it to the origin.
    */
    vec4 () : x (0), y (0), z (0), w (0) {}

    /*
    Constructor: vec4
    Construct a vector from the given coordinates.
    */
    vec4 (float _x, float _y, float _z, float _w)
        : x (_x), y (_y), z (_z), w (_w) {}

    /*
    Constructor: vec4
    Construct a vector from the given value.

    The vector's coordinates are all set to the given value.
    */
    vec4 (float val) : x (val), y (val), z (val), w (val) {}

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
vec4 operator- (vec4);

/*
Operator: +
Add two vectors.
*/
vec4 operator+ (vec4, vec4);

/*
Operator: -
Subtract two vectors.
*/
vec4 operator- (vec4, vec4);

/*
Operator: *
Modulate two vectors (component-wise multiplication).
*/
vec4 operator* (vec4, vec4);

/*
Operator: /
Divide two vectors component-wise.
*/
vec4 operator/ (vec4, vec4);

/*
Operator: +=
Add two vectors.
*/
void operator += (vec4&, vec4);

/*
Operator: -
Subtract two vectors.
*/
void operator -= (vec4&, vec4);

/*
Operator: *=
Modulate two vectors (component-wise multiplication).
*/
void operator *= (vec4&, vec4);

/*
Operator: /=
Divide two vectors component-wise.
*/
void operator /= (vec4&, vec4);

/*
Function: norm
Return the vector's magnitude.
*/
float norm (vec4 v);

/*
Function: norm2
Return the vector's squared magnitude.
*/
float norm2 (vec4 v);

} // namespace OGDT
