#pragma once

namespace OGDT
{

/*
File: Collision
*/

struct AABB3;
struct Plane;
struct Ray3;
struct Sphere;
struct vec3;

/*
Function: collide
Collide a ray and a plane.
*/
bool collide (const Ray3&, const Plane&);

/*
Function: collide
Collide a plane and a ray.
*/
inline bool collide (const Plane& plane, const Ray3& ray)
{
    return collide (ray, plane);
}

/*
Function: collide
Collide a ray and an AABB3.
*/
bool collide (const Ray3&, const AABB3&);

/*
Function: collide
Collide an AABB3 and a ray.
*/
inline bool collide (const AABB3& box, const Ray3& ray)
{
    return collide (ray, box);
}

/*
Function: collide
Collide a ray and a sphere.
*/
bool collide (const Ray3&, const Sphere&);

/*
Function: collide
Collide a sphere and a ray.
*/
inline bool collide (const Sphere& sphere, const Ray3& ray)
{
    return collide (ray, sphere);
}

} // namespace OGDT
