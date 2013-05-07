#pragma once

#include <OGDT/math/vec3.h>

namespace OGDT
{

/*
Struct: Sphere
*/
struct Sphere
{
    vec3  center;
    float radius2;

    /*
    Constructor: Sphere
    Construct a sphere of radius 0 centered at the origin.
    */
    Sphere () : radius2 (0) {}

    /*
    Constructor: Sphere
    Construct a sphere with the given center and radius.
    */
    Sphere (vec3 center, float radius);

    /*
    Function: add
    Update the sphere so that it includes the given point.

    The sphere is resized to contain the given point if it does not already contain it.
    */
    void add (vec3 p);

    /*
    Function: radius
    Return the sphere's radius.
    */
    float radius () const;
};

} // namespace OGDT
