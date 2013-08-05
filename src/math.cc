#include <OGDT/math.h>
#include <cmath> // sqrt, trig

using namespace OGDT;

R rmin (R a, R b) { return a < b ? a : b; }
R rmax (R a, R b) { return a > b ? a : b; }

//
// 2D vector
//

void vec2::normalise () {
    R n = sqrt(x*x + y*y);
    n = n == 0.0f ? 1.0f : n;
    x /= n;
    y /= n;
}

vec2 OGDT::operator- (vec2 a) {
    return vec2 (-a.x, -a.y);
}

vec2 OGDT::operator+ (vec2 a, vec2 b) {
    return vec2 (a.x + b.x, a.y + b.y);
}

vec2 OGDT::operator- (vec2 a, vec2 b) {
    return vec2 (a.x - b.x, a.y - b.y);
}

vec2 OGDT::operator* (vec2 a, vec2 b) {
    return vec2 (a.x * b.x, a.y * b.y);
}

vec2 OGDT::operator/ (vec2 a, vec2 b) {
    return vec2 (a.x / b.x, a.y / b.y);
}

void OGDT::operator += (vec2& a, vec2 b) {
    a.x += b.x;
    a.y += b.y;
}

void OGDT::operator -= (vec2& a, vec2 b) {
    a.x -= b.x;
    a.y -= b.y;
}

void OGDT::operator *= (vec2& a, vec2 b) {
    a.x *= b.x;
    a.y *= b.y;
}

void OGDT::operator /= (vec2& a, vec2 b) {
    a.x /= b.x;
    a.y /= b.y;
}

R OGDT::norm (vec2 v) {
    return sqrt (v.x * v.x + v.y * v.y);
}

R OGDT::norm2 (vec2 v) {
    return v.x * v.x + v.y * v.y;
}

vec2 OGDT::normalise (vec2 v) {
    R n = sqrt(v.x*v.x + v.y*v.y);
    n = n == 0.0f ? 1.0f : n;
    return vec2 (v.x / n, v.y / n);
}

//
// 3D vector
//

void vec3::normalise ()
{
    R n = sqrt(x*x + y*y + z*z);
    n = n == 0.0f ? 1.0f : n;
    x /= n;
    y /= n;
    z /= n;
}

vec3 OGDT::operator- (vec3 v) {
    return vec3 (-v.x, -v.y, -v.z);
}

vec3 OGDT::operator+ (vec3 a, vec3 b) {
    return vec3 (a.x + b.x, a.y + b.y, a.z + b.z);
}

vec3 OGDT::operator- (vec3 a, vec3 b) {
    return vec3 (a.x - b.x, a.y - b.y, a.z - b.z);
}

vec3 OGDT::operator* (vec3 a, vec3 b) {
    return vec3 (a.x * b.x, a.y * b.y, a.z * b.z);
}

vec3 OGDT::operator/ (vec3 a, vec3 b) {
    return vec3 (a.x / b.x, a.y / b.y, a.z / b.z);
}

void OGDT::operator += (vec3& a, vec3 b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
}

void OGDT::operator -= (vec3& a, vec3 b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
}

void OGDT::operator *= (vec3& a, vec3 b) {
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
}

void OGDT::operator /= (vec3& a, vec3 b) {
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
}

R OGDT::norm (vec3 v) {
    return sqrt (v.x * v.x + v.y * v.y + v.z * v.z);
}

