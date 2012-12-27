#include <OGDT/math/mat4.h>
#include <OGDT/math/vec3.h>
#include <OGDT/math/vec4.h>
#include <OGDT/math/utils.h>


using namespace OGDT;


mat4::mat4 ()
{
	val[0][0] = 1.0f; val[0][1] = 0.0f; val[0][2] = 0.0f; val[0][3] = 0.0f;
    val[1][0] = 0.0f; val[1][1] = 1.0f; val[1][2] = 0.0f; val[1][3] = 0.0f;
    val[2][0] = 0.0f; val[2][1] = 0.0f; val[2][2] = 1.0f; val[2][3] = 0.0f,
    val[3][0] = 0.0f; val[3][1] = 0.0f; val[3][2] = 0.0f; val[3][3] = 1.0f;
}


mat4::mat4 (float m00, float m10, float m20, float m30
           ,float m01, float m11, float m21, float m31
           ,float m02, float m12, float m22, float m32
           ,float m03, float m13, float m23, float m33)
{
    val[0][0] = m00; val[0][1] = m01; val[0][2] = m02; val[0][3] = m03;
    val[1][0] = m10; val[1][1] = m11; val[1][2] = m12; val[1][3] = m13;
    val[2][0] = m20; val[2][1] = m21; val[2][2] = m22; val[2][3] = m23,
    val[3][0] = m30; val[3][1] = m31; val[3][2] = m32; val[3][3] = m33;
}


mat4::mat4 (const vec4& v0
           ,const vec4& v1
           ,const vec4& v2
           ,const vec4& v3)
{
    val[0][0] = v0.x; val[0][1] = v0.y; val[0][2] = v0.z; val[0][3] = v0.w;
    val[1][0] = v1.x; val[1][1] = v1.y; val[1][2] = v1.z; val[1][3] = v1.w;
    val[2][0] = v2.x; val[2][1] = v2.y; val[2][2] = v2.z; val[2][3] = v2.w,
    val[3][0] = v3.x; val[3][1] = v3.y; val[3][2] = v3.z; val[3][3] = v3.w;
}


mat4::mat4 (const vec3& v0, const vec3& v1, const vec3& v2, const vec3& v3)
{
    val[0][0] = v0.x; val[0][1] = v0.y; val[0][2] = v0.z; val[0][3] = 0.0f;
    val[1][0] = v1.x; val[1][1] = v1.y; val[1][2] = v1.z; val[1][3] = 0.0f;
    val[2][0] = v2.x; val[2][1] = v2.y; val[2][2] = v2.z; val[2][3] = 0.0f;
    val[3][0] = v3.x; val[3][1] = v3.y; val[3][2] = v3.z; val[3][3] = 1.0f;
}


float& mat4::operator() (int row, int col)
{
    return val[col][row];
}


float mat4::operator() (int row, int col) const
{
    return val[col][row];
}


vec3& mat4::v0 ()
{
	return *((vec3*)val[0]);
}


vec3& mat4::v1 ()
{
	return *((vec3*)val[1]);
}


vec3& mat4::v2 ()
{
	return *((vec3*)val[2]);
}


vec3& mat4::v3 ()
{
	return *((vec3*)val[3]);
}


const vec3& mat4::v0 () const
{
    return *((vec3*)val[0]);
}


const vec3& mat4::v1 () const
{
    return *((vec3*)val[1]);
}


const vec3& mat4::v2 () const
{
    return *((vec3*)val[2]);
}


const vec3& mat4::v3 () const
{
    return *((vec3*)val[3]);
}


