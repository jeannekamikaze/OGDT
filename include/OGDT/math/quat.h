#pragma once

#include <OGDT/OGDT.h>

namespace OGDT
{

struct vec3;

/*
Struct: quat
A quaternion.
*/
struct DECLDIR quat
{
    float w, x, y, z;
    
    quat () : w (1.0f), x (0.0f), y (0.0f), z (0.0f) {}
    
    quat (float _w, float _x, float _y, float _z)
        : w (_w), x (_x), y (_y), z (_z) {}
};

/*
Operator: *
Compute the product of the given two quaternions.
*/
DECLDIR quat operator* (quat q1, quat q2);

/*
Function: qrot
Compute the quaternion representing the given rotation.
*/
DECLDIR quat qrot (float angle, float x, float y, float z);

/*
Function: inv
Compute the inverse the given quaternion.
*/
DECLDIR quat inv (quat q);

/*
Function: conj
Compute the conjugate of the given quaternion.
*/
DECLDIR quat conj (quat q);

/*
Function: rot
Rotate the given vector by the given unit quaternion.
*/
DECLDIR vec3 rot (const quat& q, const vec3& v);

/*
Function: rot
Rotate the given vector by the given unit quaternion.
*/
DECLDIR void rpt (const quat& q, vec3& v);

} // namespace OGDT
