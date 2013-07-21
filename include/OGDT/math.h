#pragma once

/*
  Header: math
*/

#define M_E 2.71828182845904523536f
#define M_LOG2E 1.44269504088896340736f
#define M_LOG10E 0.434294481903251827651f
#define M_LN2 0.693147180559945309417f
#define M_LN10 2.30258509299404568402f
#define M_PI 3.14159265358979323846f
#define M_PI_2 1.57079632679489661923f
#define M_PI_4 0.785398163397448309616f
#define M_1_PI 0.318309886183790671538f
#define M_2_PI 0.636619772367581343076f
#define M_1_SQRTPI 0.564189583547756286948f
#define M_2_SQRTPI 1.12837916709551257390f
#define M_SQRT2 1.41421356237309504880f
#define M_SQRT_2 0.707106781186547524401f

typedef float R;

namespace OGDT {

// 2D vector

/*
Struct: vec2
A vector in 2D space.
*/
struct vec2
{
    /*
    Variable: x
    The x coordinate.
    */
    R x;

    /*
    Variable: y
    The y coordinate.
    */
    R y;

    /*
    Constructor: vec2
    Construct a vector and set it to the origin.
    */
    vec2 () : x (0), y (0) {}

    /*
    Constructor: vec2
    Construct a vector from the given coordinates.
    */
    vec2 (R _x, R _y) : x (_x), y (_y) {}

    /*
    Constructor: vec2
    Construct a vector from the given value.

    The vector's coordinates are all set to the given value.
    */
    vec2 (R val) : x (val), y (val) {}

    /*
    Function: normalise
    Normalise the vector.
    */
    void normalise ();

    /*
    operator: const R*
    Return a const R pointer to the given vector's values.
    */
    operator const R* () const { return (R*) this; }
};

/*
Operator: -
Negate the given vector.
*/
vec2 operator- (vec2);

/*
Operator: +
Add two vectors.
*/
vec2 operator+ (vec2, vec2);

/*
Operator: -
Subtract two vectors.
*/
vec2 operator- (vec2, vec2);

/*
Operator: *
Modulate two vectors (component-wise multiplication).
*/
vec2 operator* (vec2, vec2);

/*
Operator: /
Divide two vectors component-wise.
*/
vec2 operator/ (vec2, vec2);

/*
Operator: +=
Add two vectors.
*/
void operator += (vec2&, vec2);

/*
Operator: -
Subtract two vectors.
*/
void operator -= (vec2&, vec2);

/*
Operator: *=
Modulate two vectors (component-wise multiplication).
*/
void operator *= (vec2&, vec2);

/*
Operator: /=
Divide two vectors component-wise.
*/
void operator /= (vec2&, vec2);

/*
Function: norm
Return the vector's magnitude.
*/
R norm (vec2 v);

/*
Function: norm2
Return the vector's squared magnitude.
*/
R norm2 (vec2 v);

/*
Function: normalise
Return the given vector divided by its magnitude.
*/
vec2 normalise (vec2 v);

// 3D vector

/*
Struct: vec3
A vector in 3D space.
*/
struct vec3
{
    /*
    Variable: x
    The x coordinate.
    */
    R x;

    /*
    Variable: y
    The y coordinate.
    */
    R y;

    /*
    Variable: z
    The z coordinate.
    */
    R z;

    /*
    Constructor: vec3
    Construct a vector and set it to the origin.
    */
    vec3 () : x (0), y (0), z (0) {}

    /*
    Constructor: vec3
    Construct a vector from the given coordinates.
    */
    vec3 (R _x, R _y, R _z)
        : x (_x), y (_y), z (_z) {}

    /*
    Constructor: vec3
    Construct a vector from the given value.

    The vector's coordinates are all set to the given value.
    */
    vec3 (R val) : x (val), y (val), z (val) {}

    /*
    Function: normalise
    Normalise the vector.
    */
    void normalise ();

