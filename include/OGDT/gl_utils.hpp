#pragma once

#include <OGDT/gl.h>
#include <OGDT/Exception.h>
#include <sstream>

namespace C
{
#include <OGDT/gl_utils.h>
}

namespace OGDT
{

/*
  Header: gl_utils
*/

/*
  Function: create_shader
  Create a shader from the given source code string.

  Parameters:

  code - The source code string.
  shader_type - The shader type.

  Returns:

  A compiled OpenGL shader.
*/
inline GLuint create_shader (const char* code, GLenum shader_type)
{
    const char* err;
    GLuint shader = C::create_shader (code, shader_type, &err);
    if (err || shader == 0) throw EXCEPTION (err);
    return shader;
}

/*
  Function: create_shader_from_file
  Load a shader from the specified file.

  Parameters:

  path - The path to the shader file.
  shader_type - The shader type.

  Returns:

  A compiled OpenGL shader.
*/
inline GLuint create_shader_from_file (const char* path, GLenum shader_type)
{
    const char* err;
    GLuint shader = C::create_shader_from_file (path, shader_type, &err);
    if (err) throw EXCEPTION (err);
    return shader;
}

/*
  Function: create_program
  Create and link a shader program from the given shader soure codes.

  Parameters:

  vertex_shader - The vertex shader code.
  fragment_shader - The fragment shader code.

  Returns:

  A linked shader program.
*/
inline GLuint create_program (GLuint vertex_shader, GLuint fragment_shader)
{
    const char* err;
    GLuint prog = C::create_program (vertex_shader, fragment_shader, &err);
    if (err) throw EXCEPTION (err);
    return prog;
}

/*
  Function: create_program
  Create and link a shader program from the given shader files.

  Parameters:

  vertex_shader - The path to the vertex shader file.
  fragment_shader - The path to the fragment shader file.

  Returns:

  A linked shader program.
*/
inline GLuint create_program_from_files (const char* vertex_shader, const char* fragment_shader)
{
    const char* err;
    GLuint prog = C::create_program_from_files (vertex_shader, fragment_shader, &err);
    if (err) throw EXCEPTION (err);
    return prog;
}

/*
  Function: load_texture
  Load the texture from the specified file path.

  Returns:

  An OpenGL texture identifier.
*/
inline GLuint load_texture (const char* path)
{
    const char* err;
    GLuint tex = C::load_texture (path, &err);
    if (err) throw EXCEPTION (err);
    return tex;
}

/*
  Function: get_uniform
  Get the location of the specified uniform.

  An exception is thrown on failure.
*/
inline GLint get_uniform (GLuint prog, const char* name)
{
    GLint loc = glGetUniformLocation (prog, name);
    if (loc == -1)
    {
        std::ostringstream os;
        os << "Failed getting uniform location: " << name;
        throw EXCEPTION (os);
    }
    return loc;
}

} // namespace OGDT