mat4 mat4::operator* (const mat4& m)
{
    const mat4& a = *this;

	float m00 = a(0,0) * m(0,0) + a(0,1) * m(1,0) + a(0,2) * m(2,0) + a(0,3) * m(3,0);
	float m01 = a(0,0) * m(0,1) + a(0,1) * m(1,1) + a(0,2) * m(2,1) + a(0,3) * m(3,1);
	float m02 = a(0,0) * m(0,2) + a(0,1) * m(1,2) + a(0,2) * m(2,2) + a(0,3) * m(3,2);
	float m03 = a(0,0) * m(0,3) + a(0,1) * m(1,3) + a(0,2) * m(2,3) + a(0,3) * m(3,3);

    float m10 = a(1,0) * m(0,0) + a(1,1) * m(1,0) + a(1,2) * m(2,0) + a(1,3) * m(3,0);
	float m11 = a(1,0) * m(0,1) + a(1,1) * m(1,1) + a(1,2) * m(2,1) + a(1,3) * m(3,1);
	float m12 = a(1,0) * m(0,2) + a(1,1) * m(1,2) + a(1,2) * m(2,2) + a(1,3) * m(3,2);
	float m13 = a(1,0) * m(0,3) + a(1,1) * m(1,3) + a(1,2) * m(2,3) + a(1,3) * m(3,3);

	float m20 = a(2,0) * m(0,0) + a(2,1) * m(1,0) + a(2,2) * m(2,0) + a(2,3) * m(3,0);
	float m21 = a(2,0) * m(0,1) + a(2,1) * m(1,1) + a(2,2) * m(2,1) + a(2,3) * m(3,1);
	float m22 = a(2,0) * m(0,2) + a(2,1) * m(1,2) + a(2,2) * m(2,2) + a(2,3) * m(3,2);
	float m23 = a(2,0) * m(0,3) + a(2,1) * m(1,3) + a(2,2) * m(2,3) + a(2,3) * m(3,3);

	float m30 = a(3,0) * m(0,0) + a(3,1) * m(1,0) + a(3,2) * m(2,0) + a(3,3) * m(3,0);
	float m31 = a(3,0) * m(0,1) + a(3,1) * m(1,1) + a(3,2) * m(2,1) + a(3,3) * m(3,1);
	float m32 = a(3,0) * m(0,2) + a(3,1) * m(1,2) + a(3,2) * m(2,2) + a(3,3) * m(3,2);
	float m33 = a(3,0) * m(0,3) + a(3,1) * m(1,3) + a(3,2) * m(2,3) + a(3,3) * m(3,3);

	return mat4
		(m00, m01, m02, m03
		,m10, m11, m12, m13
		,m20, m21, m22, m23
		,m30, m31, m32, m33);
}


void mat4::operator*= (const mat4& m)
{
	const mat4& a = *this;

	float m00 = a(0,0) * m(0,0) + a(0,1) * m(1,0) + a(0,2) * m(2,0) + a(0,3) * m(3,0);
	float m01 = a(0,0) * m(0,1) + a(0,1) * m(1,1) + a(0,2) * m(2,1) + a(0,3) * m(3,1);
	float m02 = a(0,0) * m(0,2) + a(0,1) * m(1,2) + a(0,2) * m(2,2) + a(0,3) * m(3,2);
	float m03 = a(0,0) * m(0,3) + a(0,1) * m(1,3) + a(0,2) * m(2,3) + a(0,3) * m(3,3);

    float m10 = a(1,0) * m(0,0) + a(1,1) * m(1,0) + a(1,2) * m(2,0) + a(1,3) * m(3,0);
	float m11 = a(1,0) * m(0,1) + a(1,1) * m(1,1) + a(1,2) * m(2,1) + a(1,3) * m(3,1);
	float m12 = a(1,0) * m(0,2) + a(1,1) * m(1,2) + a(1,2) * m(2,2) + a(1,3) * m(3,2);
	float m13 = a(1,0) * m(0,3) + a(1,1) * m(1,3) + a(1,2) * m(2,3) + a(1,3) * m(3,3);

	float m20 = a(2,0) * m(0,0) + a(2,1) * m(1,0) + a(2,2) * m(2,0) + a(2,3) * m(3,0);
	float m21 = a(2,0) * m(0,1) + a(2,1) * m(1,1) + a(2,2) * m(2,1) + a(2,3) * m(3,1);
	float m22 = a(2,0) * m(0,2) + a(2,1) * m(1,2) + a(2,2) * m(2,2) + a(2,3) * m(3,2);
	float m23 = a(2,0) * m(0,3) + a(2,1) * m(1,3) + a(2,2) * m(2,3) + a(2,3) * m(3,3);

	float m30 = a(3,0) * m(0,0) + a(3,1) * m(1,0) + a(3,2) * m(2,0) + a(3,3) * m(3,0);
	float m31 = a(3,0) * m(0,1) + a(3,1) * m(1,1) + a(3,2) * m(2,1) + a(3,3) * m(3,1);
	float m32 = a(3,0) * m(0,2) + a(3,1) * m(1,2) + a(3,2) * m(2,2) + a(3,3) * m(3,2);
	float m33 = a(3,0) * m(0,3) + a(3,1) * m(1,3) + a(3,2) * m(2,3) + a(3,3) * m(3,3);

	*this = mat4
		(m00, m01, m02, m03
		,m10, m11, m12, m13
		,m20, m21, m22, m23
		,m30, m31, m32, m33);
}