    /*
    operator: const R*
    Return a const R pointer to the given vector's values.
    */
    operator const R* () const { return (R*) this; }
};

/*
Operator: -
Negate the given vector.
*/
vec3 operator- (vec3);

/*
Operator: +
Add two vectors.
*/
vec3 operator+ (vec3, vec3);

/*
Operator: -
Subtract two vectors.
*/
vec3 operator- (vec3, vec3);

/*
Operator: *
Modulate two vectors (component-wise multiplication).
*/
vec3 operator* (vec3, vec3);

/*
Operator: /
Divide two vectors component-wise.
*/
vec3 operator/ (vec3, vec3);

/*
Operator: +=
Add two vectors.
*/
void operator += (vec3&, vec3);

/*
Operator: -=
Subtract two vectors.
*/
void operator -= (vec3&, vec3);

/*
Operator: *=
Modulate two vectors (component-wise multiplication).
*/
void operator *= (vec3&, vec3);

/*
Operator: /=
Divide two vectors component-wise.
*/
void operator /= (vec3&, vec3);

/*
Function: norm
Return the vector's magnitude.
*/
R norm (vec3 v);

/*
Function: norm2
Return the vector's squared magnitude.
*/
R norm2 (vec3 v);

/*
Function: normalise
Return the given vector divided by its magnitude.
*/
vec3 normalise (vec3 v);

/*
Function: dot
Return given vectors' dot product.
*/
R dot (vec3 a, vec3 b);

/*
Function: cross
Return the given vectors' cross product.
*/
vec3 cross (vec3 a, vec3 b);

/*
Constant: right3
The (1, 0, 0) vector.
*/
const vec3 right3 = vec3 (1.0f, 0.0f, 0.0f);

/*
Constant: up3
The (0, 1, 0) vector.
*/
const vec3 up3 = vec3 (0.0f, 1.0f, 0.0f);

/*
Constant: forward3
The (0, 0, -1) vector.
*/
const vec3 forward3 = vec3 (0.0f, 0.0f, -1.0f);

/*
Constant: zero3
The (0, 0, 0) vector.
*/
const vec3 zero3 = vec3 (0.0f, 0.0f, 0.0f);

// 4D vector

/*
Struct: vec4
A vector in 4D space.
*/
struct vec4
{
    /*
    Variable: x
    The x coordinate.
    */
    R x;

    /*
    Variable: y
    The y coordinate.
    */
    R y;

    /*
    Variable: z
    The z coordinate.
    */
    R z;

    /*
    Variable: w
    The w coordinate.
    */
    R w;

    /*
    Constructor: vec4
    Construct a vector and set it to the origin.
    */
    vec4 () : x (0), y (0), z (0), w (0) {}

    /*
    Constructor: vec4
    Construct a vector from the given coordinates.
    */
    vec4 (R _x, R _y, R _z, R _w)
        : x (_x), y (_y), z (_z), w (_w) {}

    /*
    Constructor: vec4
    Construct a vector from the given value.

    The vector's coordinates are all set to the given value.
    */
    vec4 (R val) : x (val), y (val), z (val), w (val) {}

    /*
    Function: normalise
    Normalise the vector.
    */
    void normalise ();

    /*
    operator: const R*
    Return a const R pointer to the given vector's values.
    */
    operator const R* () const { return (R*) this; }
};

/*
Operator: -
Negate the given vector.
*/
vec4 operator- (vec4);

/*
Operator: +
Add two vectors.
*/
vec4 operator+ (vec4, vec4);

/*
Operator: -
Subtract two vectors.
*/
vec4 operator- (vec4, vec4);

/*
Operator: *
Modulate two vectors (component-wise multiplication).
*/
vec4 operator* (vec4, vec4);

/*
Operator: /
Divide two vectors component-wise.
*/
vec4 operator/ (vec4, vec4);

/*
Operator: +=
Add two vectors.
*/
void operator += (vec4&, vec4);

/*
Operator: -
Subtract two vectors.
*/
void operator -= (vec4&, vec4);

/*
Operator: *=
Modulate two vectors (component-wise multiplication).
*/
void operator *= (vec4&, vec4);

/*
Operator: /=
Divide two vectors component-wise.
*/
void operator /= (vec4&, vec4);

/*
Function: norm
Return the vector's magnitude.
*/
R norm (vec4 v);

/*
Function: norm2
Return the vector's squared magnitude.
*/
R norm2 (vec4 v);

// Quaternion

/*
Struct: quat
A quaternion.
*/
struct quat
{
    R w, x, y, z;

    quat () : w (1.0f), x (0.0f), y (0.0f), z (0.0f) {}

