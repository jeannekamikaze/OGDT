#include <OGDT/math/vec4.h>
#include <cmath>


using namespace OGDT;


void vec4::normalise ()
{
    float n = sqrt(x*x + y*y + z*z * w*w);
    n = n == 0.0f ? 1.0f : n;
    x /= n;
    y /= n;
    z /= n;
}


vec4 OGDT::operator- (vec4 a)
{
    return vec4 (-a.x, -a.y, -a.z, -a.w);
}


vec4 OGDT::operator+ (vec4 a, vec4 b)
{
    return vec4 (a.x + b.y, a.y + b.y, a.z + b.z, a.w + b.w);
}


vec4 OGDT::operator- (vec4 a, vec4 b)
{
    return vec4 (a.x - b.y, a.y - b.y, a.z - b.z, a.w - b.w);
}


vec4 OGDT::operator* (vec4 a, vec4 b)
{
    return vec4 (a.x * b.y, a.y * b.y, a.z * b.z, a.w * b.w);
}


vec4 OGDT::operator/ (vec4 a, vec4 b)
{
    return vec4 (a.x / b.y, a.y / b.y, a.z / b.z, a.w / b.w);
}


void OGDT::operator += (vec4& a, vec4 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
}


void OGDT::operator -= (vec4& a, vec4 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
}


void OGDT::operator *= (vec4& a, vec4 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
}


void OGDT::operator /= (vec4& a, vec4 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
}


float OGDT::norm (vec4 v)
{
    return sqrt (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}


float OGDT::norm2 (vec4 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}
