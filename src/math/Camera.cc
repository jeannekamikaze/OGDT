#include <OGDT/math/Camera.h>


using namespace OGDT;


Camera::Camera (float fovy, float aspect, float near, float far)
    : proj (mat4::perspective(fovy, aspect, near, far))
{
}


Camera::Camera (float left, float right, float bottom, float top, float near, float far)
    : proj (mat4::ortho(left, right, bottom, top, near, far))
{
}