    quat (R _w, R _x, R _y, R _z)
        : w (_w), x (_x), y (_y), z (_z) {}
};

/*
Operator: *
Multiply two quaternions.
*/
quat operator* (quat q1, quat q2);

/*
Function: qrot
Construct the rotation quaternion.
*/
quat qrot (R angle, R x, R y, R z);

/*
Function: inv
Invert the quaternion.
*/
quat inv (quat q);

/*
Function: conj
Return the quaternion's conjugate.
*/
quat conj (quat q);

/*
Function: rot
Rotate the given vector by the given unit quaternion.
*/
vec3 rot (const quat& q, const vec3& v);

/*
Function: rot
Rotate the given vector by the given unit quaternion.
*/
void rot (const quat& q, vec3& v);

// Plane

/*
Struct: plane
A plane in 3D space.
*/
struct plane
{
    vec3 normal;
    R d;

    /*
    Constructor: plane
    Construct a new plane.

    Parameters:

    _normal : The plane's normal.
    _d : The perpendicular distance from the plane to the origin.
    */
    plane (const vec3& _normal, R _d)
#ifdef OGDT_AVOID_NORMALISATION
        : normal (_normal), d (_d) {}
#else
        : normal (normalise(_normal)), d (_d) {}
#endif
};

// Ray3

/*
Struct: ray3
A ray in 3D space.
*/
struct ray3
{
    vec3 pos;
    vec3 dir;

    /*
    Constructor: Ray
    Default constructor.
    */
    ray3 () {}

    /*
    Constructor: Ray
    Construct a ray.

    Parameters:

    _pos - The ray's position.
    _dir - The ray's direction.
    */
    ray3 (const vec3& _pos, const vec3& _dir)
#ifdef OGDT_AVOID_NORMALISATION
        : pos (_pos), dir (_dir) {}
#else
        : pos (_pos), dir (normalise(_dir)) {}
#endif

    /*
    Operator: ()
    Evaluate the ray equation.

    This function is defined as:

    ray(t) = ray.pos + ray.dir * t

    Parameters:

    t - The distance from the ray's position.
    */
    vec3 operator () (R t) const { return pos + dir * t; }
};

// AABB2

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

//
// AABB3
//

/*
Struct: AABB3
A 3D axis-aligned bounding box.
*/
struct AABB3
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

// Circle

/*
Struct: circle
*/
struct circle
{
    vec2  center;
    R radius2;

    /*
    Constructor: circle
    Construct a circle of radius 0 centered at the origin.
    */
    circle () : radius2 (0) {}

    /*
    Constructor: circle
    Construct a circle with the given center and radius.
    */
    circle (vec2 center, R radius);

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
    R radius () const;
};

// Sphere

/*
Struct: sphere
*/
struct sphere
{
    vec3  center;
    R radius2;

    /*
    Constructor: Sphere
    Construct a sphere of radius 0 centered at the origin.
    */
    sphere () : radius2 (0) {}

    /*
    Constructor: Sphere
    Construct a sphere with the given center and radius.
    */
    sphere (vec3 center, R radius);

    /*
    Function: add
    Update the sphere so that it includes the given point.

    The sphere is resized to contain the given point if it does not already contain it.
    */
    void add (vec3 p);

    /*
    Function: radius
    Return the sphere's radius.
    */
    R radius () const;
};

// 3x3 matrix

/*
Class: mat3
A column-major 3x3 matrix.
*/
class mat3
{
    R val[3][3];

public:

    /*
    Constructor: mat3
    Construct a matrix and set it to the identity.
    */
    mat3 ();

    /*
    Constructor: mat3
    Construct a matrix from the given values.
    */
    mat3 (R m00, R m10, R m20,
          R m01, R m11, R m21,
          R m02, R m12, R m22);

    /*
    Constructor: mat3
    Construct a matrix from the given vectors.

    Each of the vectors represents a column of the matrix.
    */
    mat3 (const vec3& v0,
          const vec3& v1,
          const vec3& v2);

    /*
    Constructor: mat3
    Construct a transformation matrix from the given vectors.
    */
    mat3 (const vec2& right, const vec2& up, const vec2& position);

    /*
    Operator: ()
    Return a mutable reference to the value at the specified position.
    */
    R& operator () (int row, int col);