mat4 mat4::transl () const
{
	const mat4& m = *this;
	return mat4
		(1.0f, 0.0f, 0.0f, m(0,3)
		,0.0f, 1.0f, 0.0f, m(1,3)
		,0.0f, 0.0f, 1.0f, m(2,3)
		,0.0f, 0.0f, 0.0f, 1.0f);
}


mat4 mat4::rot () const
{
	const mat4& m = *this;
	return mat4
		(m(0,0), m(0,1), m(0,2), 0.0f
		,m(1,0), m(1,1), m(1,2), 0.0f
		,m(2,0), m(2,1), m(2,2), 0.0f
		,0.0f  , 0.0f  , 0.0f  , 1.0f
		);
}


mat4 mat4::rotx (float angle)
{
    float a = angle * TO_RAD;
    float s = sin (a);
    float c = cos (a);
    
    return mat4
        (1, 0,  0, 0
        ,0, c, -s, 0
        ,0, s,  c, 0
        ,0, 0,  0, 1);
}


mat4 mat4::roty (float angle)
{
    float a = angle * TO_RAD;
    float s = sin (a);
    float c = cos (a);
    
    return mat4
        ( c, 0, s, 0
        , 0, 1, 0, 0
        ,-s, 0, c, 0
        , 0, 0, 0, 1);
}


mat4 mat4::rotz (float angle)
{
    float a = angle * TO_RAD;
    float s = sin (a);
    float c = cos (a);
    
    return mat4
        (c, -s, 0, 0
        ,s,  c, 0, 0
        ,0,  0, 1, 0
        ,0,  0, 0, 1);
}


mat4 mat4::rot (float angle, const vec3& axis)
{
    return rot (angle, axis.x, axis.y, axis.z);
}


mat4 mat4::rot (float angle, float x, float y, float z)
{
    float a = angle * TO_RAD;
    float s = sin (a);
    float c = cos (a);
    
    float xy  = x*y;
    float xz  = x*z;
    float yz  = y*z;
    float sx  = s*x;
    float sy  = s*y;
    float sz  = s*z;
    float omc = 1.0f - c;
    
    return mat4
        (c + omc*x*x, omc*xy-sz, omc*xz+sy, 0
        ,omc*xy+sz,   c+omc*y*y, omc*yz-sx, 0
        ,omc*xz-sy,   omc*yz+sx, c+omc*z*z, 0
        ,0,           0,         0,         1);
}


mat4 mat4::scale (const vec3& s)
{
    return mat4
        (s.x,   0,   0,   0
        ,  0, s.y,   0,   0
        ,  0,   0, s.z,   0
        ,  0,   0,   0,   1);
}


mat4 mat4::scale (float x, float y, float z)
{
    return mat4
        (x, 0, 0, 0
        ,0, y, 0, 0
        ,0, 0, z, 0
        ,0, 0, 0, 1);
}


mat4 mat4::transl (const vec3& p)
{
    return mat4
        (1, 0, 0, p.x
        ,0, 1, 0, p.y
        ,0, 0, 1, p.z
        ,0, 0, 0, 1);
}


mat4 mat4::transl (float x, float y, float z)
{
    return mat4
        (1, 0, 0, x
        ,0, 1, 0, y
        ,0, 0, 1, z
        ,0, 0, 0, 1);
}


