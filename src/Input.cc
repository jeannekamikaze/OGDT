#include <OGDT/Input.h>
#include <GL/glfw.h>


using namespace OGDT;


struct Input::_impl
{
	int xmouse, ymouse;
};


Input::Input () : impl (new _impl)
{
}


Input::~Input ()
{
	delete impl;
}


void Input::poll ()
{
	glfwPollEvents ();
	glfwGetMousePos (&impl->xmouse, &impl->ymouse);
}


bool Input::isDown (Input::code c) const
{
	switch (c)
	{
	case LMB:        return glfwGetMouseButton (GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS; break;
	case RMB:        return glfwGetMouseButton (GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS; break;
	case MMB:        return glfwGetMouseButton (GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS; break;
	case Space:      return glfwGetKey (GLFW_KEY_SPACE) == GLFW_PRESS; break;
	case Esc:        return glfwGetKey (GLFW_KEY_ESC) == GLFW_PRESS; break;
	case F1:         return glfwGetKey (GLFW_KEY_F1) == GLFW_PRESS; break;
	case F2:         return glfwGetKey (GLFW_KEY_F2) == GLFW_PRESS; break;
	case F3:         return glfwGetKey (GLFW_KEY_F3) == GLFW_PRESS; break;
	case F4:         return glfwGetKey (GLFW_KEY_F4) == GLFW_PRESS; break;
	case F5:         return glfwGetKey (GLFW_KEY_F5) == GLFW_PRESS; break;
	case F6:         return glfwGetKey (GLFW_KEY_F6) == GLFW_PRESS; break;
	case F7:         return glfwGetKey (GLFW_KEY_F7) == GLFW_PRESS; break;
	case F8:         return glfwGetKey (GLFW_KEY_F8) == GLFW_PRESS; break;
	case F9:         return glfwGetKey (GLFW_KEY_F9) == GLFW_PRESS; break;
	case F10:        return glfwGetKey (GLFW_KEY_F10) == GLFW_PRESS; break;
	case F11:        return glfwGetKey (GLFW_KEY_F11) == GLFW_PRESS; break;
	case F12:        return glfwGetKey (GLFW_KEY_F12) == GLFW_PRESS; break;
	case F13:        return glfwGetKey (GLFW_KEY_F13) == GLFW_PRESS; break;
	case F14:        return glfwGetKey (GLFW_KEY_F14) == GLFW_PRESS; break;
	case F15:        return glfwGetKey (GLFW_KEY_F15) == GLFW_PRESS; break;
	case F16:        return glfwGetKey (GLFW_KEY_F16) == GLFW_PRESS; break;
	case F17:        return glfwGetKey (GLFW_KEY_F17) == GLFW_PRESS; break;
	case F18:        return glfwGetKey (GLFW_KEY_F18) == GLFW_PRESS; break;
	case F19:        return glfwGetKey (GLFW_KEY_F19) == GLFW_PRESS; break;
	case F20:        return glfwGetKey (GLFW_KEY_F20) == GLFW_PRESS; break;
	case F21:        return glfwGetKey (GLFW_KEY_F21) == GLFW_PRESS; break;
	case F22:        return glfwGetKey (GLFW_KEY_F22) == GLFW_PRESS; break;
	case F23:        return glfwGetKey (GLFW_KEY_F23) == GLFW_PRESS; break;
	case F24:        return glfwGetKey (GLFW_KEY_F24) == GLFW_PRESS; break;
	case F25:        return glfwGetKey (GLFW_KEY_F25) == GLFW_PRESS; break;
	case Up:         return glfwGetKey (GLFW_KEY_UP) == GLFW_PRESS; break;
	case Down:       return glfwGetKey (GLFW_KEY_DOWN) == GLFW_PRESS; break;
	case Left:       return glfwGetKey (GLFW_KEY_LEFT) == GLFW_PRESS; break;
	case Right:      return glfwGetKey (GLFW_KEY_RIGHT) == GLFW_PRESS; break;
	case LShift:     return glfwGetKey (GLFW_KEY_LSHIFT) == GLFW_PRESS; break;
	case RShift:     return glfwGetKey (GLFW_KEY_RSHIFT) == GLFW_PRESS; break;
	case LCtrl:      return glfwGetKey (GLFW_KEY_LCTRL) == GLFW_PRESS; break;
	case RCtrl:      return glfwGetKey (GLFW_KEY_RCTRL) == GLFW_PRESS; break;
	case LAlt:       return glfwGetKey (GLFW_KEY_LALT) == GLFW_PRESS; break;
	case RAlt:       return glfwGetKey (GLFW_KEY_RALT) == GLFW_PRESS; break;
	case LSuper:     return glfwGetKey (GLFW_KEY_LSUPER) == GLFW_PRESS; break;
	case RSuper:     return glfwGetKey (GLFW_KEY_RSUPER) == GLFW_PRESS; break;
	case Tab:        return glfwGetKey (GLFW_KEY_TAB) == GLFW_PRESS; break;
	case Enter:      return glfwGetKey (GLFW_KEY_ENTER) == GLFW_PRESS; break;
	case Backspace:  return glfwGetKey (GLFW_KEY_BACKSPACE) == GLFW_PRESS; break;
	case Insert:     return glfwGetKey (GLFW_KEY_INSERT) == GLFW_PRESS; break;
	case Del:        return glfwGetKey (GLFW_KEY_DEL) == GLFW_PRESS; break;
	case PgUp:       return glfwGetKey (GLFW_KEY_PAGEUP) == GLFW_PRESS; break;
	case PgDown:     return glfwGetKey (GLFW_KEY_PAGEDOWN) == GLFW_PRESS; break;
	case Home:       return glfwGetKey (GLFW_KEY_HOME) == GLFW_PRESS; break;
	case End:        return glfwGetKey (GLFW_KEY_END) == GLFW_PRESS; break;
	case KP0:        return glfwGetKey (GLFW_KEY_KP_0) == GLFW_PRESS; break;
	case KP1:        return glfwGetKey (GLFW_KEY_KP_1) == GLFW_PRESS; break;
	case KP2:        return glfwGetKey (GLFW_KEY_KP_2) == GLFW_PRESS; break;
	case KP3:        return glfwGetKey (GLFW_KEY_KP_3) == GLFW_PRESS; break;
	case KP4:        return glfwGetKey (GLFW_KEY_KP_4) == GLFW_PRESS; break;
	case KP5:        return glfwGetKey (GLFW_KEY_KP_5) == GLFW_PRESS; break;
	case KP6:        return glfwGetKey (GLFW_KEY_KP_6) == GLFW_PRESS; break;
	case KP7:        return glfwGetKey (GLFW_KEY_KP_7) == GLFW_PRESS; break;
	case KP8:        return glfwGetKey (GLFW_KEY_KP_8) == GLFW_PRESS; break;
	case KP9:        return glfwGetKey (GLFW_KEY_KP_9) == GLFW_PRESS; break;
	case KPDiv:      return glfwGetKey (GLFW_KEY_KP_DIVIDE) == GLFW_PRESS; break;
	case KPMul:      return glfwGetKey (GLFW_KEY_KP_MULTIPLY) == GLFW_PRESS; break;
	case KPSub:      return glfwGetKey (GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS; break;
	case KPAdd:      return glfwGetKey (GLFW_KEY_KP_ADD) == GLFW_PRESS; break;
	case KPDecimal:  return glfwGetKey (GLFW_KEY_KP_DECIMAL) == GLFW_PRESS; break;
	case KPEqual:    return glfwGetKey (GLFW_KEY_KP_EQUAL) == GLFW_PRESS; break;
	case KPEnter:    return glfwGetKey (GLFW_KEY_KP_ENTER) == GLFW_PRESS; break;
	case KPNumLock:  return glfwGetKey (GLFW_KEY_KP_NUM_LOCK) == GLFW_PRESS; break;
	case CapsLock:   return glfwGetKey (GLFW_KEY_CAPS_LOCK) == GLFW_PRESS; break;
	case ScrollLock: return glfwGetKey (GLFW_KEY_SCROLL_LOCK) == GLFW_PRESS; break;
	case Pause:      return glfwGetKey (GLFW_KEY_PAUSE) == GLFW_PRESS; break;
	case Menu:       return glfwGetKey (GLFW_KEY_MENU) == GLFW_PRESS; break;
	default:         return glfwGetKey (c) == GLFW_PRESS; break;
	}
}


void Input::getMousePosition (int& x, int& y) const
{
	x = impl->xmouse;
	y = impl->ymouse;
}


void Input::setMousePosition (int x, int y)
{
	glfwSetMousePos (x, y);
	impl->xmouse = x;
	impl->ymouse = y;
}