    /*
    Operator: ()
    Access the value at the specified position.
    */
    R operator() (int row, int col) const;

    /*
    Function: v0
    Return a mutable reference to the matrix's first column.
    */
    vec2& v0 ();

    /*
    Function: v1
    Return a mutable reference to the matrix's second column.
    */
    vec2& v1 ();

    /*
    Function: v2
    Return a mutable reference to the matrix's third column.
    */
    vec2& v2 ();

    /*
    Function: v0
    Return the matrix's first column.
    */
    const vec2& v0 () const;

    /*
    Function: v1
    Return the matrix's second column.
    */
    const vec2& v1 () const;

    /*
    Function: v2
    Return the matrix's third column.
    */
    const vec2& v2 () const;

    /*
    Operator: *
    Multiply two matrices.
    */
    mat3 operator* (const mat3&);

    /*
    Operator: *=
    Multiply two matrices and accumulate the result in the first operand.
    */
    void operator*= (const mat3&);

    /*
    Operator: const R*
    Return a const R pointer to the matrix's data.
    */
    operator const R* () const { return (R*) val; }

    /*
    Function: transl
    Return the translation component of the matrix.
    */
    mat3 transl () const;

    /*
    Function: rot
    Return the rotation component of the matrix.
    */
    mat3 rot () const;

    /*
    Function: rot
    Create a rotation matrix.

    Parmeters:

    angle - The angle of rotation in degrees.
    */
    static mat3 rot (R angle);

    /*
    Function: scale
    Create a scale matrix.

    Parameters:

    s - A vector specifying the scale factor on each axis.
    */
    static mat3 scale (vec3 s);

    /*
    Function: scale
    Create a scale matrix.

    Parameters:

    sx - The scale factor on the X axis.
    sy - The scale factor on the Y axis.
    sz - The scale factor on the Z axis.
    */
    static mat3 scale (R x, R y, R z);

    /*
    Function: transl
    Create a translation matrix.

    Parameters:

    offset - A vector specifying the translation along each axis.
    */
    static mat3 transl (vec2 offset);

    /*
    Function: transl
    Create a translation matrix.

    Parameters:

    x - The amount of translation along the X axis.
    y - The amount of translation along the Y axis.
    */
    static mat3 transl (R x, R y);

    /*
    Constant: reflectx
    The X-axis reflection matrix.
    */
    static const mat3 reflectx;

    /*
    Constant: reflecty
    The Y-axis reflection matrix.
    */
    static const mat3 reflecty;

    /*
    Constant: reflectz
    The Z-axis reflection matrix.
    */
    static const mat3 reflectz;

    /*
    Constant: id
    The identity matrix.
    */
    static const mat3 id;
};

mat3 inverse (const mat3&);

mat3 transpose (const mat3&);

vec3 operator* (const mat3&, vec3);

// 4x4 matrix

/*
Class: mat4
A 4x4 column-major matrix.
*/
class mat4
{
    R val[4][4];

public:

    /*
    Constructor: mat4
    Construct a matrix and set it to the identity.
    */
    mat4 ();

    /*
    Constructor: mat4
    Construct a matrix from the given values.
    */
    mat4 (R m00, R m10, R m20, R m30,
          R m01, R m11, R m21, R m31,
          R m02, R m12, R m22, R m32,
          R m03, R m13, R m23, R m33);

    /*
    Constructor: mat4
    Construct a matrix from the given vectors.

    Each of the vectors represents a column of the matrix.
    */
    mat4 (const vec4& v0,
          const vec4& v1,
          const vec4& v2,
          const vec4& v3);

    /*
    Constructor: mat4
    Construct a transformation matrix from the given vectors.
    */
    mat4 (const vec3& right, const vec3& up, const vec3& forward, const vec3& position);

    /*
    Operator: ()
    Return a mutable reference to the value at the specified position.
    */
    R& operator () (int row, int col);

    /*
    Operator: ()
    Access the value at the specified position.
    */
    R operator() (int row, int col) const;

    /*
    Function: v0
    Return a mutable reference to the matrix's first column.
    */
    vec3& v0 ();

    /*
    Function: v1
    Return a mutable reference to the matrix's second column.
    */
    vec3& v1 ();

    /*
    Function: v2
    Return a mutable reference to the matrix's third column.
    */
    vec3& v2 ();

