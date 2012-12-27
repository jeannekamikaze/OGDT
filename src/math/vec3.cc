#include <OGDT/math/vec3.h>
#include <cmath>


using namespace OGDT;


void vec3::normalise ()
{
    float n = sqrt(x*x + y*y + z*z);
    n = n == 0.0f ? 1.0f : n;
    x /= n;
    y /= n;
    z /= n;
}


vec3 OGDT::operator- (vec3 v)
{
	return vec3 (-v.x, -v.y, -v.z);
}


vec3 OGDT::operator+ (vec3 a, vec3 b)
{
    return vec3 (a.x + b.x, a.y + b.y, a.z + b.z);
}


vec3 OGDT::operator- (vec3 a, vec3 b)
{
    return vec3 (a.x - b.x, a.y - b.y, a.z - b.z);
}


vec3 OGDT::operator* (vec3 a, vec3 b)
{
    return vec3 (a.x * b.x, a.y * b.y, a.z * b.z);
}


vec3 OGDT::operator/ (vec3 a, vec3 b)
{
    return vec3 (a.x / b.x, a.y / b.y, a.z / b.z);
}


void OGDT::operator += (vec3& a, vec3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
}


void OGDT::operator -= (vec3& a, vec3 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
}


void OGDT::operator *= (vec3& a, vec3 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
}


void OGDT::operator /= (vec3& a, vec3 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
}


float OGDT::norm (vec3 v)
{
    return sqrt (v.x * v.x + v.y * v.y + v.z * v.z);
}


float OGDT::norm2 (vec3 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}


vec3 OGDT::normalise (vec3 v)
{
    float n = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    n = n == 0.0f ? 1.0f : n;
    return vec3 (v.x / n, v.y / n, v.z / n);
}


float OGDT::dot (vec3 a, vec3 b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}


vec3 OGDT::cross (vec3 a, vec3 b)
{
    return vec3
        (a.y*b.z - a.z*b.y
        ,a.z*b.x - a.x*b.z
        ,a.x*b.y - a.y*b.x);
}
