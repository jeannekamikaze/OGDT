#pragma once

#include <OGDT/OGDT.h>

namespace OGDT
{

class Model;

/*
 * Class: ModelInstance
 * A Model instance.
 */
class DECLDIR ModelInstance
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
