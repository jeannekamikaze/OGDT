#pragma once

#include <OGDT/OGDT.h>
#include <OGDT/Input.h>

namespace OGDT
{

/*
Class: Application
*/
class DECLDIR Application
{
	struct _impl;
	_impl* impl;

	Application (const Application&);
	Application& operator= (const Application&);

	void terminate ();

public:

	Application ();

	virtual ~Application ();

	/*
	Function: start
	Start the application.

	Parameters:

	width - Window width.
	height - Window height.
	fullscreen - Whether the application should run in fullscreen mode.
	*/
	void setup (int width, int height, const char* title = "OGDT Application", bool fullscreen = false);

	/*
	Function: run
	Enter the application's main loop.
	*/
	void run ();

	/*
	Function: runCapped
	Enter the application's main loop, with a cap on the frame rate.

	Parameters:

	max_fps - The desired frame rate.
	*/
	void runCapped (int max_fps);

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
	Function: setCursorVisible
	Set the mouse cursor visible on visible.
	*/
	void setCursorVisible (bool val);

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
	Function: onKey
	Called on a key event.
	*/
	virtual void onKey (Input::code key, bool pressed) {}

protected:

	/*
	Function: onInit
	Called during initialisation.
	*/
	virtual void onInit () {}

	/*
	Function: onQuit
	Called on exit.
	*/
	virtual void onQuit () {}

	/*
	Function: update
	Called every frame.

	Parameters:

	dt - The time elapsed since the last frame, in seconds.
	*/
	virtual void update (float dt) {}
};

} // namespace OGDT
