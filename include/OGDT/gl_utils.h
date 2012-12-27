#pragma once

#include <OGDT/OGDT.h>
#include <OGDT/gl.h>

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
DECLDIR GLuint create_shader (const char* code, GLenum shader_type);

DECLDIR GLuint create_shader_from_file (const char* path, GLenum shader_type);

/*
Function: create_program
Create and link a shader program from the given shaders.

Parameters:

vertex_shader - The vertex shader.
fragment_shader - The fragment shader.

Returns:

A linked shader program.
*/
DECLDIR GLuint create_program (GLuint vertex_shader, GLuint fragment_shader);

/*
Function: load_texture
Load the texture from the specified file path.

Returns:

An OpenGL texture identifier.
*/
DECLDIR GLuint load_texture (const char* path);
