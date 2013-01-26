#include <OGDT/Application.h>
#include <OGDT/Exception.h>
#include <OGDT/gl.h>
#include <OGDT/Timer.h>
#include <GL/glfw.h>


using namespace OGDT;


struct Application::_impl
{
    Input input;
    bool running;
    bool auto_poll;

    _impl () : running (false), auto_poll (true)
    {
    }
};


static Application* app = 0;

Input::code from_glfw (int c);


void GLFWCALL onResize (int width, int height)
{
    app->onResize (width, height);
}


void GLFWCALL onMouseButton (int button, int action)
{
    app->onMouseButton (from_glfw(button), action == GLFW_PRESS);
}


void GLFWCALL onMouseMove (int x, int y)
{
    app->onMouseMove (x, y);
}


void GLFWCALL onMouseWheel (int pos)
{
    app->onMouseWheel (pos);
}


void GLFWCALL onKey (int key, int action)
{
    app->onKey (from_glfw(key), action == GLFW_PRESS);
}


Application::Application (int width, int height, const char* title, int major, int minor, bool fullscreen)
  : impl (new _impl)
{
    if (!glfwInit()) throw EXCEPTION ("Failed initialising GLFW");
    int mode = fullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW;
    glfwOpenWindowHint (GLFW_VERSION_MAJOR, major);
    glfwOpenWindowHint (GLFW_VERSION_MINOR, minor);
    if (!glfwOpenWindow (width, height, 0, 0, 0, 0, 0, 0, mode))
    {
        glfwTerminate ();
        throw EXCEPTION ("glfwOpenWindow failed");
    }
    glewInit ();
    ::app = this;
    glfwSetWindowTitle (title);
    glfwSetWindowSizeCallback (::onResize);
    glfwSetMouseButtonCallback (::onMouseButton);
    glfwSetMousePosCallback (::onMouseMove);
    glfwSetMouseWheelCallback (::onMouseWheel);
    glfwSetKeyCallback (::onKey);
    glfwDisable (GLFW_AUTO_POLL_EVENTS);
}


Application::~Application ()
{
    if (glfwGetWindowParam (GLFW_OPENED)) glfwCloseWindow ();
    glfwTerminate ();
    delete impl;
}


void Application::quit ()
{
    impl->running = false;
}


void Application::run ()
{
    bool& running = impl->running;

    if (running) return;
    running = true;

    // Trigger an initial resize for ease of use.
    int width, height;
    glfwGetWindowSize (&width, &height);
    onResize (width, height);

    Timer t;
    t.start ();

    while (running)
    {
        t.tick ();
        float dt = t.getDelta();
        if (impl->auto_poll) impl->input.poll();
        update (dt);
        running = running && glfwGetWindowParam (GLFW_OPENED);
    }
}


void Application::runCapped (int max_fps)
{
    bool& running = impl->running;

    if (running) return;
    running = true;

    // Trigger an initial resize for ease of use.
    int width, height;
    glfwGetWindowSize (&width, &height);
    onResize (width, height);

    float desired_frame_time = 1.0f / (float) max_fps;

    Timer frame;
    Timer control;

    frame.start ();
    control.start ();

    while (running)
    {
        frame.tick ();
        float dt = frame.getDelta ();

        control.tick ();
        if (impl->auto_poll) impl->input.poll();
        update (dt);
        running = running && glfwGetWindowParam (GLFW_OPENED);
        control.tick ();

        float frame_time = control.getDelta ();
        if (frame_time < desired_frame_time) timer_sleep (desired_frame_time - frame_time);
    }
}


void Application::swapBuffers ()
{
    glfwSwapBuffers ();
}


void Application::pollInput ()
{
    impl->input.poll ();
}


void Application::setAutoPollInput (bool val)
{
    impl->auto_poll = val;
}


void Application::setCursorVisible (bool val)
{
    if (val) glfwEnable  (GLFW_MOUSE_CURSOR);
    else     glfwDisable (GLFW_MOUSE_CURSOR);
}


void Application::setKeyRepeat (bool val)
{
    if (val) glfwEnable  (GLFW_KEY_REPEAT);
    else     glfwDisable (GLFW_KEY_REPEAT);
}


Input& Application::getInput ()
{
    return impl->input;
}


const Input& Application::getInput () const
{
    return impl->input;
}


bool Application::isRunning () const
{
    return impl->running;
}


