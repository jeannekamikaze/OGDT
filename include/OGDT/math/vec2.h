#pragma once

#include <OGDT/OGDT.h>

namespace OGDT
{

/*
Struct: vec2
A vector in 2D space.
*/
struct DECLDIR vec2
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
DECLDIR vec2 operator- (vec2);

/*
Operator: +
Add two vectors.
*/
DECLDIR vec2 operator+ (vec2, vec2);

/*
Operator: -
Subtract two vectors.
*/
DECLDIR vec2 operator- (vec2, vec2);

/*
Operator: *
Modulate two vectors (component-wise multiplication).
*/
DECLDIR vec2 operator* (vec2, vec2);

/*
Operator: /
Divide two vectors component-wise.
*/
DECLDIR vec2 operator/ (vec2, vec2);

/*
Operator: +=
Add two vectors.
*/
DECLDIR void operator += (vec2&, vec2);

/*
Operator: -
Subtract two vectors.
*/
DECLDIR void operator -= (vec2&, vec2);

/*
Operator: *=
Modulate two vectors (component-wise multiplication).
*/
DECLDIR void operator *= (vec2&, vec2);

/*
Operator: /=
Divide two vectors component-wise.
*/
DECLDIR void operator /= (vec2&, vec2);

/*
Function: norm
Return the vector's magnitude.
*/
DECLDIR float norm (vec2 v);

/*
Function: norm2
Return the vector's squared magnitude.
*/
DECLDIR float norm2 (vec2 v);

/*
Function: normalise
Return the given vector divided by its magnitude.
*/
DECLDIR vec2 normalise (vec2 v);

} // namespace OGDT
