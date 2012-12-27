#pragma once

#include <OGDT/OGDT.h>
#include <OGDT/math/vec3.h>

namespace OGDT
{

/*
Struct: AABB3
A 3D axis-aligned bounding box.
*/
struct DECLDIR AABB3
{
    vec3 min, max;
    
	/*
	Constructor: AABB3
	Construct an AABB3 with both vertices set to 0.
	*/
    AABB3 () {}
    
	/*
	Constructor: AABB3
	Construct an AABB3 from the given corner points.

	Parameters:

	_min - Bottom left corner.
	_max - Top right corner.
	*/
    AABB3 (vec3 _min, vec3 _max) : min (_min), max (_max) {}
    
	/*
	Constructor: AABB3
	Construct an AABB3 from the given points.

	Parameters:

	ps - An array of points.
	n  - The number of points in the array.
	*/
    AABB3 (vec3* ps, unsigned n);
    
	/*
	Function: add
	Update the AABB3 so that it includes the given point.

	The AABB3 is resized to contain the given point if it does not already contain it.
	*/
    void add (vec3 p);
};

} // namespace OGDT
