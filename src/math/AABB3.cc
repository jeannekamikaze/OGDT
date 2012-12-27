#include <OGDT/math/AABB3.h>
#include <algorithm>


using namespace OGDT;


AABB3::AABB3 (vec3* ps, unsigned n)
{
    vec3* p = ps;
    for (unsigned i = 0; i < n; ++i, ++p)
    {
        min.x = std::min (min.x, p->x);
        min.y = std::min (min.y, p->y);
        min.z = std::min (min.z, p->z);
        
        max.x = std::max (max.x, p->x);
        max.y = std::max (max.y, p->y);
        max.z = std::max (max.z, p->z);
    }
}


void AABB3::add (vec3 p)
{
    min.x = std::min (min.x, p.x);
    min.y = std::min (min.y, p.y);
    min.z = std::min (min.z, p.z);
    
    max.x = std::max (max.x, p.x);
    max.y = std::max (max.y, p.y);
    max.z = std::max (max.z, p.z);
}
