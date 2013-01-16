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
Create and link a shader program from the given shader soure codes.

Parameters:

vertex_shader - The vertex shader code.
fragment_shader - The fragment shader code.

Returns:

A linked shader program.
*/
DECLDIR GLuint create_program (GLuint vertex_shader, GLuint fragment_shader);

/*
Function: create_program
Create and link a shader program from the given shader files.

Parameters:

vertex_shader - The path to the vertex shader file.
fragment_shader - The path to the fragment shader file.

Returns:

A linked shader program.
*/
DECLDIR GLuint create_program_from_files (const char* vertex_shader, const char* fragment_shader);

/*
Function: load_texture
Load the texture from the specified file path.

Returns:

An OpenGL texture identifier.
*/
DECLDIR GLuint load_texture (const char* path);

/*
Function: get_uniform
Get the location of the specified uniform.

An exception is thrown on failure.
*/
DECLDIR GLint get_uniform (GLuint prog, const char* name);