const mat4 mat4::reflectx = mat4
	(-1, 0, 0, 0
	, 0, 1, 0, 0
	, 0, 0, 1, 0
	, 0, 0, 0, 1);


const mat4 mat4::reflecty = mat4
	(1,  0,  0,  0
	,0, -1,  0,  0
	,0,  0,  1,  0
	,0,  0,  0,  1);


const mat4 mat4::reflectz = mat4
	(1,  0,  0,  0
	,0,  1,  0,  0
	,0,  0, -1,  0
	,0,  0,  0,  1);


const mat4 mat4::id = mat4
	( 1.0f, 0.0f, 0.0f, 0.0f
	, 0.0f, 1.0f, 0.0f, 0.0f
	, 0.0f, 0.0f, 1.0f, 0.0f
	, 0.0f, 0.0f, 0.0f, 1.0f
	);


mat4 mat4::transform (vec3 f)
{
	f.normalise();
	vec3 r = cross (f, up3);
	vec3 u = cross (r, f);
	r.normalise();
	u.normalise();
	return mat4
		(r.x , u.x , -f.x , 0.0f
		,r.y , u.y , -f.y , 0.0f
		,r.z , u.z , -f.z , 0.0f
		,0.0f, 0.0f, 0.0f, 1.0f
		);
}


mat4 mat4::lookAt (const vec3& position, const vec3& target)
{
    vec3 fwd   = normalise (target - position);
    vec3 right = cross (fwd, vec3(0,1,0));
    vec3 up    = cross (right, fwd);
    return mat4 (right, up, fwd, position);
}


mat4 mat4::ortho (float l, float r, float b, float t, float n, float f)
{
    float tx = -(r+l) / (r-l);
    float ty = -(t+b) / (t-b);
    float tz = -(f+n) / (f-n);
    
    return mat4
        (2/(r-l), 0,        0,       tx
        ,0,       2/(t-b),  0,       ty
        ,0,       0,       -2/(f-n), tz
        ,0,       0,        0,       1);
}


mat4 mat4::perspective (float fovy, float r, float near, float far)
{
    float f = tan (fovy * TO_RAD / 2.0f);
    f = f == 0.0f ? 1.0f : 1.0f / f;
    float a = near - far;
    
    return mat4
        (f/r, 0,  0,            0
        ,0,   f,  0,            0
        ,0,   0, (far+near)/a, (2*far*near/a)
        ,0,   0, -1,            0);
}


