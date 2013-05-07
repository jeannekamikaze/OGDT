#pragma once

#ifdef __cplusplus
extern "C" {
#else
#include <OGDT/gl.h>
#endif

/*
  Header: gl_utils
*/

/*
  Function: create_shader
  Create a shader from the given source code string.

  Parameters:

  code - The source code string.
  shader_type - The shader type.
  err - Output error string. 0 on success, non-zero otherwise.

  Returns:

  A compiled OpenGL shader.
*/
GLuint create_shader (const char* code, GLenum shader_type, const char** err);

/*
  Function: create_shader_from_file
  Load a shader from the specified file.

  Parameters:

  path - The path to the shader file.
  shader_type - The shader type.
  err - Output error string. 0 on success, non-zero otherwise.

  Returns:

  A compiled OpenGL shader.
*/
GLuint create_shader_from_file (const char* path, GLenum shader_type, const char** err);

/*
  Function: create_program
  Create and link a shader program from the given shader soure codes.

  Parameters:

  vertex_shader - The vertex shader code.
  fragment_shader - The fragment shader code.
  err - Output error string. 0 on success, non-zero otherwise.

  Returns:

  A linked shader program.
*/
GLuint create_program (GLuint vertex_shader, GLuint fragment_shader, const char** err);

/*
  Function: create_program
  Create and link a shader program from the given shader files.

  Parameters:

  vertex_shader - The path to the vertex shader file.
  fragment_shader - The path to the fragment shader file.
  err - Output error string. 0 on success, non-zero otherwise.

  Returns:

  A linked shader program.
*/
GLuint create_program_from_files (const char* vertex_shader, const char* fragment_shader, const char** err);

/*
  Function: load_texture
  Load the texture from the specified file path.

  Parameters:

  path - Path to the texture file.
  err - Output error string. 0 on success, non-zero otherwise.

  Returns:

  An OpenGL texture identifier.
*/
GLuint load_texture (const char* path, const char** err);

#ifdef __cplusplus
}
#endif
