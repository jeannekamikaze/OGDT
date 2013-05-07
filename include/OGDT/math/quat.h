#pragma once

namespace OGDT
{

struct vec3;

/*
Struct: quat
A quaternion.
*/
struct quat
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
quat operator* (quat q1, quat q2);

/*
Function: qrot
Compute the quaternion representing the given rotation.
*/
quat qrot (float angle, float x, float y, float z);

/*
Function: inv
Compute the inverse the given quaternion.
*/
quat inv (quat q);

/*
Function: conj
Compute the conjugate of the given quaternion.
*/
quat conj (quat q);

/*
Function: rot
Rotate the given vector by the given unit quaternion.
*/
vec3 rot (const quat& q, const vec3& v);

/*
Function: rot
Rotate the given vector by the given unit quaternion.
*/
void rot (const quat& q, vec3& v);

} // namespace OGDT
