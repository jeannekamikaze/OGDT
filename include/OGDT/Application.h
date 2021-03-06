#pragma once

#include <OGDT/Input.h>

namespace OGDT
{

/*
Class: Application
*/
class Application
{
    struct _impl;
    _impl* impl;

    Application (const Application&);
    Application& operator= (const Application&);

public:

    /*
    Constructor: Application
    Create a new application.

    Parameters:

    width - Window width.
    height - Window height.
    major - Desired OpenGL context major version.
    minor - Desired OpenGL context minor version.
    fullscreen - Whether the application should run in fullscreen mode.
    */
    Application (int width = 640,
                 int height = 480,
                 const char* title = "OGDT Application",
                 int major = 1,
                 int minor = 1,
                 bool fullscreen = false);

    virtual ~Application ();

    /*
    Function: run
    Enter the application's main loop.
    */
    void run ();

    /*
    Function: run
    Enter the application's main loop, with a cap on the frame rate.

    Parameters:

    max_fps - The desired frame rate.
    */
    void run (int max_fps);

    /*
    Function: quit
    Quit the application.
    */
    void quit ();

    /*
    Function: swapBuffers
    Swap OpenGL buffers.
    */
    void swapBuffers ();

    /*
    Function: pollInput
    Poll input devices.
    */
    void pollInput ();

    /*
    Function: setAutoPollInput
    Set whether the input should be automatically polled.
    */
    void setAutoPollInput (bool val);
    
    /*
    Function: setAutoSwapBuffers
    Set whether buffers should be automatically swapped at the end of onUpdate.
    */
    void setAutoSwapBuffers (bool val);

    /*
    Function: setCursorVisible
    Set the mouse cursor visible on visible.
    */
    void setCursorVisible (bool val);
    
    /*
    Function: setMouseAutoCenter
    Set the mouse position to the center of the window every frame.
    */
    void setMouseAutoCenter (bool val);

    /*
    Function: setKeyRepeat
    Enable or disable key repeat.

    When key repeat is enabled, the onKey callback function is called
    repeatedly when the a key is held long enough, according to system
    settings.

    When key repeat is disabled, the onKey callback function is called
    just once for every press and for every release.
    */
    void setKeyRepeat (bool val);

    /*
    Function: getInput
    Return the input system.
    */
    Input& getInput ();

    /*
    Function: getInput
    Return the input system.
    */
    const Input& getInput () const;

    /*
    Function: isRunning
    Return true if the application is running, false otherwise.
    */
    bool isRunning () const;

    /*
    Function: onResize
    Called on a window resize.

    Parameters:

    width - New window width.
    height - New window height.
    */
    virtual void onResize (int width, int height) {}

    /*
    Function: onMouseButton
    Called on a mouse button event.
    */
    virtual void onMouseButton (Input::code button, bool pressed) {}

    /*
    Function: onMouseMove
    Called on a mouse move event.
    */
    virtual void onMouseMove (int x, int y) {}

    /*
    Function: onMouseWheel
    Called on a mouse wheel event.
    */
    virtual void onMouseWheel (int pos) {}

    /*
    Function: onKey
    Called on a key event.
    */
    virtual void onKey (Input::code key, bool pressed) {}

protected:

    /*
    Function: update
    Called every frame.

    Parameters:

    dt - The time elapsed since the last frame, in seconds.
    */
    virtual void onUpdate (float dt) {}
};

} // namespace OGDT
