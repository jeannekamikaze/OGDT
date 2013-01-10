#pragma once

#include <OGDT/OGDT.h>
#include <OGDT/math/mat4.h>
#include <OGDT/math/vec3.h>

namespace OGDT
{

/*
Class: Spatial
An object in 3D space.
*/
class DECLDIR Spatial
{
    vec3 r;
    vec3 u;
    vec3 f;
    vec3 p;
    
public:
    
    /*
    Constructor: Spatial
    Create a spatial.
    */
    Spatial ();
    
    /*
    Constructor: Spatial
    Create a spatial.

    Parameters:

    position - The spatial's position.
    target - The point where the spatial is look at.
    */
    Spatial (const vec3& position, const vec3& target);
    
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
    void moveForwards (float speed);
    
    /*
    Function: moveBackwards
    Move the spatial along its local backwards vector.
    */
    void moveBackwards (float speed);
    
    /*
    Function: strafeLeft
    Move the spatial along its local left vector.
    */
    void strafeLeft (float speed);
    
    /*
    Function: strafeRight
    Move the spatial along its local right vector.
    */
    void strafeRight (float speed);
    
    /*
    Function: moveUp
    Move the spatial along the global up vector.
    */
    void moveUp (float speed);
    
    /*
    Function: moveDown
    Move the spatial along the global down vector.
    */
    void moveDown (float speed);
    
    /*
    Function: rotate
    Rotate the spatial about the given axis in world space.
    
    Parameters:

    angle - The angle of rotation in degrees.
    x - The x coordinate of the axis of rotation.
    y - The y coordinate of the axis of rotation.
    z - The z coordinate of the axis of rotation.
    */
    void rotate (float angle, float x, float y, float z);
    
    /*
    Function: rotate
    Rotate the spatial about the given axis in world space.
    
    Parameters:

    angle - The angle of rotation in degrees.
    axis - The axis of rotation.
    */
    void rotate (float angle, vec3 axis) { rotate (angle, axis.x, axis.y, axis.z); }
    
    /*
    Function: yaw
    Rotate the spatial about its local y axis.

    Parameters:
    
    angle - The angle of rotation in degrees.
    */
    void yaw (const float angle);
    
    /*
    Function: pitch
    Rotate the spatial about its local x axis.

    Parameters:
    
    angle - The angle of rotation in degrees.
    */
    void pitch (const float angle);
    
    /*
    Function: roll
    Rotate the spatial about its local z axis.

    Parameters:
    
    angle - The angle of rotation in degrees.
    */
    void roll (const float angle);
    
    /*
    Function: setPosition
    Set the spatial's position.
    */
    void setPosition (float x, float y, float z);
    
    /*
    Function: setPosition
    Set the spatial's position.
    */
    void setPosition (const vec3 &v);
    
    /*
    Function: setForward
    Set the spatial's forward vector.
    */
    void setForward (float x, float y, float z);
    
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
    void lookAt (float x, float y, float z);
    
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
    void orbit (float x, float y, float z, float radius, float azimuth, float zenith);

    /*
    Function: orbit
    Make the spatial orbit around the given target.

    Parameters:

    target - Target position.
    radius - Radial distance.
    azimuth - Azimuthal (horizontal) angle.
    zenith - Polar (vertical) angle.
    */
    void orbit (const vec3& target, float radius, float azimuth, float zenith);

    /*
    Function: orbit
    Make the spatial orbit around the given target.

    Parameters:

    target - Target spatial.
    radius - Radial distance.
    azimuth - Azimuthal (horizontal) angle.
    zenith - Polar (vertical) angle.
    */
    void orbit (const Spatial& target, float radius, float azimuth, float zenith);
    
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

} // namespace OGDT
