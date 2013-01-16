#include <OGDT/math/utils.h>


using namespace OGDT;


union Float
{
    float f;
    int i;

    Float (float _f) : f (_f) {}

    bool positive () const { return i >= 0; }
};


bool OGDT::float_eq (float a, float b, float eps, int ULPs)
{
    if (a == b) return true;
    else if (a*b == 0.0f)
    {
        return fabs(a-b) <= eps;
    }
    else
    {
        Float x (a);
        Float y (b);
        if (x.positive() != y.positive()) return false;
        int diff = std::abs (x.i - y.i);
        return diff <= ULPs;
    }
}


mat3 OGDT::qmat3 (const quat& q)
{
    float x = q.x;
    float y = q.y;
    float z = q.z;
    float w = q.w;
    float xx = x*x;
    float xy = x*y;
    float xz = x*z;
    float yy = y*y;
    float yz = y*z;
    float zz = z*z;
    float wx = w*x;
    float wy = w*y;
    float wz = w*z;

    return mat3
        ( 1- 2*yy - 2*zz, 2*xy + 2*wz    , 2*xz - 2*wy
        , 2*xy - 2*wz,    1 - 2*xx - 2*zz, 2*yz + 2*wx
        , 2*xz + 2*wy,    2*yz - 2*wx    , 1 - 2*xx - 2*yy);
}


mat4 OGDT::qmat4 (const quat& q)
{
    float x = q.x;
    float y = q.y;
    float z = q.z;
    float w = q.w;
    float xx = x*x;
    float xy = x*y;
    float xz = x*z;
    float yy = y*y;
    float yz = y*z;
    float zz = z*z;
    float wx = w*x;
    float wy = w*y;
    float wz = w*z;

    return mat4
        ( 1- 2*yy - 2*zz, 2*xy + 2*wz    , 2*xz - 2*wy    , 0.0f
        , 2*xy - 2*wz,    1 - 2*xx - 2*zz, 2*yz + 2*wx    , 0.0f
        , 2*xz + 2*wy,    2*yz - 2*wx    , 1 - 2*xx - 2*yy, 0.0f
        , 0.0f       ,    0.0f           , 0.0f           , 1.0f);
}


float OGDT::sign (float x)
{
    if (x >= 0.0f) return 1.0f;
    else return -1.0f;
}


float OGDT::pitch_from_fwd (vec3 forward)
{
    vec3 f = vec3 (0.0f, forward.y, forward.z);
    f.normalise();
    return acos (dot(f, forward3)) * TO_DEG;
}


float OGDT::yaw_from_fwd (vec3 forward)
{
    vec3 f = vec3 (forward.x, 0.0, forward.z);
    f.normalise();
    return acos(dot(f, forward3)) * TO_DEG;
}
