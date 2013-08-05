#include <OGDT/gl_utils.h>
#include <OGDT/Exception.h>
#include <OGDT/Image.h>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace OGDT;

char* copy_string (const char* str) {
    size_t n = strlen (str);
    char* scopy = new char[n+1];
    strcpy (scopy, str);
    return scopy;
}

GLuint create_shader (const char* code, GLenum shader_type) {
    const GLuint shader = glCreateShader (shader_type);
    if (shader) {
        const GLchar* shader_code[] = {code};
        glShaderSource (shader, 1, shader_code, NULL);
        glCompileShader (shader);
        GLint result;
        glGetShaderiv (shader, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE) {
            GLint log_len;
            glGetShaderiv (shader, GL_INFO_LOG_LENGTH, &log_len);
            if (log_len > 0) {
                char* log = new char[log_len];
                glGetShaderInfoLog (shader, log_len, NULL, log);
                throw EXCEPTION (log);
            }
            return 0;
        }
        return shader;
    }
    else return 0;
}

GLuint create_shader_from_file (const char* path, GLenum shader_type) {
    FILE* f = fopen (path, "r");
    if (!f) {
        std::ostringstream os;
        os << "Failed opening shader file: " << path;
        throw EXCEPTION (os);
    }
    
    fseek (f, 0, SEEK_END);
    int len = ftell (f);
    fseek (f, 0, SEEK_SET);
    char* code = new char [len];
    if (fread (code, len, 1, f) != 1) {
        std::ostringstream os;
        os << "Failed reading shader file: " << path;
        throw EXCEPTION (os);
    }
    fclose (f);
    
    const GLuint shader = glCreateShader (shader_type);
    if (shader) {
        const GLchar* shader_code[] = {code};
        const GLint lengths[] = {len};
        glShaderSource (shader, 1, shader_code, lengths);
        glCompileShader (shader);
        delete[] code;
        GLint result;
        glGetShaderiv (shader, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE) {
            GLint log_len;
            glGetShaderiv (shader, GL_INFO_LOG_LENGTH, &log_len);
            if (log_len > 0) {
                char* log = new char[log_len];
                glGetShaderInfoLog (shader, log_len, NULL, log);
                std::ostringstream os;
                os << "Failed loading shader file " << path << ": " << log;
                throw EXCEPTION (os);
            }
            else {
                std::ostringstream os;
                os << "Failed loading shader file " << path;
                throw EXCEPTION (os);
            }
        }
        return shader;
    }
    else throw EXCEPTION ("glCreateShader failed");
}

GLuint create_program (GLuint vertex_shader, GLuint fragment_shader) {
    GLuint prog = glCreateProgram ();
    if (prog == 0) {
        throw EXCEPTION ("create_program: Failed creating GLSL program");
    }
    glAttachShader (prog, vertex_shader);
    glAttachShader (prog, fragment_shader);
    glLinkProgram (prog);
    GLint result;
    glGetProgramiv (prog, GL_LINK_STATUS, &result);
    if (result == GL_FALSE) {
        GLint log_len;
        glGetProgramiv (prog, GL_INFO_LOG_LENGTH, &log_len);
        if (log_len > 0) {
            char* log = new char[log_len];
            glGetProgramInfoLog (prog, log_len, NULL, log);
            throw EXCEPTION  (log);
        }
        return 0;
    }
    else return prog;
}

GLuint load_texture (const char* path) {
    Image image;
    Image::from_file(path, image);
    image.flipVertically ();
    unsigned w = image.width();
    unsigned h = image.height();
    unsigned c = image.numComponents();
    GLenum format;
    switch (c) {
    case 1:  format = GL_DEPTH; break;
    case 3:  format = GL_RGB;   break;
    default: format = GL_RGBA;  break;
    }
    GLuint tex;
    glGenTextures (1, &tex);
    glBindTexture (GL_TEXTURE_2D, tex);
    if (GLEW_EXT_texture_filter_anisotropic) {
        GLfloat ani;
        glGetFloatv (GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &ani);
        gluBuild2DMipmaps (GL_TEXTURE_2D, c, w, h, format, GL_UNSIGNED_BYTE, image);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, ani);
    }
    else {
        gluBuild2DMipmaps (GL_TEXTURE_2D, c, w, h, format, GL_UNSIGNED_BYTE, image);
        glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        //glTexImage2D (GL_TEXTURE_2D, 0, 4, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
        //glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        //glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    glBindTexture (GL_TEXTURE_2D, 0);
    return tex;
}

GLuint create_program_from_files (const char* vertex_shader, const char* fragment_shader) {
    GLuint vs = create_shader_from_file (vertex_shader, GL_VERTEX_SHADER);
    GLuint fs = create_shader_from_file (fragment_shader, GL_FRAGMENT_SHADER);
    GLuint prog = create_program (vs, fs);
    glDeleteShader (vs);
    glDeleteShader (fs);
    return prog;
}

GLint get_uniform (GLuint prog, const char* name) {
    GLint loc = glGetUniformLocation (prog, name);
    if (loc == -1) {
        std::ostringstream os;
        os << "Failed getting uniform location: " << name;
        throw EXCEPTION (os);
    }
    return loc;
}

GLint get_attribute (GLuint prog, const char* name) {
    GLint loc = glGetAttribLocation (prog, name);
    if (loc == -1) {
        std::ostringstream os;
        os << "Failed getting uniform location: " << name;
        throw EXCEPTION (os);
    }
    return loc;
}