R OGDT::norm2 (vec3 v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

vec3 OGDT::normalise (vec3 v) {
    R n = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    n = n == 0.0f ? 1.0f : n;
    return vec3 (v.x / n, v.y / n, v.z / n);
}

R OGDT::dot (vec3 a, vec3 b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

vec3 OGDT::cross (vec3 a, vec3 b) {
    return vec3
        (a.y*b.z - a.z*b.y
        ,a.z*b.x - a.x*b.z
        ,a.x*b.y - a.y*b.x);
}

//
// 4D vector
//

void vec4::normalise () {
    R n = sqrt(x*x + y*y + z*z * w*w);
    n = n == 0.0f ? 1.0f : n;
    x /= n;
    y /= n;
    z /= n;
}

vec4 OGDT::operator- (vec4 a) {
    return vec4 (-a.x, -a.y, -a.z, -a.w);
}

vec4 OGDT::operator+ (vec4 a, vec4 b) {
    return vec4 (a.x + b.y, a.y + b.y, a.z + b.z, a.w + b.w);
}

vec4 OGDT::operator- (vec4 a, vec4 b) {
    return vec4 (a.x - b.y, a.y - b.y, a.z - b.z, a.w - b.w);
}

vec4 OGDT::operator* (vec4 a, vec4 b) {
    return vec4 (a.x * b.y, a.y * b.y, a.z * b.z, a.w * b.w);
}

vec4 OGDT::operator/ (vec4 a, vec4 b) {
    return vec4 (a.x / b.y, a.y / b.y, a.z / b.z, a.w / b.w);
}

void OGDT::operator += (vec4& a, vec4 b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
}

void OGDT::operator -= (vec4& a, vec4 b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
}

void OGDT::operator *= (vec4& a, vec4 b) {
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
}

void OGDT::operator /= (vec4& a, vec4 b) {
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
}

R OGDT::norm (vec4 v)
{
    return sqrt (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

R OGDT::norm2 (vec4 v) {
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

//
// Quaternion
//

quat OGDT::operator* (quat q1, quat q2) {
    R w, x, y, z;
    w = q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z;
    x = q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y;
    y = q1.w*q2.y - q1.x*q2.z + q1.y*q2.w + q1.z*q2.x;
    z = q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w;
    return quat (w, x, y, z);
}

quat OGDT::qrot (R angle, R x, R y, R z) {
    R a = angle * TO_RAD * 0.5f;
    R sa = sin (a);
    R w = cos (a);
    R mag = sqrt(x*x + y*y + z*z);
    mag = mag == 0.0f ? 1.0f : mag;
    x = x * sa;
    y = y * sa;
    z = z * sa;
    return quat (w, x / mag, y / mag, z / mag);
}

quat OGDT::inv (quat q) {
    R magsq = q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z;
    magsq = magsq == 0.0f ? 1.0f : magsq;
    return quat (q.w / magsq, -q.x / magsq, -q.y / magsq, -q.z / magsq);
}

quat OGDT::conj (quat q) {
    return quat (q.w, -q.x, -q.y, -q.z);
}

vec3 OGDT::rot (const quat& q, const vec3& v) {
    quat p = conj (q);
    quat qv (0, v.x, v.y, v.z);
    qv = q * qv * p;
    return vec3 (qv.x, qv.y, qv.z);
}

void rot (const quat& q, vec3& v) {
    quat p = conj (q);
    quat qv (0, v.x, v.y, v.z);
    qv = q * qv * p;
    v.x = qv.x; v.y = qv.y; v.z = qv.z;
}

//
// AABB2
//

AABB2::AABB2 (vec2* ps, unsigned n) {
    vec2* p = ps;
    for (unsigned i = 0; i < n; ++i, ++p)
    {
        min.x = rmin (min.x, p->x);
        min.y = rmin (min.y, p->y);

        max.x = rmax (max.x, p->x);
        max.y = rmax (max.y, p->y);
    }
}

void AABB2::add (vec2 p) {
    min.x = rmin (min.x, p.x);
    min.y = rmin (min.y, p.y);

    max.x = rmax (max.x, p.x);
    max.y = rmax (max.y, p.y);
}

//
// AABB3
//

AABB3::AABB3 (vec3* ps, unsigned n) {
    vec3* p = ps;
    for (unsigned i = 0; i < n; ++i, ++p)
    {
        min.x = rmin (min.x, p->x);
        min.y = rmin (min.y, p->y);
        min.z = rmin (min.z, p->z);

        max.x = rmax (max.x, p->x);
        max.y = rmax (max.y, p->y);
        max.z = rmax (max.z, p->z);
    }
}

void AABB3::add (vec3 p) {
    min.x = rmin (min.x, p.x);
    min.y = rmin (min.y, p.y);
    min.z = rmin (min.z, p.z);

    max.x = rmax (max.x, p.x);
    max.y = rmax (max.y, p.y);
    max.z = rmax (max.z, p.z);
}

// Circle

circle::circle (vec2 _center, R _radius)
    : center (_center), radius2 (_radius*_radius) {}

void circle::add (vec2 p) {
    radius2 = rmax (radius2, norm2(p));
}

R circle::radius () const {
    return std::sqrt (radius2);
}

//
// Sphere
//

sphere::sphere (vec3 c, R r)
    : center (c), radius2 (r*r) {}

void sphere::add (vec3 p) {
    radius2 = rmax (radius2, norm2(p));
}

R sphere::radius () const {
    return std::sqrt (radius2);
}

//
// 3x3 matrix
//

mat3::mat3 () {
    val[0][0] = 1; val[0][1] = 0; val[0][2] = 0;
    val[1][0] = 0; val[1][1] = 1; val[1][2] = 0;
    val[2][0] = 0; val[2][1] = 0; val[2][2] = 1;
}

mat3::mat3 (R m00, R m10, R m20,
            R m01, R m11, R m21,
            R m02, R m12, R m22) {
    val[0][0] = m00; val[0][1] = m01; val[0][2] = m02;
    val[1][0] = m10; val[1][1] = m11; val[1][2] = m12;
    val[2][0] = m20; val[2][1] = m21; val[2][2] = m22;
}

mat3::mat3 (const vec3& v0,
            const vec3& v1,
            const vec3& v2) {
    val[0][0] = v0.x; val[0][1] = v0.y; val[0][2] = v0.z;
    val[1][0] = v1.x; val[1][1] = v1.y; val[1][2] = v1.z;
    val[2][0] = v2.x; val[2][1] = v2.y; val[2][2] = v2.z;
}

mat3::mat3 (const vec2& right, const vec2& up, const vec2& pos) {
    val[0][0] = right.x; val[0][1] = right.y; val[0][2] = 0;
    val[1][0] = up.x;    val[1][1] = up.y;    val[1][2] = 0;
    val[2][0] = pos.x;   val[2][1] = pos.y;   val[2][2] = 1;
}

mat3 mat3::rot (R angle) {
    R a  = angle * (R) M_PI / 180.0f;
    R sa = sin (a);
    R ca = cos (a);

    return mat3
        (ca, -sa, 0
        ,sa,  ca, 0
        , 0,   0, 1);
}

mat3 mat3::scale (vec3 s) {
    return mat3
        (s.x,   0,   0
        ,  0, s.y,   0
        ,  0,   0, s.z);
}

mat3 mat3::scale (R x, R y, R z) {
    return mat3
        (x, 0, 0
        ,0, y, 0
        ,0, 0, z);
}

mat3 mat3::transl (vec2 p) {
    return mat3
        (1, 0, p.x
        ,0, 1, p.y
        ,0, 0, 1);
}

mat3 mat3::transl (R x, R y) {
    return mat3
        (1, 0, x
        ,0, 1, y
        ,0, 0, 1);
}

R& mat3::operator() (int row, int col) {
    return val[col][row];
}

R mat3::operator() (int row, int col) const {
    return val[col][row];
}

vec2& mat3::v0 () {
    return *((vec2*)val[0]);
}

vec2& mat3::v1 ()
{
    return *((vec2*)val[1]);
}

vec2& mat3::v2 () {
    return *((vec2*)val[2]);
}

const vec2& mat3::v0 () const {
    return *((vec2*)val[0]);
}

const vec2& mat3::v1 () const {
    return *((vec2*)val[1]);
}

const vec2& mat3::v2 () const {
    return *((vec2*)val[2]);
}

mat3 mat3::operator* (const mat3& m) {
    const mat3& a = *this;

    R m00 = a(0,0) * m(0,0) + a(0,1) * m(1,0) + a(0,2) * m(2,0);
    R m01 = a(0,0) * m(0,1) + a(0,1) * m(1,1) + a(0,2) * m(2,1);
    R m02 = a(0,0) * m(0,2) + a(0,1) * m(1,2) + a(0,2) * m(2,2);

    R m10 = a(1,0) * m(0,0) + a(1,1) * m(1,0) + a(1,2) * m(2,0);
    R m11 = a(1,0) * m(0,1) + a(1,1) * m(1,1) + a(1,2) * m(2,1);
    R m12 = a(1,0) * m(0,2) + a(1,1) * m(1,2) + a(1,2) * m(2,2);

    R m20 = a(2,0) * m(0,0) + a(2,1) * m(1,0) + a(2,2) * m(2,0);
    R m21 = a(2,0) * m(0,1) + a(2,1) * m(1,1) + a(2,2) * m(2,1);
    R m22 = a(2,0) * m(0,2) + a(2,1) * m(1,2) + a(2,2) * m(2,2);

    return mat3
        (m00, m01, m02
        ,m10, m11, m12
        ,m20, m21, m22);
}

void mat3::operator*= (const mat3& m) {
    const mat3& a = *this;

    R m00 = a(0,0) * m(0,0) + a(0,1) * m(1,0) + a(0,2) * m(2,0);
    R m01 = a(0,0) * m(0,1) + a(0,1) * m(1,1) + a(0,2) * m(2,1);
    R m02 = a(0,0) * m(0,2) + a(0,1) * m(1,2) + a(0,2) * m(2,2);

    R m10 = a(1,0) * m(0,0) + a(1,1) * m(1,0) + a(1,2) * m(2,0);
    R m11 = a(1,0) * m(0,1) + a(1,1) * m(1,1) + a(1,2) * m(2,1);
    R m12 = a(1,0) * m(0,2) + a(1,1) * m(1,2) + a(1,2) * m(2,2);

    R m20 = a(2,0) * m(0,0) + a(2,1) * m(1,0) + a(2,2) * m(2,0);
    R m21 = a(2,0) * m(0,1) + a(2,1) * m(1,1) + a(2,2) * m(2,1);
    R m22 = a(2,0) * m(0,2) + a(2,1) * m(1,2) + a(2,2) * m(2,2);

    *this = mat3
        (m00, m01, m02
        ,m10, m11, m12
        ,m20, m21, m22);
}

mat3 mat3::transl () const {
    const mat3& m = *this;
    return mat3
        (1.0f, 0.0f, m(0,2)
        ,0.0f, 1.0f, m(1,2)
        ,0.0f, 0.0f, 1.0f);
}

mat3 mat3::rot () const {
    const mat3& m = *this;
    return mat3
        (m(0,0), m(0,1), 0.0f
        ,m(1,0), m(1,1), 0.0f
        ,0.0f  , 0.0f  , 1.0f);
}

const mat3 mat3::reflectx = mat3
    (-1, 0, 0
    , 0, 1, 0
    , 0, 0, 1);

const mat3 mat3::reflecty = mat3
    (1,  0,  0
    ,0, -1,  0
    ,0,  0,  1);

const mat3 mat3::reflectz = mat3
    (1,  0,  0
    ,0,  1,  0
    ,0,  0, -1);

const mat3 mat3::id = mat3
    ( 1.0f, 0.0f, 0.0f
    , 0.0f, 1.0f, 0.0f
    , 0.0f, 0.0f, 1.0f);

mat3 OGDT::inverse (const mat3& m) {
    R m00 = m[0];
    R m01 = m[1];
    R m02 = m[2];
    R m03 = m[3];
    R m04 = m[4];
    R m05 = m[5];
    R m06 = m[6];
    R m07 = m[7];
    R m08 = m[8];

    R det = m00*(m04*m08-m05*m07) - m03*(m01*m08-m02*m07) + m06*(m01*m05-m02*m04);
    if (det == 0.0f) return mat3::id;

    R d10 = m04*m08 - m07*m05;
    R d11 = m03*m08 - m06*m05;
    R d12 = m03*m07 - m06*m04;
    R d20 = m01*m08 - m07*m02;
    R d21 = m00*m08 - m06*m02;
    R d22 = m00*m07 - m06*m01;
    R d30 = m01*m05 - m04*m02;
    R d31 = m00*m05 - m03*m02;
    R d32 = m00*m04 - m03*m01;

    det = det / 1.0f;

    return mat3
            ( d10*det, -d11*det,  d12*det
            ,-d20*det,  d21*det, -d22*det
            , d30*det, -d31*det,  d32*det);
}

mat3 OGDT::transpose (const mat3& m) {
    return mat3
        (m(0,0), m(1,0), m(2,0)
        ,m(0,1), m(1,1), m(2,1)
        ,m(0,2), m(1,2), m(2,2));
}

vec3 OGDT::operator* (const mat3& m, vec3 v) {
    return vec3
        (m[0]*v.x + m[1]*v.y + m[2]*v.z,
         m[3]*v.x + m[4]*v.y + m[5]*v.z,
         m[6]*v.x + m[7]*v.y + m[8]*v.z);
}

//
// 4x4 matrix
//

mat4::mat4 () {
    val[0][0] = 1; val[0][1] = 0; val[0][2] = 0; val[0][3] = 0;
    val[1][0] = 0; val[1][1] = 1; val[1][2] = 0; val[1][3] = 0;
    val[2][0] = 0; val[2][1] = 0; val[2][2] = 1; val[2][3] = 0,
    val[3][0] = 0; val[3][1] = 0; val[3][2] = 0; val[3][3] = 1;
}

mat4::mat4 (R m00, R m10, R m20, R m30,
            R m01, R m11, R m21, R m31,
            R m02, R m12, R m22, R m32,
            R m03, R m13, R m23, R m33) {
    val[0][0] = m00; val[0][1] = m01; val[0][2] = m02; val[0][3] = m03;
    val[1][0] = m10; val[1][1] = m11; val[1][2] = m12; val[1][3] = m13;
    val[2][0] = m20; val[2][1] = m21; val[2][2] = m22; val[2][3] = m23,
    val[3][0] = m30; val[3][1] = m31; val[3][2] = m32; val[3][3] = m33;
}

mat4::mat4 (const vec4& v0,
            const vec4& v1,
            const vec4& v2,
            const vec4& v3) {
    val[0][0] = v0.x; val[0][1] = v0.y; val[0][2] = v0.z; val[0][3] = v0.w;
    val[1][0] = v1.x; val[1][1] = v1.y; val[1][2] = v1.z; val[1][3] = v1.w;
    val[2][0] = v2.x; val[2][1] = v2.y; val[2][2] = v2.z; val[2][3] = v2.w,
    val[3][0] = v3.x; val[3][1] = v3.y; val[3][2] = v3.z; val[3][3] = v3.w;
}

mat4::mat4 (const vec3& v0, const vec3& v1, const vec3& v2, const vec3& v3) {
    val[0][0] = v0.x; val[0][1] = v0.y; val[0][2] = v0.z; val[0][3] = 0.0f;
    val[1][0] = v1.x; val[1][1] = v1.y; val[1][2] = v1.z; val[1][3] = 0.0f;
    val[2][0] = v2.x; val[2][1] = v2.y; val[2][2] = v2.z; val[2][3] = 0.0f;
    val[3][0] = v3.x; val[3][1] = v3.y; val[3][2] = v3.z; val[3][3] = 1.0f;
}

R& mat4::operator() (int row, int col) {
    return val[col][row];
}

R mat4::operator() (int row, int col) const {
    return val[col][row];
}

vec3& mat4::v0 () {
    return *((vec3*)val[0]);
}

vec3& mat4::v1 () {
    return *((vec3*)val[1]);
}

vec3& mat4::v2 () {
    return *((vec3*)val[2]);
}

vec3& mat4::v3 () {
    return *((vec3*)val[3]);
}

const vec3& mat4::v0 () const {
    return *((vec3*)val[0]);
}

const vec3& mat4::v1 () const {
    return *((vec3*)val[1]);
}

const vec3& mat4::v2 () const {
    return *((vec3*)val[2]);
}

const vec3& mat4::v3 () const {
    return *((vec3*)val[3]);
}

mat4 mat4::operator* (const mat4& m) {
    const mat4& a = *this;

    R m00 = a(0,0) * m(0,0) + a(0,1) * m(1,0) + a(0,2) * m(2,0) + a(0,3) * m(3,0);
    R m10 = a(0,0) * m(0,1) + a(0,1) * m(1,1) + a(0,2) * m(2,1) + a(0,3) * m(3,1);
    R m20 = a(0,0) * m(0,2) + a(0,1) * m(1,2) + a(0,2) * m(2,2) + a(0,3) * m(3,2);
    R m30 = a(0,0) * m(0,3) + a(0,1) * m(1,3) + a(0,2) * m(2,3) + a(0,3) * m(3,3);

    R m01 = a(1,0) * m(0,0) + a(1,1) * m(1,0) + a(1,2) * m(2,0) + a(1,3) * m(3,0);
    R m11 = a(1,0) * m(0,1) + a(1,1) * m(1,1) + a(1,2) * m(2,1) + a(1,3) * m(3,1);
    R m21 = a(1,0) * m(0,2) + a(1,1) * m(1,2) + a(1,2) * m(2,2) + a(1,3) * m(3,2);
    R m31 = a(1,0) * m(0,3) + a(1,1) * m(1,3) + a(1,2) * m(2,3) + a(1,3) * m(3,3);

    R m02 = a(2,0) * m(0,0) + a(2,1) * m(1,0) + a(2,2) * m(2,0) + a(2,3) * m(3,0);
    R m12 = a(2,0) * m(0,1) + a(2,1) * m(1,1) + a(2,2) * m(2,1) + a(2,3) * m(3,1);
    R m22 = a(2,0) * m(0,2) + a(2,1) * m(1,2) + a(2,2) * m(2,2) + a(2,3) * m(3,2);
    R m32 = a(2,0) * m(0,3) + a(2,1) * m(1,3) + a(2,2) * m(2,3) + a(2,3) * m(3,3);

    R m03 = a(3,0) * m(0,0) + a(3,1) * m(1,0) + a(3,2) * m(2,0) + a(3,3) * m(3,0);
    R m13 = a(3,0) * m(0,1) + a(3,1) * m(1,1) + a(3,2) * m(2,1) + a(3,3) * m(3,1);
    R m23 = a(3,0) * m(0,2) + a(3,1) * m(1,2) + a(3,2) * m(2,2) + a(3,3) * m(3,2);
    R m33 = a(3,0) * m(0,3) + a(3,1) * m(1,3) + a(3,2) * m(2,3) + a(3,3) * m(3,3);

    return mat4
        (m00, m10, m20, m30
        ,m01, m11, m21, m31
        ,m02, m12, m22, m32
        ,m03, m13, m23, m33);
}

void mat4::operator*= (const mat4& m) {
    const mat4& a = *this;

    R m00 = a(0,0) * m(0,0) + a(0,1) * m(1,0) + a(0,2) * m(2,0) + a(0,3) * m(3,0);
    R m10 = a(0,0) * m(0,1) + a(0,1) * m(1,1) + a(0,2) * m(2,1) + a(0,3) * m(3,1);
    R m20 = a(0,0) * m(0,2) + a(0,1) * m(1,2) + a(0,2) * m(2,2) + a(0,3) * m(3,2);
    R m30 = a(0,0) * m(0,3) + a(0,1) * m(1,3) + a(0,2) * m(2,3) + a(0,3) * m(3,3);

    R m01 = a(1,0) * m(0,0) + a(1,1) * m(1,0) + a(1,2) * m(2,0) + a(1,3) * m(3,0);
    R m11 = a(1,0) * m(0,1) + a(1,1) * m(1,1) + a(1,2) * m(2,1) + a(1,3) * m(3,1);
    R m21 = a(1,0) * m(0,2) + a(1,1) * m(1,2) + a(1,2) * m(2,2) + a(1,3) * m(3,2);
    R m31 = a(1,0) * m(0,3) + a(1,1) * m(1,3) + a(1,2) * m(2,3) + a(1,3) * m(3,3);

    R m02 = a(2,0) * m(0,0) + a(2,1) * m(1,0) + a(2,2) * m(2,0) + a(2,3) * m(3,0);
    R m12 = a(2,0) * m(0,1) + a(2,1) * m(1,1) + a(2,2) * m(2,1) + a(2,3) * m(3,1);
    R m22 = a(2,0) * m(0,2) + a(2,1) * m(1,2) + a(2,2) * m(2,2) + a(2,3) * m(3,2);
    R m32 = a(2,0) * m(0,3) + a(2,1) * m(1,3) + a(2,2) * m(2,3) + a(2,3) * m(3,3);

    R m03 = a(3,0) * m(0,0) + a(3,1) * m(1,0) + a(3,2) * m(2,0) + a(3,3) * m(3,0);
    R m13 = a(3,0) * m(0,1) + a(3,1) * m(1,1) + a(3,2) * m(2,1) + a(3,3) * m(3,1);
    R m23 = a(3,0) * m(0,2) + a(3,1) * m(1,2) + a(3,2) * m(2,2) + a(3,3) * m(3,2);
    R m33 = a(3,0) * m(0,3) + a(3,1) * m(1,3) + a(3,2) * m(2,3) + a(3,3) * m(3,3);

    *this = mat4
        (m00, m10, m20, m30
        ,m01, m11, m21, m31
        ,m02, m12, m22, m32
        ,m03, m13, m23, m33);
}

mat4 mat4::transl () const {
    const mat4& m = *this;
    return mat4
        (1.0f, 0.0f, 0.0f, m(0,3)
        ,0.0f, 1.0f, 0.0f, m(1,3)
        ,0.0f, 0.0f, 1.0f, m(2,3)
        ,0.0f, 0.0f, 0.0f, 1.0f);
}

mat4 mat4::rot () const {
    const mat4& m = *this;
    return mat4
        (m(0,0), m(0,1), m(0,2), 0.0f
        ,m(1,0), m(1,1), m(1,2), 0.0f
        ,m(2,0), m(2,1), m(2,2), 0.0f
        ,0.0f  , 0.0f  , 0.0f  , 1.0f
         );
}

mat3 mat4::to33 () const {
    const mat4& m = *this;
    return mat3
        (m(0,0), m(0,1), m(0,2)
        ,m(1,0), m(1,1), m(1,2)
        ,m(2,0), m(2,1), m(2,2));
}

mat4 mat4::rotx (R angle) {
    R a = angle * TO_RAD;
    R s = sin (a);
    R c = cos (a);

    return mat4
        (1, 0,  0, 0
        ,0, c, -s, 0
        ,0, s,  c, 0
        ,0, 0,  0, 1);
}

mat4 mat4::roty (R angle) {
    R a = angle * TO_RAD;
    R s = sin (a);
    R c = cos (a);

    return mat4
        ( c, 0, s, 0
        , 0, 1, 0, 0
        ,-s, 0, c, 0
        , 0, 0, 0, 1);
}

mat4 mat4::rotz (R angle) {
    R a = angle * TO_RAD;
    R s = sin (a);
    R c = cos (a);

    return mat4
        (c, -s, 0, 0
        ,s,  c, 0, 0
        ,0,  0, 1, 0
        ,0,  0, 0, 1);
}

mat4 mat4::rot (R angle, const vec3& axis) {
    return rot (angle, axis.x, axis.y, axis.z);
}

mat4 mat4::rot (R angle, R x, R y, R z) {
    R a = angle * TO_RAD;
    R s = sin (a);
    R c = cos (a);

    R xy  = x*y;
    R xz  = x*z;
    R yz  = y*z;
    R sx  = s*x;
    R sy  = s*y;
    R sz  = s*z;
    R omc = 1.0f - c;

    return mat4
        (c + omc*x*x, omc*xy-sz, omc*xz+sy, 0
        ,omc*xy+sz,   c+omc*y*y, omc*yz-sx, 0
        ,omc*xz-sy,   omc*yz+sx, c+omc*z*z, 0
        ,0,           0,         0,         1);
}

mat4 mat4::scale (const vec3& s) {
    return mat4
        (s.x,   0,   0,   0
        ,  0, s.y,   0,   0
        ,  0,   0, s.z,   0
        ,  0,   0,   0,   1);
}

mat4 mat4::scale (R x, R y, R z) {
    return mat4
        (x, 0, 0, 0
        ,0, y, 0, 0
        ,0, 0, z, 0
        ,0, 0, 0, 1);
}

mat4 mat4::transl (const vec3& p) {
    return mat4
        (1, 0, 0, p.x
        ,0, 1, 0, p.y
        ,0, 0, 1, p.z
        ,0, 0, 0, 1);
}

mat4 mat4::transl (R x, R y, R z) {
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

mat4 mat4::lookAt (const vec3& position, const vec3& target) {
    vec3 fwd   = normalise (target - position);
    vec3 right = cross (fwd, vec3(0,1,0));
    vec3 up    = cross (right, fwd);
    return mat4 (right, up, fwd, position);
}

mat4 mat4::ortho (R l, R r, R b, R t, R n, R f) {
    R tx = -(r+l) / (r-l);
    R ty = -(t+b) / (t-b);
    R tz = -(f+n) / (f-n);

    return mat4
        (2/(r-l), 0,        0,       tx
        ,0,       2/(t-b),  0,       ty
        ,0,       0,       -2/(f-n), tz
        ,0,       0,        0,       1);
}

mat4 mat4::perspective (R fovy, R r, R near, R far) {
    R f = tan (fovy * TO_RAD / 2.0f);
    f = f == 0.0f ? 1.0f : 1.0f / f;
    R a = near - far;

    return mat4
        (f/r, 0,  0,            0
        ,0,   f,  0,            0
        ,0,   0, (far+near)/a, (2*far*near/a)
        ,0,   0, -1,            0);
}

mat4 OGDT::inverse (const mat4& m) {
    const R* vals = m;
    R m00 = vals[0];
    R m01 = vals[1];
    R m02 = vals[2];
    R m03 = vals[3];
    R m04 = vals[4];
    R m05 = vals[5];
    R m06 = vals[6];
    R m07 = vals[7];
    R m08 = vals[8];
    R m09 = vals[9];
    R m10 = vals[10];
    R m11 = vals[11];
    R m12 = vals[12];
    R m13 = vals[13];
    R m14 = vals[14];
    R m15 = vals[15];

    R i00 = m05 * m10  * m15
              - m05 * m11  * m14
              - m09 * m06  * m15
              + m09 * m07  * m14
              + m13 * m06  * m11
              - m13 * m07  * m10;

    R i04 = -m04 * m10 * m15
              +  m04 * m11 * m14
              +  m08 * m06 * m15
              -  m08 * m07 * m14
              -  m12 * m06 * m11
              +  m12 * m07 * m10;

    R i08 = m04 * m09 * m15
              - m04 * m11 * m13
              - m08 * m05 * m15
              + m08 * m07 * m13
              + m12 * m05 * m11
              - m12 * m07 * m09;

    R i12 = -m04 * m09 * m14
              +  m04 * m10 * m13
              +  m08 * m05 * m14
              -  m08 * m06 * m13
              -  m12 * m05 * m10
              +  m12 * m06 * m09;

    R i01 = -m01 * m10 * m15
              +  m01 * m11 * m14
              +  m09 * m02 * m15
              -  m09 * m03 * m14
              -  m13 * m02 * m11
              +  m13 * m03 * m10;

    R i05 = m00 * m10 * m15
              - m00 * m11 * m14
              - m08 * m02 * m15
              + m08 * m03 * m14
              + m12 * m02 * m11
              - m12 * m03 * m10;

    R i09 = -m00 * m09 * m15
              +  m00 * m11 * m13
              +  m08 * m01 * m15
              -  m08 * m03 * m13
              -  m12 * m01 * m11
              +  m12 * m03 * m09;

    R i13 = m00 * m09 * m14
              - m00 * m10 * m13
              - m08 * m01 * m14
              + m08 * m02 * m13
              + m12 * m01 * m10
              - m12 * m02 * m09;

    R i02 = m01 * m06 * m15
              - m01 * m07 * m14
              - m05 * m02 * m15
              + m05 * m03 * m14
              + m13 * m02 * m07
              - m13 * m03 * m06;

    R i06 = -m00 * m06 * m15
              +  m00 * m07 * m14
              +  m04 * m02 * m15
              -  m04 * m03 * m14
              -  m12 * m02 * m07
              +  m12 * m03 * m06;

    R i10 = m00 * m05 * m15
              - m00 * m07 * m13
              - m04 * m01 * m15
              + m04 * m03 * m13
              + m12 * m01 * m07
              - m12 * m03 * m05;

    R i14 = -m00 * m05 * m14
              +  m00 * m06 * m13
              +  m04 * m01 * m14
              -  m04 * m02 * m13
              -  m12 * m01 * m06
              +  m12 * m02 * m05;

    R i03 = -m01 * m06 * m11
              +  m01 * m07 * m10
              +  m05 * m02 * m11
              -  m05 * m03 * m10
              -  m09 * m02 * m07
              +  m09 * m03 * m06;

    R i07 = m00 * m06 * m11
              - m00 * m07 * m10
              - m04 * m02 * m11
              + m04 * m03 * m10
              + m08 * m02 * m07
              - m08 * m03 * m06;

    R i11 = -m00 * m05 * m11
              +  m00 * m07 * m09
              +  m04 * m01 * m11
              -  m04 * m03 * m09
              -  m08 * m01 * m07
              +  m08 * m03 * m05;

    R i15 = m00 * m05 * m10
              - m00 * m06 * m09
              - m04 * m01 * m10
              + m04 * m02 * m09
              + m08 * m01 * m06
              - m08 * m02 * m05;

    R det = m00 * i00 + m01 * i04 + m02 * i08 + m03 * i12;
    if (det == 0) return mat4::id;
    else {
        det = 1.0f / det;
        return mat4
            (i00 * det, i04 * det, i08 * det, i12 * det
            ,i01 * det, i05 * det, i09 * det, i13 * det
            ,i02 * det, i06 * det, i10 * det, i14 * det
            ,i03 * det, i07 * det, i11 * det, i15 * det);
    }
}

mat4 OGDT::inverse_transform (const mat4& m) {
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

mat4 OGDT::transpose (const mat4& m) {
    return mat4
        (m(0,0), m(1,0), m(2,0), m(3,0)
        ,m(0,1), m(1,1), m(2,1), m(3,1)
        ,m(0,2), m(1,2), m(2,2), m(3,2)
        ,m(0,3), m(1,3), m(2,3), m(3,3));
}

vec3 OGDT::transform (const mat4& m, vec3 v, R w) {
    vec3 u;
    u.x = m(0,0) * v.x + m(0,1) * v.y + m(0,2) * v.z + m(0,3) * w;
    u.y = m(1,0) * v.x + m(1,1) * v.y + m(1,2) * v.z + m(1,3) * w;
    u.z = m(2,0) * v.x + m(2,1) * v.y + m(2,2) * v.z + m(2,3) * w;
    return u;
}

//
// Spatial
//

Spatial::Spatial ()
    : r (right3), u (up3), f (forward3) {}

Spatial::Spatial (const vec3& pos, const vec3& target) {
    setPosition (pos);
    lookAt (target);
}

void Spatial::move (const vec3& direction) {
    p += direction;
}

void Spatial::moveForwards (R speed) {
    move (fwd() * speed);
}

void Spatial::moveBackwards (R speed) {
    move (fwd() * -speed);
}

void Spatial::strafeLeft (R speed) {
     move (right() * -speed);
}

void Spatial::strafeRight (R speed) {
     move (right() * speed);
}

void Spatial::moveUp (R speed) {
     move (up() * speed);
}

void Spatial::moveDown (R speed) {
     move (up() * -speed);
}

void Spatial::rotate (R angle, R x, R y, R z) {
    mat4 transf = transform();
    vec3 axis = ::transform (inverse_transform(transf), vec3 (x,y,z), 0.0f);
    axis.normalise();
    transf *= mat4::rot (angle, axis);
    r = normalise(transf.v0());
    u = normalise(transf.v1());
    f = normalise(-transf.v2());
}

void Spatial::yaw (const R angle) {
    R a = angle * TO_RAD;
    R sa = sin (a);
    R ca = cos (a);
    f = f*ca - r*sa;
    f.normalise();
    r = cross (f, u);
    r.normalise();
}

void Spatial::pitch (const R angle) {
    R a = angle * TO_RAD;
    R sa = sin (a);
    R ca = cos (a);
    f = f*ca + u*sa;
    f.normalise();
    u = cross (r, f);
    u.normalise();
}

void Spatial::roll (const R angle) {
    R a = angle * TO_RAD;
    R sa = sin (a);
    R ca = cos (a);
    u = u * ca - r * sa;
    u.normalise();
    r = cross (f, u);
}

void Spatial::setPosition (R x, R y, R z) {
    p.x = x; p.y = y; p.z = z;
}

void Spatial::setPosition (const vec3& v) {
    p = v;
}

void Spatial::setForward (R x, R y, R z) {
    setForward (vec3(x,y,z));
}

void Spatial::setForward (vec3 forward) {
    forward.normalise();
    f = forward;
    r = cross (f, up3);
    u = cross (r, f);
    r.normalise();
    u.normalise();
}

void Spatial::setTransform (const mat4& transform) {
    r = transform.v0();
    u = transform.v1();
    f = -transform.v2();
    p = transform.v3();
}

void Spatial::lookAt (R x, R y, R z) {
    setForward (vec3(x,y,z) - p);
}

void Spatial::lookAt (const vec3& target) {
    setForward (target - p);
}

void Spatial::lookAt (const Spatial& target) {
    setForward (target.pos() - p);
}

void Spatial::orbit (R x, R y, R z, R radius, R azimuth, R zenith) {
    R ax = azimuth * TO_RAD;
    R ay = zenith * TO_RAD;
    R sx = sin(ax);
    R sy = sin(ay);
    R cx = cos(ax);
    R cy = cos(ay);
    setPosition (x + radius*cy*sx, y + radius*sy, z + radius*cx*cy);
}

void Spatial::orbit (const vec3& target, R radius, R azimuth, R zenith) {
    orbit (target.x, target.y, target.z, radius, azimuth, zenith);
}

void Spatial::orbit (const Spatial& target, R radius, R azimuth, R zenith) {
    const vec3& p = target.pos();
    orbit (p.x, p.y, p.z, radius, azimuth, zenith);
}

const vec3& Spatial::pos () const {
    return p;
}

const vec3& Spatial::fwd () const {
    return f;
}

const vec3& Spatial::right () const {
    return r;
}

const vec3& Spatial::up () const {
    return u;
}

mat4 Spatial::transform () const {
    return mat4
        (r.x , u.x , -f.x , p.x
        ,r.y , u.y , -f.y , p.y
        ,r.z , u.z , -f.z , p.z
        ,0.0f, 0.0f, 0.0f, 1.0f
        );
}

mat4 Spatial::inverseTransform () const {
    return inverse_transform (transform());
}

//
// Perspective Camera
//

PerspectiveCamera::PerspectiveCamera ()
    : fovy(45), aspect(640./480.), near(5), far(1000) {}

PerspectiveCamera::PerspectiveCamera (R _fovy, R _aspect, R _near, R _far)
    : fovy(_fovy), aspect(_aspect), near(_near), far(_far) {}

mat4 PerspectiveCamera::projection () const {
    return mat4::perspective(fovy, aspect, near, far);
}

//
// Utils
//

union Floating {
    R f;
    int i;

    Floating (R _f) : f (_f) {}

    bool positive () const { return i >= 0; }
};

bool OGDT::R_eq (R a, R b, R eps, int ULPs) {
    if (a == b) return true;
    else if (a*b == 0.0f) return fabs(a-b) <= eps;
    else {
        Floating x (a);
        Floating y (b);
        if (x.positive() != y.positive()) return false;
        int diff = std::abs (x.i - y.i);
        return diff <= ULPs;
    }
}

mat3 OGDT::qmat3 (const quat& q) {
    R x = q.x;
    R y = q.y;
    R z = q.z;
    R w = q.w;
    R xx = x*x;
    R xy = x*y;
    R xz = x*z;
    R yy = y*y;
    R yz = y*z;
    R zz = z*z;
    R wx = w*x;
    R wy = w*y;
    R wz = w*z;

    return mat3
        ( 1- 2*yy - 2*zz, 2*xy + 2*wz    , 2*xz - 2*wy
        , 2*xy - 2*wz,    1 - 2*xx - 2*zz, 2*yz + 2*wx
        , 2*xz + 2*wy,    2*yz - 2*wx    , 1 - 2*xx - 2*yy);
}

mat4 OGDT::qmat4 (const quat& q) {
    R x = q.x;
    R y = q.y;
    R z = q.z;
    R w = q.w;
    R xx = x*x;
    R xy = x*y;
    R xz = x*z;
    R yy = y*y;
    R yz = y*z;
    R zz = z*z;
    R wx = w*x;
    R wy = w*y;
    R wz = w*z;

    return mat4
        ( 1- 2*yy - 2*zz, 2*xy + 2*wz    , 2*xz - 2*wy    , 0.0f
        , 2*xy - 2*wz,    1 - 2*xx - 2*zz, 2*yz + 2*wx    , 0.0f
        , 2*xz + 2*wy,    2*yz - 2*wx    , 1 - 2*xx - 2*yy, 0.0f
        , 0.0f       ,    0.0f           , 0.0f           , 1.0f);
}

R OGDT::sign (R x) {
    if (x >= 0.0f) return 1.0f;
    else return -1.0f;
}

R OGDT::pitch_from_fwd (vec3 forward) {
    vec3 f = vec3 (0.0f, forward.y, forward.z);
    f.normalise();
    return acos (dot(f, forward3)) * TO_DEG;
}

R OGDT::yaw_from_fwd (vec3 forward) {
    vec3 f = vec3 (forward.x, 0.0, forward.z);
    f.normalise();
    return acos(dot(f, forward3)) * TO_DEG;
}
