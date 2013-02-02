#pragma once

#include <OGDT/math/vec3.h>

namespace OGDT
{

/*
Struct: Plane
A plane in 3D space.
*/
struct Plane
{
    vec3 normal;
    float d;
    
    /*
    Constructor: Plane
    Construct a new plane.
    
    Parameters:
    
    _normal : The plane's normal.
    _d : The perpendicular distance from the plane to the origin.
    */
    Plane (const vec3& _normal, float _d)
#ifdef OGDT_AVOID_NORMALISATION
        : normal (_normal), d (_d) {}
#else
        : normal (normalise(_normal)), d (_d) {}
#endif
};

} // namespace OGDT
