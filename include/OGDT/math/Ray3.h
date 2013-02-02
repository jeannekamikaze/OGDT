#pragma once

#include <OGDT/math/vec3.h>

namespace OGDT
{

/*
Struct: Ray3
A ray in 3D space.
*/
struct Ray3
{
    vec3 pos;
    vec3 dir;
    
    /*
    Constructor: Ray
    Default constructor.
    */
    Ray3 () {}
    
    /*
    Constructor: Ray
    Construct a ray.
    
    Parameters:
    
    _pos - The ray's position.
    _dir - The ray's direction.
    */
    Ray3 (const vec3& _pos, const vec3& _dir)
#ifdef OGDT_AVOID_NORMALISATION
        : pos (_pos), dir (_dir) {}
#else
        : pos (_pos), dir (normalise(_dir)) {}
#endif
    
    /*
    Operator: ()
    Evaluate the ray equation.
    
    This function is defined as:
    
    ray(t) = ray.pos + ray.dir * t
    
    Parameters:
    
    t - The distance from the ray's position.
    */
    vec3 operator () (float t) const { return pos + dir * t; }
};

} // namespace OGDT
