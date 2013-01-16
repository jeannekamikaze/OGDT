#pragma once

#include <OGDT/OGDT.h>
#include <OGDT/math/mat3.h>
#include <OGDT/math/mat4.h>
#include <OGDT/math/quat.h>
#include <cmath>

#ifndef __GNUG__
    #define M_E 2.71828182845904523536f
    #define M_LOG2E 1.44269504088896340736f
    #define M_LOG10E 0.434294481903251827651f
    #define M_LN2 0.693147180559945309417f
    #define M_LN10 2.30258509299404568402f
    #define M_PI 3.14159265358979323846f
    #define M_PI_2 1.57079632679489661923f
    #define M_PI_4 0.785398163397448309616f
    #define M_1_PI 0.318309886183790671538f
    #define M_2_PI 0.636619772367581343076f
    #define M_1_SQRTPI 0.564189583547756286948f
    #define M_2_SQRTPI 1.12837916709551257390f
    #define M_SQRT2 1.41421356237309504880f
    #define M_SQRT_2 0.707106781186547524401f
#endif

namespace OGDT
{

/*
Function: float_eq
Compare two floats for equality.

This function first tests a and b for equality: a == b.
If the plain equality test fails, the function checks if one of a or b is 0.
In that case, the function performs a comparison using an absolute error,
where the error is given by eps: |a-b| <= eps.
Otherwise an ULP comparison is made, where the maximum ULP distance is given by
the ULPs parameter: ULP (a-b) <= ULPs.

Parameters:

eps - The error used in the absolute comparison.
ULPs - The maximum ULP distance used in the ULP comparison.

Returns:

True if the given floats are equal, false otherwise.
*/
bool float_eq (float a, float b, float eps, int ULPs);

/*
Constant: TO_RAD
Converts degrees to radians.
*/
const float TO_RAD = M_PI / 180.0f;

/*
Constat: TO_DEG
Converts radians to degrees.
*/
const float TO_DEG = 180.0f / M_PI;

/*
Function: qmat3
Constructs a 3x3 matrix representing the same rotation as the given quaternion.
*/
DECLDIR mat3 qmat3 (const quat& q);

/*
Function: qmat3
Constructs a 4x4 matrix representing the same rotation as the given quaternion.
*/
DECLDIR mat4 qmat4 (const quat& q);

/*
Function: sign
Return the sign of the given value.
*/
DECLDIR float sign (float x);

/*
Function: pitch_from_fwd
Return the pitch formed by the given forward vector.
*/
DECLDIR float pitch_from_fwd (vec3 forward);

/*
Function: yaw_from_fwd
Return the yaw formed by the given forward vector.
*/
DECLDIR float yaw_from_fwd (vec3 forward);

} // namespace OGDT