    /*
    Function: v3
    Return a mutable reference to the matrix's fourth column.
    */
    vec3& v3 ();

    /*
    Function: v0
    Return the matrix's first column.
    */
    const vec3& v0 () const;

    /*
    Function: v1
    Return the matrix's second column.
    */
    const vec3& v1 () const;

    /*
    Function: v2
    Return the matrix's third column.
    */
    const vec3& v2 () const;

    /*
    Function: v3
    Return an immutable reference to the matrix's fourth column.
    */
    const vec3& v3 () const;

    /*
    Operator: *
    Multiply two matrices.
    */
    mat4 operator* (const mat4&);

    /*
    Operator: *=
    Multiply two matrices and accumulate the result in the first operand.
    */
    void operator*= (const mat4&);

    /*
    Operator: const R*
    Return a const R pointer to the matrix's data.
    */
    operator const R* () const { return (R*) val; }

    /*
    Function: transl
    Return the translation component of the matrix.
    */
    mat4 transl () const;

    /*
    Function: rot
    Return the rotation component of the matrix.
    */
    mat4 rot () const;

    /*
    Function: to33
    Return the upper 3x3 portion of the matrix.
    */
    mat3 to33 () const;

    /*
    Function: rotx
    Create an X-axis rotation matrix.

    Parmeters:

    angle - The angle of rotation in degrees.
    */
    static mat4 rotx (R angle);

    /*
    Function: roty
    Create a Y-axis rotation matrix.

    Parmeters:

    angle - The angle of rotation in degrees.
    */
    static mat4 roty (R angle);

    /*
    Function: rotz
    Create a Z-axis rotation matrix.

    Parmeters:

    angle - The angle of rotation in degrees.
    */
    static mat4 rotz (R angle);

    /*
    Function: rot
    Create a rotation matrix.

    Parmeters:

    angle - The angle of rotation in degrees.
    axis  - The axis of rotation.
    */
    static mat4 rot (R angle, const vec3& axis);

    /*
    Function: rot
    Create a rotation matrix.

    angle - The angle of rotation in degrees.
    x - X component of the axis of rotation.
    y - Y component of the axis of rotation.
    z - Z component of the axis of rotation.
    */
    static mat4 rot (R angle, R x, R y, R z);

    /*
    Function: scale
    Create a scale matrix.

    Parameters:

    s - A vector specifying the scale factor on each axis.
    */
    static mat4 scale (const vec3& s);

    /*
    Function: scale
    Create a scale matrix.

    Parameters:

    sx - The scale factor on the X axis.
    sy - The scale factor on the Y axis.
    sz - The scale factor on the Z axis.
    */
    static mat4 scale (R sx, R sy, R sz);

    /*
    Function: transl
    Create a translation matrix.

    Parameters:

    offset - A vector specifying the translation along each axis.
    */
    static mat4 transl (const vec3& offset);

    /*
    Function: transl
    Create a translation matrix.

    Parameters:

    x - The amount of translation along the X axis.
    y - The amount of translation along the Y axis.
    z - The amount of translation along the Z axis.
    */
    static mat4 transl (R x, R y, R z);

    /*
    Constant: reflectx
    The X-axis reflection matrix.
    */
    static const mat4 reflectx;

    /*
    Constant: reflecty
    The Y-axis reflection matrix.
    */
    static const mat4 reflecty;

    /*
    Constant: reflectz
    The Z-axis reflection matrix.
    */
    static const mat4 reflectz;

    /*
    Constant: id
    The identity matrix.
    */
    static const mat4 id;

    /*
    Function: transform
    Create a transformation matrix from the given forward vector.
    */
    static mat4 transform (vec3 forward);

    /*
    Function: lookAt
    Create a transformation matrix.

    Parameters:

    position - The object's position.
    target - The point the object is looking at.
    */
    static mat4 lookAt (const vec3& position, const vec3& target);

    /*
    Function: ortho
    Create an orthographic projection matrix.

    Parameters:

    left - The coordinate for the left vertical clipping plane.
    right - The coordinate for the right vertical clipping plane.
    bottom - The coordinate for the bottom horizontal clipping plane.
    top - The coordinate for the top horizontal clipping plane.
    near - The distance to the near clipping plane.
    far - The distance to the far clipping plane.
    */
    static mat4 ortho (R left, R right, R bottom, R top, R near, R far);

