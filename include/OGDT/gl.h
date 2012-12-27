#pragma once

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <gl/glew.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#else
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif
