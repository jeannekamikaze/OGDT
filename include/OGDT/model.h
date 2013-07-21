#pragma once

/*
Header: model
*/

namespace OGDT
{

/*
Struct: Animation
A model animation.
*/
struct Animation
{
    /*
    Variable: name
    The animation's name.
    */
    const char* name;

    /*
    Variable: duration
    The animation's duration in seconds.
    */
    float duration;

    /*
    Variable: id
    The animation's id.
    */
    const unsigned id;

    Animation (const char* _name, float d, const unsigned _id)
        : name (_name), duration (d), id (_id) {}
};

/*
 * Class: Model
 * A static or animated 3D model.
 */
class Model
{
    struct _impl;
    _impl* impl;

    Model (const Model&);
    Model& operator= (const Model&);

public:

    /*
     * Constructor: Model
     * Load a model from the specified file path.
     */
    Model (const char* path);

    ~Model ();

    /*
     * Function: render
     * Render the model.
     *
     * Parameters:
     *
     * t - Animation time.
     * anim - Animation to display.
     */
    void render (float t = 0.0f, const Animation* anim = nullptr) const;

    /*
     * Function: isAnimated
     * Return true if the model is animated, false otherwise.
     */
    bool isAnimated () const;

    /*
     * Function: getAnimation
     * Return the animation specified by the given name if it exists, null otherwise.
     */
    const Animation* getAnimation (const char* name) const;

    /*
     * Function: scale
     * Scale the model.
     *
     * Parameters:
     *
     * sx - Scaling along the x axis.
     * sy - Scaling along the y axis.
     * sz - Scaling along the z axis.
     */
    void scale (float sx, float sy, float sz);

    /*
     * Function: pitch
     * Rotate the model about the X axis.
     *
     * Parameters:
     *
     * angle - Angle of rotation in degrees.
     */
    void pitch (float angle);

    /*
     * Function: yaw
     * Rotate the model about the Y axis.
     *
     * Parameters:
     *
     * angle - Angle of rotation in degrees.
     */
    void yaw (float angle);

    /*
     * Function: roll
     * Rotate the model about the Z axis.
     *
     * Parameters:
     *
     * angle - Angle of rotation in degrees.
     */
    void roll (float angle);

    /*
     * Function: toGround
     * Translate the model so that its lowest point has y=0.
     */
    void toGround ();

    /*
     * Function: computeAABB
     * Compute the AABB of the given animation's frames.
     */
    void computeAABB (const char* anim, float& xmin, float& xmax, float& ymin, float& ymax, float& zmin, float& zmax) const;

    /*
     * Function: computeAABB
     * Compute the given frame's AABB.
     */
    void computeAABB (float& xmin, float& xmax, float& ymin, float& ymax, float& zmin, float& zmax, unsigned frame = 0) const;
};

/*
 * Class: ModelInstance
 * A Model instance.
 */
class ModelInstance
{
    struct _impl;
    _impl* impl;

    ModelInstance (const ModelInstance&);
    ModelInstance& operator= (const ModelInstance&);

public:

    /*
     * Constructor: ModelInstance
     * Construct a model instance from the given model.
     */
    ModelInstance (const Model&);

    ~ModelInstance ();

    /*
     * Function: update
     * Update the animation state.
     */
    void update (float dt);

    /*
     * Function: setAnimation
     * Set the current animation to the one specified by the given name.
     *
     * Parameters:
     *
     * name - The animation to play.
     * loop - Whether the animation should play in a loop.
     */
    void setAnimation (const char* name, bool loop = true);

    /*
     * Function: getAnimation
     * Get the current animation's name, or an empty string if no animation is being played.
     */
    const char* getAnimation () const;

    /*
    Function: setAnimationSpeed
    Sets the animation speed.
    */
    void setAnimationSpeed (float speed);

    /*
     * Function: isAnimationDone
     * Return true if the current animation is done.
     *
     * This returns false if no animation is being played.
     *
     * If an animation is set to loop it is never considered done.
     */
    bool isAnimationDone () const;

    /*
     * Function: isAnimated
     * Return true if the underlying model is animated, false otherwise.
     */
    bool isAnimated () const;

    /*
     * Function: render
     * Render the model.
     */
    void render () const;
};

} // namespace OGDT