    /*
    Function: perspective
    Create a perspective projection matrix.

    Parameters:

    fovy - The vertical field of view angle in degrees.
    aspect - The aspect ratio that determines the field of view in the x-direction.
    near - Distance to the near clipping plane.
    far - Distance to the far clipping plane.
    */
    static mat4 perspective (R fovy, R aspect, R near, R far);
};

mat4 inverse (const mat4& m);

mat4 inverse_transform (const mat4& m);

mat4 transpose (const mat4& m);

vec3 transform (const mat4&, vec3, R w);

// Spatial

/*
Class: Spatial
An object in 3D space.
*/
class Spatial
{
    vec3 r;
    vec3 u;
    vec3 f;
    vec3 p;

public:

    /*
    Constructor: Spatial
    Construct a spatial.
    */
    Spatial ();

    /*
    Constructor: Spatial
    Construct a spatial.

    Parameters:

    position - The spatial's position.
    target - The point where the spatial is look at.
    */
    Spatial (const vec3& position, const vec3& target);

    /*
    Destructor: ~Spatial
    */
    virtual ~Spatial() {}

    /*
    Function: move
    Displace the spatial by the given vector.
    */
    void move (const vec3 &direction);

    /*
    Function: moveForwards
    Move the spatial along its local forward vector.
    */
    void moveForwards (R speed);

    /*
    Function: moveBackwards
    Move the spatial along its local backwards vector.
    */
    void moveBackwards (R speed);

    /*
    Function: strafeLeft
    Move the spatial along its local left vector.
    */
    void strafeLeft (R speed);

    /*
    Function: strafeRight
    Move the spatial along its local right vector.
    */
    void strafeRight (R speed);

    /*
    Function: moveUp
    Move the spatial along the global up vector.
    */
    void moveUp (R speed);

    /*
    Function: moveDown
    Move the spatial along the global down vector.
    */
    void moveDown (R speed);

    /*
    Function: rotate
    Rotate the spatial about the given axis in world space.

    Parameters:

    angle - The angle of rotation in degrees.
    x - The x coordinate of the axis of rotation.
    y - The y coordinate of the axis of rotation.
    z - The z coordinate of the axis of rotation.
    */
    void rotate (R angle, R x, R y, R z);

    /*
    Function: rotate
    Rotate the spatial about the given axis in world space.

    Parameters:

    angle - The angle of rotation in degrees.
    axis - The axis of rotation.
    */
    void rotate (R angle, vec3 axis) { rotate (angle, axis.x, axis.y, axis.z); }

    /*
    Function: yaw
    Rotate the spatial about its local y axis.

    Parameters:

    angle - The angle of rotation in degrees.
    */
    void yaw (const R angle);

    /*
    Function: pitch
    Rotate the spatial about its local x axis.

    Parameters:

    angle - The angle of rotation in degrees.
    */
    void pitch (const R angle);

    /*
    Function: roll
    Rotate the spatial about its local z axis.

    Parameters:

    angle - The angle of rotation in degrees.
    */
    void roll (const R angle);

    /*
    Function: setPosition
    Set the spatial's position.
    */
    void setPosition (R x, R y, R z);

    /*
    Function: setPosition
    Set the spatial's position.
    */
    void setPosition (const vec3 &v);

    /*
    Function: setForward
    Set the spatial's forward vector.
    */
    void setForward (R x, R y, R z);

    /*
    Function: setForward
    Set the spatial's forward vector.
    */
    void setForward (vec3 forward);

    /*
    Function: setTransform
    Set the spatial's transformation matrix.
    */
    void setTransform (const mat4& transform);

    /*
    Function: lookAt
    Make the spatial look at the given target.
    */
    void lookAt (R x, R y, R z);

    /*
    Function: lookAt
    Make the spatial look at the given target.
    */
    void lookAt (const vec3& target);

    /*
    Function: lookAt
    Make the spatial look at the given target.
    */
    void lookAt (const Spatial&);

    /*
    Function: orbit
    Make the spatial orbit around the given target.

    Parameters:

    x - Target x coordinate.
    y - Target y coordinate.
    z - Target z coordinate.
    radius - Radial distance.
    azimuth - Azimuthal (horizontal) angle.
    zenith - Polar (vertical) angle.
    */
    void orbit (R x, R y, R z, R radius, R azimuth, R zenith);

