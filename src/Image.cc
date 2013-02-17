#include <OGDT/Image.h>
#include <OGDT/Exception.h>
#include "stb_image.c"
#include <cstdio>
#include <cstring>
#include <sstream>


using namespace OGDT;


U8* read_ppm (const char* path, FILE* file, int* width, int* height, int* components);


const char* get_extension (const char* file)
{
    size_t n = strlen (file);
    const char* p = file + n - 1;
    while (p >= file && *p != '.') --p;
    if (p == file) return nullptr;
    else return p+1;
}


Image::Image () : pixels (nullptr)
{
}


Image::Image (int width, int height, int num_components, DataType data_type)
{
    w = width;
    h = height;
    c = num_components;
    switch (data_type)
    {
    case Image_U8: s = 1; break;
    case Image_F32: s = 4; break;
    }
    t = data_type;
    pixels = (U8*) malloc (w*h*c*s);
}


void Image::from_file (const char* path, Image& img)
{
    const char* ext = get_extension (path);
    if (!ext)
    {
        std::ostringstream os;
        os << "Failed loading image file: file must have an extension; " << path;
        throw EXCEPTION (os);
    }
    FILE* file = fopen (path, "rb");
    if (!file)
    {
        std::ostringstream os;
        os << "Error opening file: " << file;
        throw EXCEPTION (os);
    }
    if (img.pixels) stbi_image_free (img.pixels);
    if (strcmp(ext, "ppm") == 0 || strcmp(ext, "pgm") == 0 || strcmp(ext, "pfm") == 0)
    {
        img.pixels = read_ppm (path, file, &img.w, &img.h, &img.c);
    }
    else
    {
        img.pixels = stbi_load_from_file (file, &img.w, &img.h, &img.c, 0);
    }
    fclose (file);
    img.s = 1;
    img.t = Image_U8;
}


void Image::from_mem (const U8* data, int n, Image& img)
{
    if (img.pixels) stbi_image_free (img.pixels);
    img.pixels = stbi_load_from_memory ((const unsigned char*)data, n, &img.w, &img.h, &img.c, 0);
    img.s = 1;
    img.t = Image_U8;
}


Image::~Image ()
{
    if (pixels) stbi_image_free (pixels);
}


void Image::flipVertically ()
{
    int img_size = w * h * c;
    int line_size = w * c;
    
    unsigned char* top = pixels;
    unsigned char* bot = &pixels[img_size - line_size];
    unsigned char* tmp = new unsigned char[line_size];
    
    while (top < bot)
    {
        memcpy(tmp, top, line_size);
        memcpy(top, bot, line_size);
        memcpy(bot, tmp, line_size);
        
        top += line_size;
        bot -= line_size;
    }
    
    delete tmp;
}


void OGDT::write_ppm (const Image& image, const char* file)
{
    int w = image.width();
    int h = image.height();
    
    FILE* f = fopen (file, "w");
    fprintf (f, "P6 %d %d 255\n", w, h);
    
    const U8* p = image;
    size_t n = w*h;
    size_t stride = image.numComponents() * image.dataSize();
    Image::DataType data_type = image.dataType();
    
    for (size_t i = 0; i < n; ++i, p += stride)
    {
        switch (data_type)
        {
        case Image::Image_U8: fwrite (p, 1, 3, f); break;
        case Image::Image_F32:
        {
            U8 bytes[3];
            for (size_t j = 0; j < 3; ++j)
            {
                bytes[j] = (U8) (*(((float*)p)+j) * 255.0f);
            }
            fwrite (bytes, 1, 3, f);
            break;
        }
        }
    }
    
    fclose (f);
}


U8* read_ppm (const char* path, FILE* file, int* width, int* height, int* components)
{
    int magic1 = fgetc (file);
    int magic2 = fgetc (file);

    if (magic1 != 'P')
    {
        std::ostringstream os;
        os << "Failed reading ppm file: magic mismatch; " << path;
        throw EXCEPTION (os);
    }
    
    I32 w, h;
    fscanf (file, "%d %d", &w, &h);

    I32 max_value;
    float scale;

    if (magic2 == 'f' || magic2 == 'F')
    {
        fscanf (file, "%f", &scale);
    }
    else
    {
        fscanf (file, "%d", &scale);
    }
    
    U8 c;
    do
    {
        fread (&c, 1, 1, file);
    }
    while (c == ' ' || c == '\r' || c == '\n');
    fseek (file, -1, SEEK_CUR);
    
    U8* pixels;
    U8 r, g, b;
    
    if (magic2 == '6') // Binary ppm
    {
        I32 n = w*h*3;
        pixels = (U8*) malloc (n);
        *components = 3;
        fread (pixels, sizeof(U8), n, file);
    }
    else if (magic2 == '3') // Ascii ppm
    {
        I32 n = w*h*3;
        pixels = (U8*) malloc (n);
        *components = 3;
        for (int i = 0; i < n; i += 3)
        {
            fscanf (file, "%c %c %c", &r, &g, &b);
            pixels[i]   = r;
            pixels[i+1] = g;
            pixels[i+2] = b;
        }
    }
    else if (magic2 == '5') // Binary pgm
    {
        I32 n = w*h;
        pixels = (U8*) malloc (n);
        *components = 1;
        fread (pixels, sizeof(U8), n, file);
    }
    else if (magic2 == '2') // Ascii pgm
    {
        I32 n = w*h;
        pixels = (U8*) malloc (n);
        *components = 3;
        for (int i = 0; i < n; ++i)
        {
            fscanf (file, "%c", &r);
            pixels[i] = r;
        }
    }
    else if (magic2 == 'f') // Grayscale pfm
    {
        I32 n = w*h;
        pixels = (U8*) malloc (n * sizeof(float));
        *components = 1;
        fread (pixels, sizeof(float), n, file);
        float* p = (float*) pixels;
        for (int i = 0; i < n; ++i) *p++ *= scale;
    }
    else
    {
        std::ostringstream os;
        os << "Failed reading ppm file: unsupported ppm format: P" << magic2 << "; " << path;
        throw EXCEPTION (os);
    }
    
    *width = w;
    *height = h;
    
    return pixels;
}
