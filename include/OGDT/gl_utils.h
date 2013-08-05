#pragma once

#include <OGDT/gl.h>
#include <OGDT/Exception.h>

/*
File: gl_utils
*/

/*
Function: create_shader
Create a shader from the given source code string.

Parameters:

code - The source code string.
shader_type - The shader type as specified by OpenGL.

Returns:

A compiled OpenGL shader.
*/
GLuint create_shader (const char* code, GLenum shader_type);

GLuint create_shader_from_file (const char* path, GLenum shader_type);

/*
Function: create_program
Create and link a shader program from the given shader soure codes.

Parameters:

vertex_shader - The vertex shader code.
fragment_shader - The fragment shader code.

Returns:

A linked shader program.
*/
GLuint create_program (GLuint vertex_shader, GLuint fragment_shader);

/*
Function: create_program
Create and link a shader program from the given shader files.

Parameters:

vertex_shader - The path to the vertex shader file.
fragment_shader - The path to the fragment shader file.

Returns:

A linked shader program.
*/
GLuint create_program_from_files (const char* vertex_shader, const char* fragment_shader);

/*
Function: load_texture
Load the texture from the specified file path.

Returns:

An OpenGL texture identifier.
*/
GLuint load_texture (const char* path);

/*
Function: get_uniform
Get the location of the specified uniform.

An exception is thrown on failure.
*/
GLint get_uniform (GLuint prog, const char* name);

/*
Function: get_attribute
Get the location of the specified attribute.

An exception is thrown on failure.
*/
GLint get_attribute (GLuint prog, const char* name);

/*
Function: assert_gl
Throw an exception if there was an OpenGL error.
*/
#ifdef OGDT_DEBUG
#define ASSERT_GL { \
    GLenum e = glGetError(); \
    switch (e) { \
        case GL_NO_ERROR: break; \
        case GL_INVALID_ENUM: throw EXCEPTION ("GL_INVALID_ENUM"); \
        case GL_INVALID_VALUE: throw EXCEPTION ("GL_INVALID_VALUE"); \
        case GL_INVALID_OPERATION: throw EXCEPTION ("GL_INVALID_OPERATION"); \
        case GL_INVALID_FRAMEBUFFER_OPERATION: throw EXCEPTION ("GL_INVALID_FRAMEBUFFER_OPERATION"); \
        case GL_OUT_OF_MEMORY: throw EXCEPTION ("GL_OUT_OF_MEMORY"); \
        case GL_STACK_UNDERFLOW: throw EXCEPTION ("GL_STACK_UNDERFLOW"); \
        case GL_STACK_OVERFLOW: throw EXCEPTION ("GL_STACK_OVERFLOW"); \
        default: throw EXCEPTION ("Unknown OpenGL error"); \
    } \
}
#else
#define ASSERT_GL
#endif
