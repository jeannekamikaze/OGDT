#include <OGDT/math/quat.h>
#include <OGDT/math/vec3.h>
#include <OGDT/math/utils.h>


using namespace OGDT;


quat OGDT::operator* (quat q1, quat q2)
{
    float w, x, y, z;
    w = q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z;
    x = q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y;
    y = q1.w*q2.y - q1.x*q2.z + q1.y*q2.w + q1.z*q2.x;
    z = q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w;
    return quat (w, x, y, z);
}


quat OGDT::qrot (float angle, float x, float y, float z)
{
    float a = angle * TO_RAD * 0.5f;
    float sa = sin (a);
    float w = cos (a);
    float mag = sqrt(x*x + y*y + z*z);
    mag = mag == 0.0f ? 1.0f : mag;
    x = x * sa;
    y = y * sa;
    z = z * sa;
    return quat (w, x / mag, y / mag, z / mag);
}


quat OGDT::inv (quat q)
{
    float magsq = q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z;
    magsq = magsq == 0.0f ? 1.0f : magsq;
    return quat (q.w / magsq, -q.x / magsq, -q.y / magsq, -q.z / magsq);
}


quat OGDT::conj (quat q)
{
    return quat (q.w, -q.x, -q.y, -q.z);
}


vec3 OGDT::rot (const quat& q, const vec3& v)
{
    quat p = conj (q);
    quat qv (0, v.x, v.y, v.z);
    qv = q * qv * p;
    return vec3 (qv.x, qv.y, qv.z);
}


void rot (const quat& q, vec3& v)
{
    quat p = conj (q);
    quat qv (0, v.x, v.y, v.z);
    qv = q * qv * p;
    v.x = qv.x; v.y = qv.y; v.z = qv.z;
}
