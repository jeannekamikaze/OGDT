#include <OGDT/math/vec2.h>
#include <cmath>


using namespace OGDT;


void vec2::normalise ()
{
    float n = sqrt(x*x + y*y);
    n = n == 0.0f ? 1.0f : n;
    x /= n;
    y /= n;
}


vec2 OGDT::operator- (vec2 a)
{
	return vec2 (-a.x, -a.y);
}


vec2 OGDT::operator+ (vec2 a, vec2 b)
{
    return vec2 (a.x + b.x, a.y + b.y);
}


vec2 OGDT::operator- (vec2 a, vec2 b)
{
    return vec2 (a.x - b.x, a.y - b.y);
}


vec2 OGDT::operator* (vec2 a, vec2 b)
{
    return vec2 (a.x * b.x, a.y * b.y);
}


vec2 OGDT::operator/ (vec2 a, vec2 b)
{
    return vec2 (a.x / b.x, a.y / b.y);
}


void OGDT::operator += (vec2& a, vec2 b)
{
    a.x += b.x;
    a.y += b.y;
}


void OGDT::operator -= (vec2& a, vec2 b)
{
    a.x -= b.x;
    a.y -= b.y;
}


void OGDT::operator *= (vec2& a, vec2 b)
{
    a.x *= b.x;
    a.y *= b.y;
}


void OGDT::operator /= (vec2& a, vec2 b)
{
    a.x /= b.x;
    a.y /= b.y;
}


float OGDT::norm (vec2 v)
{
    return sqrt (v.x * v.x + v.y * v.y);
}


float OGDT::norm2 (vec2 v)
{
    return v.x * v.x + v.y * v.y;
}


vec2 OGDT::normalise (vec2 v)
{
    float n = sqrt(v.x*v.x + v.y*v.y);
    n = n == 0.0f ? 1.0f : n;
    return vec2 (v.x / n, v.y / n);
}
