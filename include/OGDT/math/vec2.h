#pragma once

namespace OGDT
{

/*
Struct: vec2
A vector in 2D space.
*/
struct vec2
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
    Constructor: vec2
    Construct a vector and set it to the origin.
    */
    vec2 () : x (0), y (0) {}

    /*
    Constructor: vec2
    Construct a vector from the given coordinates.
    */
    vec2 (float _x, float _y) : x (_x), y (_y) {}

    /*
    Constructor: vec2
    Construct a vector from the given value.

    The vector's coordinates are all set to the given value.
    */
    vec2 (float val) : x (val), y (val) {}

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
vec2 operator- (vec2);

/*
Operator: +
Add two vectors.
*/
vec2 operator+ (vec2, vec2);

/*
Operator: -
Subtract two vectors.
*/
vec2 operator- (vec2, vec2);

/*
Operator: *
Modulate two vectors (component-wise multiplication).
*/
vec2 operator* (vec2, vec2);

/*
Operator: /
Divide two vectors component-wise.
*/
vec2 operator/ (vec2, vec2);

/*
Operator: +=
Add two vectors.
*/
void operator += (vec2&, vec2);

/*
Operator: -
Subtract two vectors.
*/
void operator -= (vec2&, vec2);

/*
Operator: *=
Modulate two vectors (component-wise multiplication).
*/
void operator *= (vec2&, vec2);

/*
Operator: /=
Divide two vectors component-wise.
*/
void operator /= (vec2&, vec2);

/*
Function: norm
Return the vector's magnitude.
*/
float norm (vec2 v);

/*
Function: norm2
Return the vector's squared magnitude.
*/
float norm2 (vec2 v);

/*
Function: normalise
Return the given vector divided by its magnitude.
*/
vec2 normalise (vec2 v);

} // namespace OGDT
