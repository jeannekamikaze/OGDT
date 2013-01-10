#pragma once

#include <OGDT/OGDT.h>
#include <OGDT/math/vec2.h>

namespace OGDT
{

/*
Struct: Circle
*/
struct DECLDIR Circle
{
    vec2  center;
    float radius2;
    
    /*
    Constructor: Circle
    Construct a circle of radius 0 centered at the origin.
    */
    Circle () : radius2 (0) {}
    
    /*
    Constructor: Circle
    Construct a circle with the given center and radius.
    */
    Circle (vec2 center, float radius);
    
    /*
    Function: add
    Update the circle so that it includes the given point.

    The circle is resized to contain the given point if it does not already contain it.
    */
    void add (vec2 p);
    
    /*
    Function: radius
    Return the circle's radius.
    */
    float radius () const;
};

} // namespace OGDT
