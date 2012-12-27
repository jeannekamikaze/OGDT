#include <OGDT/math/AABB2.h>
#include <algorithm>


using namespace OGDT;


AABB2::AABB2 (vec2* ps, unsigned n)
{
    vec2* p = ps;
    for (unsigned i = 0; i < n; ++i, ++p)
    {
        min.x = std::min (min.x, p->x);
        min.y = std::min (min.y, p->y);
        
        max.x = std::max (max.x, p->x);
        max.y = std::max (max.y, p->y);
    }
}


void AABB2::add (vec2 p)
{
    min.x = std::min (min.x, p.x);
    min.y = std::min (min.y, p.y);
    
    max.x = std::max (max.x, p.x);
    max.y = std::max (max.y, p.y);
}
