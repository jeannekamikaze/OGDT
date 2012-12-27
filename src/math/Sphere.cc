#include <OGDT/math/Sphere.h>
#include <algorithm>


using namespace OGDT;


Sphere::Sphere (vec3 _center, float _radius)
    : center (_center), radius2 (_radius*_radius) {}


void Sphere::add (vec3 p)
{
    radius2 = std::max (radius2, norm2(p));
}


float Sphere::radius () const
{
	return std::sqrt (radius2);
}
