#include <OGDT/math/Sphere.h>
#include <algorithm>


using namespace OGDT;


Sphere::Sphere (vec3 c, float r)
    : center (c), radius2 (r*r) {}


void Sphere::add (vec3 p)
{
    radius2 = std::max (radius2, norm2(p));
}


float Sphere::radius () const
{
    return std::sqrt (radius2);
}