mat4 OGDT::inverse (const mat4& m)
{
	float a00 = m[0];
	float a01 = m[10];
	float a02 = m[20];
	float a03 = m[30];
	float a04 = m[1];
	float a05 = m[11];
	float a06 = m[21];
	float a07 = m[31];
	float a08 = m[2];
	float a09 = m[12];
	float a10 = m[22];
	float a11 = m[32];
	float a12 = m[3];
	float a13 = m[13];
	float a14 = m[23];
	float a15 = m[33];

	float m00 = a05 * a10  * a15
              - a05 * a11  * a14
              - a09 * a06  * a15
              + a09 * a07  * a14
              + a13 * a06  * a11
              - a13 * a07  * a10;
        
	float m04 = -a04 * a10 * a15
              +  a04 * a11 * a14
              +  a08 * a06 * a15
              -  a08 * a07 * a14
              -  a12 * a06 * a11
              +  a12 * a07 * a10;

	float m08 = a04 * a09 * a15
              - a04 * a11 * a13
              - a08 * a05 * a15
              + a08 * a07 * a13
              + a12 * a05 * a11
              - a12 * a07 * a09;

	float m12 = -a04 * a09 * a14
              +  a04 * a10 * a13
              +  a08 * a05 * a14
              -  a08 * a06 * a13
              -  a12 * a05 * a10
              +  a12 * a06 * a09;

	float m01 = -a01 * a10 * a15
              +  a01 * a11 * a14
              +  a09 * a02 * a15
              -  a09 * a03 * a14
              -  a13 * a02 * a11
              +  a13 * a03 * a10;

	float m05 = a00 * a10 * a15
              - a00 * a11 * a14
              - a08 * a02 * a15
              + a08 * a03 * a14
              + a12 * a02 * a11
              - a12 * a03 * a10;
        
	float m09 = -a00 * a09 * a15
              +  a00 * a11 * a13
              +  a08 * a01 * a15
              -  a08 * a03 * a13
              -  a12 * a01 * a11
              +  a12 * a03 * a09;

	float m13 = a00 * a09 * a14
              - a00 * a10 * a13
              - a08 * a01 * a14
              + a08 * a02 * a13
              + a12 * a01 * a10
              - a12 * a02 * a09;

	float m02 = a01 * a06 * a15
              - a01 * a07 * a14
              - a05 * a02 * a15
              + a05 * a03 * a14
              + a13 * a02 * a07
              - a13 * a03 * a06;

	float m06 = -a00 * a06 * a15
              +  a00 * a07 * a14
              +  a04 * a02 * a15
              -  a04 * a03 * a14
              -  a12 * a02 * a07
              +  a12 * a03 * a06;

	float m10 = a00 * a05 * a15
              - a00 * a07 * a13
              - a04 * a01 * a15
              + a04 * a03 * a13
              + a12 * a01 * a07
              - a12 * a03 * a05;

	float m14 = -a00 * a05 * a14
              +  a00 * a06 * a13
              +  a04 * a01 * a14
              -  a04 * a02 * a13
              -  a12 * a01 * a06
              +  a12 * a02 * a05;

	float m03 = -a01 * a06 * a11
              +  a01 * a07 * a10
              +  a05 * a02 * a11
              -  a05 * a03 * a10
              -  a09 * a02 * a07
              +  a09 * a03 * a06;

	float m07 = a00 * a06 * a11
              - a00 * a07 * a10
              - a04 * a02 * a11
              + a04 * a03 * a10
              + a08 * a02 * a07
              - a08 * a03 * a06;

	float m11 = -a00 * a05 * a11
              +  a00 * a07 * a09
              +  a04 * a01 * a11
              -  a04 * a03 * a09
              -  a08 * a01 * a07
              +  a08 * a03 * a05;

	float m15 = a00 * a05 * a10
              - a00 * a06 * a09
              - a04 * a01 * a10
              + a04 * a02 * a09
              + a08 * a01 * a06
              - a08 * a02 * a05;
        
	float det = a00 * m00 + a01 * m04 + a02 * m08 + a03 * m12;
    if (det == 0)
	{
		return mat4::id;
	}
	else
	{
		det = 1.0f / det;
		return mat4
			(m00 * det, m04 * det, m08 * det, m12 * det
			,m01 * det, m05 * det, m09 * det, m13 * det
			,m02 * det, m06 * det, m10 * det, m14 * det
			,m03 * det, m07 * det, m11 * det, m15 * det
			);
	}
}


mat4 OGDT::inverse_transform (const mat4& m)
{
	vec3 r = m.v0 ();
	vec3 u = m.v1 ();
	vec3 f = m.v2 ();
	vec3 t = m.v3 ();
	
	return mat4
		( r.x , r.y , r.z , -dot(r,t)
		, u.x , u.y , u.z , -dot(u,t)
		, f.x , f.y , f.z , -dot(f,t)
		, 0.0f, 0.0f, 0.0f, 1.0f
		);
}


mat4 OGDT::transpose (const mat4& m)
{
	return mat4
		(m(0,0), m(1,0), m(2,0), m(3,0)
		,m(0,1), m(1,1), m(2,1), m(3,1)
		,m(0,2), m(1,2), m(2,2), m(3,2)
		,m(0,3), m(1,3), m(2,3), m(3,3));
}


vec3 OGDT::transform (const mat4& m, vec3 v, float w)
{
	vec3 u;
	u.x = m(0,0) * v.x + m(0,1) * v.y + m(0,2) * v.z + w;
	u.y = m(1,0) * v.x + m(1,1) * v.y + m(1,2) * v.z + w;
	u.z = m(2,0) * v.x + m(2,1) * v.y + m(2,2) * v.z + w;
	return u;
}
