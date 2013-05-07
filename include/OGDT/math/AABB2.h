#pragma once

#include <OGDT/math/vec2.h>

namespace OGDT
{

/*
Struct: AABB2
A 2D axis-aligned bounding box.
*/
struct AABB2
{
    vec2 min, max;

    /*
    Constructor: AABB2
    Construct an AABB2 with both vertices set to 0.
    */
    AABB2 () {}

    /*
    Constructor: AABB2
    Construct an AABB2 from the given corner points.

    Parameters:

    _min - Bottom left corner.
    _max - Top right corner.
    */
    AABB2 (vec2 _min, vec2 _max) : min (_min), max (_max) {}

    /*
    Constructor: AABB2
    Construct an AABB2 from the given points.

    Parameters:

    ps - An array of points.
    n  - The number of points in the array.
    */
    AABB2 (vec2* ps, unsigned n);

    /*
    Function: add
    Update the AABB2 so that it includes the given point.

    The AABB2 is resized to contain the given point if it does not already contain it.
    */
    void add (vec2 p);
};

} // namespace OGDT
