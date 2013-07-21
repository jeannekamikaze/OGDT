#pragma once

namespace OGDT
{

/*
Header: collision
*/

struct AABB3;
struct plane;
struct ray3;
struct sphere;
struct vec3;

/*
Function: collide
Collide a ray and a plane.
*/
bool collide (const ray3&, const plane&);

/*
Function: collide
Collide a plane and a ray.
*/
inline bool collide (const plane& plane, const ray3& ray)
{
    return collide (ray, plane);
}

/*
Function: collide
Collide a ray and an AABB3.
*/
bool collide (const ray3&, const AABB3&);

/*
Function: collide
Collide an AABB3 and a ray.
*/
inline bool collide (const AABB3& box, const ray3& ray)
{
    return collide (ray, box);
}

/*
Function: collide
Collide a ray and a sphere.
*/
bool collide (const ray3&, const sphere&);

/*
Function: collide
Collide a sphere and a ray.
*/
inline bool collide (const sphere& sphere, const ray3& ray)
{
    return collide (ray, sphere);
}

} // namespace OGDT
