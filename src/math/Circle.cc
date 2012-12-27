#include <OGDT/math/Circle.h>
#include <algorithm>


using namespace OGDT;


Circle::Circle (vec2 _center, float _radius)
    : center (_center), radius2 (_radius*_radius) {}


void Circle::add (vec2 p)
{
    radius2 = std::max (radius2, norm2(p));
}


float Circle::radius () const
{
	return std::sqrt (radius2);
}