    /*
    Function: orbit
    Make the spatial orbit around the given target.

    Parameters:

    target - Target position.
    radius - Radial distance.
    azimuth - Azimuthal (horizontal) angle.
    zenith - Polar (vertical) angle.
    */
    void orbit (const vec3& target, R radius, R azimuth, R zenith);

    /*
    Function: orbit
    Make the spatial orbit around the given target.

    Parameters:

    target - Target spatial.
    radius - Radial distance.
    azimuth - Azimuthal (horizontal) angle.
    zenith - Polar (vertical) angle.
    */
    void orbit (const Spatial& target, R radius, R azimuth, R zenith);

    /*
    Function: pos
    Return the spatial's position.
    */
    const vec3& pos () const;

    /*
    Function: fwd
    Return the spatial's forward vector.
    */
    const vec3& fwd () const;

    /*
    Function: right
    Return the spatial's right vector.
    */
    const vec3& right () const;

    /*
    Function: up
    Return the spatial's up vector.
    */
    const vec3& up () const;

    /*
    Function: transform
    Return the spatial's transformation matrix (from spatial to world coordinates).
    */
    mat4 transform () const;

    /*
    Function: inverseTransform
    Return the spatial's inverse transformation matrix (from world to spatial coordinates).
    */
    mat4 inverseTransform () const;
};

// Camera

/*
Class: Camera
A camera.
*/
class Camera : public Spatial
{
public:

    /*
    Function: projection
    Return the camera's projection matrix.
    */
    virtual mat4 projection () const = 0;
};

/*
Class: PerspectiveCamera
A perspective projection camera.
*/
class PerspectiveCamera : public Camera
{
public:

    /*
    Property: fovy
    Vertical field of view angle.
    */
    R fovy;
    
    /*
    Property: aspect
    Aspect ratio.
    */
    R aspect;
    
    /*
    Property: near
    Near plane.
    */
    R near;
    
    /*
    Property: aspect
    Far plane.
    */
    R far;
    
    /*
    Constructor: PerspectiveCamera
    Construct a perspective camera.
    */
    PerspectiveCamera ();
    
    /*
    Constructor: PerspectiveCamera
    Construct a perspective camera.
    
    Parameters:
    
    fovy - Vertical field of view angle.
    aspect - Aspect ratio.
    near - Near plane.
    far - Far plane.
    */
    PerspectiveCamera (R fovy, R aspect, R near, R far);
    
    mat4 projection () const;
};

// Utils

/*
Section: Utils
Various utility functions and constants.
*/

/*
Function: R_eq
Compare two Rs for equality.

This function first tests a and b for equality: a == b.
If the plain equality test fails, the function checks if one of a or b is 0.
In that case, the function performs a comparison using an absolute error,
where the error is given by eps: |a-b| <= eps.
Otherwise an ULP comparison is made, where the maximum ULP distance is given by
the ULPs parameter: ULP (a-b) <= ULPs.

Parameters:

eps - The error used in the absolute comparison.
ULPs - The maximum ULP distance used in the ULP comparison.

Returns:

True if the given Rs are equal, false otherwise.
*/
bool R_eq (R a, R b, R eps, int ULPs);

/*
Constant: TO_RAD
Convert degrees to radians.
*/
const R TO_RAD = M_PI / 180.0;

/*
Constat: TO_DEG
Convert radians to degrees.
*/
const R TO_DEG = 180.0 / M_PI;

/*
Function: qmat3
Construct a 3x3 matrix representing the same rotation as the given quaternion.
*/
mat3 qmat3 (const quat& q);

/*
Function: qmat3
Construct a 4x4 matrix representing the same rotation as the given quaternion.
*/
mat4 qmat4 (const quat& q);

/*
Function: sign
Return the sign of the given value.
*/
R sign (R x);

/*
Function: pitch_from_fwd
Return the pitch formed by the given forward vector.
*/
R pitch_from_fwd (vec3 forward);

/*
Function: yaw_from_fwd
Return the yaw formed by the given forward vector.
*/
R yaw_from_fwd (vec3 forward);

} // namespace OGDT
