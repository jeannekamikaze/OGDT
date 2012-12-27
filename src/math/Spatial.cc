#include <OGDT/math/Spatial.h>
#include <OGDT/math/utils.h>
#include <cmath>


using namespace OGDT;


Spatial::Spatial ()
	: r (right3), u (up3), f (forward3)
{
}


Spatial::Spatial (const vec3& pos, const vec3& target)
{
	setPosition (pos);
	lookAt (target);
}


void Spatial::move (const vec3& direction)
{
	p += direction;
}


void Spatial::moveForwards (float speed)
{
	move (fwd() * speed);
}


void Spatial::moveBackwards (float speed)
{
	move (fwd() * -speed);
}


void Spatial::strafeLeft (float speed)
{
     move (right() * -speed);
}


void Spatial::strafeRight (float speed)
{
     move (right() * speed);
}


void Spatial::moveUp (float speed)
{
     move (up() * speed);
}


void Spatial::moveDown (float speed)
{
     move (up() * -speed);
}


void Spatial::rotate (float angle, float x, float y, float z)
{
	mat4 transf = transform();
	vec3 axis = ::transform (inverse_transform(transf), vec3 (x,y,z), 0.0f);
    transf *= mat4::rot (angle, axis);
	r = transf.v0();
	u = transf.v1();
	f = -transf.v2();
}


void Spatial::yaw (const float angle)
{
	float a = angle * TO_RAD;
	float sa = sin (a);
	float ca = cos (a);
	r = r * ca + f * sa;
	r.normalise();
	f = cross (r, u);
}


void Spatial::pitch (const float angle)
{
	float a = angle * TO_RAD;
	float sa = sin (a);
	float ca = cos (a);
	f = f * ca + u * sa;
	f.normalise();
	u = cross (r, f);
}


void Spatial::roll (const float angle)
{
	float a = angle * TO_RAD;
	float sa = sin (a);
	float ca = cos (a);
	u = u * ca - r * sa;
	u.normalise();
	r = cross (f, u);
}


void Spatial::setPosition (float x, float y, float z)
{
    p.x = x; p.y = y; p.z = z;
}


void Spatial::setPosition (const vec3& v)
{
    p = v;
}


void Spatial::setForward (float x, float y, float z)
{
	setForward (vec3(x,y,z));
}


void Spatial::setForward (vec3 forward)
{
	forward.normalise();
	f = forward;
	r = cross (f, up3);
	u = cross (r, f);
	r.normalise();
	u.normalise();
}


void Spatial::setTransform (const mat4& transform)
{
	r = transform.v0();
	u = transform.v1();
	f = -transform.v2();
	p = transform.v3();
}


void Spatial::lookAt (float x, float y, float z)
{
	setForward (vec3(x,y,z) - p);
}


void Spatial::lookAt (const vec3& target)
{
    setForward (target - p);
}


void Spatial::lookAt (const Spatial& target)
{
	setForward (target.pos() - p);
}


void Spatial::orbit (float x, float y, float z, float radius, float azimuth, float zenith)
{
	float ax = azimuth * TO_RAD;
	float ay = zenith * TO_RAD;
	float sx = sin(ax);
	float sy = sin(ay);
	float cx = cos(ax);
	float cy = cos(ay);
	setPosition (x + radius*cy*sx, y + radius*sy, z + radius*cx*cy);
}


void Spatial::orbit (const vec3& target, float radius, float azimuth, float zenith)
{
	orbit (target.x, target.y, target.z, radius, azimuth, zenith);
}


void Spatial::orbit (const Spatial& target, float radius, float azimuth, float zenith)
{
	const vec3& p = target.pos();
	orbit (p.x, p.y, p.z, radius, azimuth, zenith);
}


const vec3& Spatial::pos () const
{
	return p;
}


const vec3& Spatial::fwd () const
{
    return f;
}


const vec3& Spatial::right () const
{
    return r;
}


const vec3& Spatial::up () const
{
    return u;
}


mat4 Spatial::transform () const
{
	return mat4
		(r.x , u.x , -f.x , p.x
		,r.y , u.y , -f.y , p.y
		,r.z , u.z , -f.z , p.z
		,0.0f, 0.0f, 0.0f, 1.0f
		);
}


mat4 Spatial::inverseTransform () const
{
	return inverse_transform (transform());
}