Input::code from_glfw (int c)
{
    switch (c)
    {
    case GLFW_MOUSE_BUTTON_LEFT:   return Input::LMB; break;
    case GLFW_MOUSE_BUTTON_RIGHT:  return Input::RMB; break;
    case GLFW_MOUSE_BUTTON_MIDDLE: return Input::MMB; break;
    case GLFW_KEY_SPACE:       return Input::Space; break;
    case GLFW_KEY_ESC:         return Input::Esc; break;
    case GLFW_KEY_F1:          return Input::F1; break;;
    case GLFW_KEY_F2:          return Input::F2; break;;
    case GLFW_KEY_F3:          return Input::F3; break;;
    case GLFW_KEY_F4:          return Input::F4; break;;
    case GLFW_KEY_F5:          return Input::F5; break;;
    case GLFW_KEY_F6:          return Input::F6; break;;
    case GLFW_KEY_F7:          return Input::F7; break;;
    case GLFW_KEY_F8:          return Input::F8; break;;
    case GLFW_KEY_F9:          return Input::F9; break;;
    case GLFW_KEY_F10:         return Input::F10; break;;
    case GLFW_KEY_F11:         return Input::F11; break;;
    case GLFW_KEY_F12:         return Input::F12; break;;
    case GLFW_KEY_F13:         return Input::F13; break;;
    case GLFW_KEY_F14:         return Input::F14; break;;
    case GLFW_KEY_F15:         return Input::F15; break;;
    case GLFW_KEY_F16:         return Input::F16; break;;
    case GLFW_KEY_F17:         return Input::F17; break;;
    case GLFW_KEY_F18:         return Input::F18; break;;
    case GLFW_KEY_F19:         return Input::F19; break;;
    case GLFW_KEY_F20:         return Input::F20; break;;
    case GLFW_KEY_F21:         return Input::F21; break;;
    case GLFW_KEY_F22:         return Input::F22; break;;
    case GLFW_KEY_F23:         return Input::F23; break;;
    case GLFW_KEY_F24:         return Input::F24; break;;
    case GLFW_KEY_F25:         return Input::F25; break;;
    case GLFW_KEY_UP:          return Input::Up; break;;
    case GLFW_KEY_DOWN:        return Input::Down; break;;
    case GLFW_KEY_LEFT:        return Input::Left; break;;
    case GLFW_KEY_RIGHT:       return Input::Right; break;;
    case GLFW_KEY_LSHIFT:      return Input::LShift; break;;
    case GLFW_KEY_RSHIFT:      return Input::RShift; break;;
    case GLFW_KEY_LCTRL:       return Input::LCtrl; break;;
    case GLFW_KEY_RCTRL:       return Input::RCtrl; break;;
    case GLFW_KEY_LALT:        return Input::LAlt; break;;
    case GLFW_KEY_RALT:        return Input::RAlt; break;;
    case GLFW_KEY_LSUPER:      return Input::LSuper; break;;
    case GLFW_KEY_RSUPER:      return Input::RSuper; break;;
    case GLFW_KEY_TAB:         return Input::Tab; break;;
    case GLFW_KEY_ENTER:       return Input::Enter; break;;
    case GLFW_KEY_BACKSPACE:   return Input::Backspace; break;;
    case GLFW_KEY_INSERT:      return Input::Insert; break;;
    case GLFW_KEY_DEL:         return Input::Del; break;;
    case GLFW_KEY_PAGEUP:      return Input::PgUp; break;;
    case GLFW_KEY_PAGEDOWN:    return Input::PgDown; break;;
    case GLFW_KEY_HOME:        return Input::Home; break;;
    case GLFW_KEY_END:         return Input::End; break;;
    case GLFW_KEY_KP_0:        return Input::KP0; break;;
    case GLFW_KEY_KP_1:        return Input::KP1; break;;
    case GLFW_KEY_KP_2:        return Input::KP2; break;;
    case GLFW_KEY_KP_3:        return Input::KP3; break;;
    case GLFW_KEY_KP_4:        return Input::KP4; break;;
    case GLFW_KEY_KP_5:        return Input::KP5; break;;
    case GLFW_KEY_KP_6:        return Input::KP6; break;;
    case GLFW_KEY_KP_7:        return Input::KP7; break;;
    case GLFW_KEY_KP_8:        return Input::KP8; break;;
    case GLFW_KEY_KP_9:        return Input::KP9; break;;
    case GLFW_KEY_KP_DIVIDE:   return Input::KPDiv; break;;
    case GLFW_KEY_KP_MULTIPLY: return Input::KPMul; break;;
    case GLFW_KEY_KP_SUBTRACT: return Input::KPSub; break;;
    case GLFW_KEY_KP_ADD:      return Input::KPAdd; break;;
    case GLFW_KEY_KP_DECIMAL:  return Input::KPDecimal; break;;
    case GLFW_KEY_KP_EQUAL:    return Input::KPEqual; break;;
    case GLFW_KEY_KP_ENTER:    return Input::KPEnter; break;;
    case GLFW_KEY_KP_NUM_LOCK: return Input::KPNumLock; break;;
    case GLFW_KEY_CAPS_LOCK:   return Input::CapsLock; break;;
    case GLFW_KEY_SCROLL_LOCK: return Input::ScrollLock; break;;
    case GLFW_KEY_PAUSE:       return Input::Pause; break;;
    case GLFW_KEY_MENU:        return Input::Menu; break;;
    default:                   return (Input::code) c; break;
    }
}
