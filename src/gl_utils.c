#include <OGDT/gl_utils.h>
#include <OGDT/Image.h>
#include <OGDT/TLS.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERROR_SIZE 4096

static TLS char err_buf [ERROR_SIZE];

char* copy_string (const char* str)
{
    size_t n = strlen (str);
    char* scopy = (char*) malloc (n+1);
    assert (scopy);
    strcpy (scopy, str);
    return scopy;
}

GLuint create_shader (const char* code, GLenum shader_type, const char** err)
{
    *err = 0;
    GLuint shader = glCreateShader (shader_type);
    if (shader)
    {
        const GLchar* shader_code[] = {code};
        glShaderSource (shader, 1, shader_code, NULL);
        glCompileShader (shader);
        GLint result;
        glGetShaderiv (shader, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
            GLint log_len;
            glGetShaderiv (shader, GL_INFO_LOG_LENGTH, &log_len);
            if (log_len > 0)
            {
                char* log = (char*) malloc (log_len);
                assert (log);
                glGetShaderInfoLog (shader, log_len, NULL, log);
                snprintf (err_buf, ERROR_SIZE, "%s", log);
                free (log);
                *err = err_buf;
            }
            else *err = "Shader compilation failed";
        }
    }
    return shader;
}

GLuint create_shader_from_file (const char* path, GLenum shader_type, const char** err)
{
    *err = 0;
    FILE* f = fopen (path, "r");
    if (!f)
    {
        snprintf (err_buf, ERROR_SIZE, "Failed opening shader file %s", path);
        *err = err_buf;
        return 0;
    }

    fseek (f, 0, SEEK_END);
    int len = ftell (f);
    fseek (f, 0, SEEK_SET);
    char* code = (char*) malloc (len);
    assert (code);
    fread (code, len, 1, f);
    fclose (f);

    GLuint shader = glCreateShader (shader_type);
    if (shader)
    {
        const GLchar* shader_code[] = {code};
        const GLint lengths[] = {len};
        glShaderSource (shader, 1, shader_code, lengths);
        glCompileShader (shader);
        GLint result;
        glGetShaderiv (shader, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
            GLint log_len;
            glGetShaderiv (shader, GL_INFO_LOG_LENGTH, &log_len);
            if (log_len > 0)
            {
                char* log = (char*) malloc (log_len);
                assert (log);
                glGetShaderInfoLog (shader, log_len, NULL, log);
                snprintf (err_buf, ERROR_SIZE, "Failed loading shader file %s\n%s", path, log);
                free (log);
                *err = err_buf;
            }
            else
            {
                snprintf (err_buf, ERROR_SIZE, "Failed loading shader file %s", path);
                *err = err_buf;
            }
        }
    }
    else *err = "glCreateShader failed";
    free (code);
    return shader;
}

GLuint create_program (GLuint vertex_shader, GLuint fragment_shader, const char** err)
{
    *err = 0;
    GLuint prog = glCreateProgram ();
    if (prog == 0)
    {
        *err = "create_program: Failed creating GLSL program";
        return 0;
    }
    glAttachShader (prog, vertex_shader);
    glAttachShader (prog, fragment_shader);
    glLinkProgram (prog);
    GLint result;
    glGetProgramiv (prog, GL_LINK_STATUS, &result);
    if (result == GL_FALSE)
    {
        GLint log_len;
        glGetProgramiv (prog, GL_INFO_LOG_LENGTH, &log_len);
        if (log_len > 0)
        {
            char* log = (char*) malloc (log_len);
            assert (log);
            glGetProgramInfoLog (prog, log_len, NULL, log);
            snprintf (err_buf, ERROR_SIZE, "Failed linking program\n%s", log);
            free (log);
            *err = err_buf;
        }
        else *err = "Failed linking program";
    }
    return prog;
}

GLuint create_program_from_files (const char* vertex_shader, const char* fragment_shader, const char** err)
{
    GLuint vs = create_shader_from_file (vertex_shader, GL_VERTEX_SHADER, err);
    if (*err) return 0;
    GLuint fs = create_shader_from_file (fragment_shader, GL_FRAGMENT_SHADER, err);
    if (*err) return 0;
    GLuint prog = create_program (vs, fs, err);
    if (*err) return 0;
    glDeleteShader (vs);
    glDeleteShader (fs);
    return prog;
}

GLuint load_texture (const char* path, const char** err)
{
    Image image;
    image_init (&image);
    image_from_file (&image, path, err);
    if (*err) return 0;
    image_flip_vertically (&image);
    unsigned w = image.w;
    unsigned h = image.h;
    unsigned c = image.c;
    GLenum format;
    switch (c)
    {
    case 1:  format = GL_DEPTH; break;
    case 3:  format = GL_RGB;   break;
    default: format = GL_RGBA;  break;
    }
    GLuint tex;
    glGenTextures (1, &tex);
    glBindTexture (GL_TEXTURE_2D, tex);
    if (GLEW_EXT_texture_filter_anisotropic)
    {
        GLfloat ani;
        glGetFloatv (GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &ani);
        gluBuild2DMipmaps (GL_TEXTURE_2D, c, w, h, format, GL_UNSIGNED_BYTE, image.pixels);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, ani);
    }
    else
    {
        gluBuild2DMipmaps (GL_TEXTURE_2D, c, w, h, format, GL_UNSIGNED_BYTE, image.pixels);
        glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        //glTexImage2D (GL_TEXTURE_2D, 0, 4, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
        //glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        //glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    glBindTexture (GL_TEXTURE_2D, 0);
    image_free (&image);
    return tex;
}
