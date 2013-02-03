#include <OGDT/math/collision.h>
#include <OGDT/math/AABB3.h>
#include <OGDT/math/Plane.h>
#include <OGDT/math/Ray3.h>
#include <OGDT/math/Sphere.h>
#include <OGDT/math/vec3.h>
#include <float.h>

#ifdef _MSC_VER
#include <algorithm>
#define fmax std::max
#define fmin std::min
#else
#include <cmath>
#endif

using namespace OGDT;


bool OGDT::collide (const Ray3& r, const Plane& p)
{
    float denom = dot (p.normal, r.dir);
    if (denom == 0.0f) return false;
    float t = (dot(-p.normal, r.pos) - p.d) / denom;
    return t >= 0.0f;
}


bool OGDT::collide (const Ray3& r, const AABB3& a)
{
    float tmin = FLT_MIN;
    float tmax = FLT_MAX;
    if (r.dir.x != 0.0f)
    {
        tmin = fmax (tmin, (a.min.x - r.pos.x) / r.dir.x);
        tmax = fmin (tmax, (a.max.x - r.pos.x) / r.dir.x);
    }
    if (r.dir.y != 0.0f)
    {
        tmin = fmax (tmin, (a.min.y - r.pos.y) / r.dir.y);
        tmax = fmin (tmax, (a.max.y - r.pos.y) / r.dir.y);
    }
    if (r.dir.z != 0.0f)
    {
        tmin = fmax (tmin, (a.min.z - r.pos.z) / r.dir.z);
        tmax = fmin (tmax, (a.max.z - r.pos.z) / r.dir.z);
    }
    return tmin <= tmax;
}


bool OGDT::collide (const Ray3& r, const Sphere& s)
{
    vec3 l = s.center - r.pos;
    float l2 = norm2 (l);
    float r2 = s.radius2;
    if (l2 < r2) return true;
    float p = dot (l, r.dir);
    if (p < 0.0f) return false;
    float a2 = l2 - p*p;
    return a2 < r2;
}
