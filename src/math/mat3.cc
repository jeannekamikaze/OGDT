#include <OGDT/math/mat3.h>
#include <OGDT/math/vec2.h>
#include <OGDT/math/vec3.h>
#include <OGDT/math/utils.h>


using namespace OGDT;


mat3::mat3 ()
{
}


mat3::mat3 (float m00, float m10, float m20
           ,float m01, float m11, float m21
           ,float m02, float m12, float m22)
{
    val[0][0] = m00; val[0][1] = m01; val[0][2] = m02;
    val[1][0] = m10; val[1][1] = m11; val[1][2] = m12;
    val[2][0] = m20; val[2][1] = m21; val[2][2] = m22;
}


mat3::mat3 (const vec3& v0
           ,const vec3& v1
           ,const vec3& v2)
{
    val[0][0] = v0.x; val[0][1] = v0.y; val[0][2] = v0.z;
    val[1][0] = v1.x; val[1][1] = v1.y; val[1][2] = v1.z;
    val[2][0] = v2.x; val[2][1] = v2.y; val[2][2] = v2.z;
}


mat3::mat3 (const vec2& right, const vec2& up, const vec2& pos)
{
    val[0][0] = right.x; val[0][1] = right.y; val[0][2] = 0;
    val[1][0] = up.x;    val[1][1] = up.y;    val[1][2] = 0;
    val[2][0] = pos.x;   val[2][1] = pos.y;   val[2][2] = 1;
}


mat3 mat3::rot (float angle)
{
    float a  = angle * (float) M_PI / 180.0f;
    float sa = sin (a);
    float ca = cos (a);
    
    return mat3
        (ca, -sa, 0
        ,sa,  ca, 0
        , 0,   0, 1);
}


mat3 mat3::scale (vec3 s)
{
    return mat3
        (s.x,   0,   0
        ,  0, s.y,   0
        ,  0,   0, s.z);
}


mat3 mat3::scale (float x, float y, float z)
{
    return mat3
        (x, 0, 0
        ,0, y, 0
        ,0, 0, z);
}


mat3 mat3::transl (vec2 p)
{
    return mat3
        (1, 0, p.x
        ,0, 1, p.y
        ,0, 0, 1);
}


mat3 mat3::transl (float x, float y)
{
    return mat3
        (1, 0, x
        ,0, 1, y
        ,0, 0, 1);
}


float& mat3::operator() (int row, int col)
{
    return val[col][row];
}


float mat3::operator() (int row, int col) const
{
    return val[col][row];
}


vec2& mat3::v0 ()
{
    return *((vec2*)val[0]);
}


vec2& mat3::v1 ()
{
    return *((vec2*)val[1]);
}


vec2& mat3::v2 ()
{
    return *((vec2*)val[2]);
}


const vec2& mat3::v0 () const
{
    return *((vec2*)val[0]);
}


const vec2& mat3::v1 () const
{
    return *((vec2*)val[1]);
}


const vec2& mat3::v2 () const
{
    return *((vec2*)val[2]);
}


mat3 mat3::operator* (const mat3& m)
{
    const mat3& a = *this;

    float m00 = a(0,0) * m(0,0) + a(0,1) * m(1,0) + a(0,2) * m(2,0);
    float m01 = a(0,0) * m(0,1) + a(0,1) * m(1,1) + a(0,2) * m(2,1);
    float m02 = a(0,0) * m(0,2) + a(0,1) * m(1,2) + a(0,2) * m(2,2);
    
    float m10 = a(1,0) * m(0,0) + a(1,1) * m(1,0) + a(1,2) * m(2,0);
    float m11 = a(1,0) * m(0,1) + a(1,1) * m(1,1) + a(1,2) * m(2,1);
    float m12 = a(1,0) * m(0,2) + a(1,1) * m(1,2) + a(1,2) * m(2,2);
    
    float m20 = a(2,0) * m(0,0) + a(2,1) * m(1,0) + a(2,2) * m(2,0);
    float m21 = a(2,0) * m(0,1) + a(2,1) * m(1,1) + a(2,2) * m(2,1);
    float m22 = a(2,0) * m(0,2) + a(2,1) * m(1,2) + a(2,2) * m(2,2);
    
    return mat3
        (m00, m01, m02
        ,m10, m11, m12
        ,m20, m21, m22);
}


void mat3::operator*= (const mat3& m)
{
    const mat3& a = *this;

    float m00 = a(0,0) * m(0,0) + a(0,1) * m(1,0) + a(0,2) * m(2,0);
    float m01 = a(0,0) * m(0,1) + a(0,1) * m(1,1) + a(0,2) * m(2,1);
    float m02 = a(0,0) * m(0,2) + a(0,1) * m(1,2) + a(0,2) * m(2,2);
    
    float m10 = a(1,0) * m(0,0) + a(1,1) * m(1,0) + a(1,2) * m(2,0);
    float m11 = a(1,0) * m(0,1) + a(1,1) * m(1,1) + a(1,2) * m(2,1);
    float m12 = a(1,0) * m(0,2) + a(1,1) * m(1,2) + a(1,2) * m(2,2);
    
    float m20 = a(2,0) * m(0,0) + a(2,1) * m(1,0) + a(2,2) * m(2,0);
    float m21 = a(2,0) * m(0,1) + a(2,1) * m(1,1) + a(2,2) * m(2,1);
    float m22 = a(2,0) * m(0,2) + a(2,1) * m(1,2) + a(2,2) * m(2,2);
    
    *this = mat3
        (m00, m01, m02
        ,m10, m11, m12
        ,m20, m21, m22);
}


mat3 mat3::transl () const
{
    const mat3& m = *this;
    return mat3
        (1.0f, 0.0f, m(0,2)
        ,0.0f, 1.0f, m(1,2)
        ,0.0f, 0.0f, 1.0f);
}


mat3 mat3::rot () const
{
    const mat3& m = *this;
    return mat3
        (m(0,0), m(0,1), 0.0f
        ,m(1,0), m(1,1), 0.0f
        ,0.0f  , 0.0f  , 1.0f);
}


mat3 OGDT::transpose (const mat3& m)
{
    return mat3
        (m(0,0), m(1,0), m(2,0)
        ,m(0,1), m(1,1), m(2,1)
        ,m(0,2), m(1,2), m(2,2));
}
