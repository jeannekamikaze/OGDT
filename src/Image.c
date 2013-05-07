#include <OGDT/Image.h>
#include <OGDT/TLS.h>
#include "stb_image.c"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define ERROR_SIZE 1024

static TLS char err_buf [ERROR_SIZE];

U8* read_ppm (const char* path, FILE* file, int* width, int* height, int* components, const char** err);

const char* get_extension (const char* file)
{
    size_t n = strlen (file);
    const char* p = file + n - 1;
    while (p >= file && *p != '.') --p;
    if (p == file) return 0;
    else return p+1;
}

void image_init (Image* img)
{
    img->pixels = 0;
}

void image (Image* img, int width, int height, int num_components, image_t data_type)
{
    img->w = width;
    img->h = height;
    img->c = num_components;
    switch (data_type)
    {
    case Image_U8:  img->s = 1; break;
    case Image_F32: img->s = 4; break;
    }
    img->type = data_type;
    img->pixels = (U8*) malloc (width*height*num_components*img->s);
    assert (img->pixels != NULL);
}

void image_from_file (Image* img, const char* path, const char** err)
{
    *err = 0;
    const char* ext = get_extension (path);
    if (!ext)
    {
        snprintf (err_buf, ERROR_SIZE, "Failed loading image file, file must have an extension: %s", path);
        *err = err_buf;
        return;
    }
    FILE* file = fopen (path, "rb");
    if (!file)
    {
        snprintf (err_buf, ERROR_SIZE, "Failed opening image file for reading: %s", path);
        *err = err_buf;
        return;
    }
    if (strcmp(ext, "ppm") == 0 || strcmp(ext, "pgm") == 0 || strcmp(ext, "pfm") == 0)
    {
        img->pixels = read_ppm (path, file, &img->w, &img->h, &img->c, err);
    }
    else
    {
        img->pixels = stbi_load_from_file (file, &img->w, &img->h, &img->c, 0);
    }
    fclose (file);
    img->s = 1;
    img->type = Image_U8;
}

void image_from_mem (Image* img, const U8* data, int n)
{
    img->pixels = stbi_load_from_memory ((const unsigned char*)data, n, &img->w, &img->h, &img->c, 0);
    img->s = 1;
    img->type = Image_U8;
}

void image_free (Image* img)
{
    if (img->pixels) stbi_image_free (img->pixels);
    img->pixels = 0;
}

void image_flip_vertically (Image* img)
{
    int img_size  = img->w * img->h * img->c;
    int line_size = img->w * img->c;

    U8* top = img->pixels;
    U8* bot = &img->pixels[img_size - line_size];
    U8* tmp = (U8*) malloc (line_size);
    assert (tmp);

    while (top < bot)
    {
        memcpy(tmp, top, line_size);
        memcpy(top, bot, line_size);
        memcpy(bot, tmp, line_size);

        top += line_size;
        bot -= line_size;
    }

    free (tmp);
}

void write_ppm (const Image* img, const char* file)
{
    int w = img->w;
    int h = img->h;

    FILE* f = fopen (file, "w");
    fprintf (f, "P6 %d %d 255\n", w, h);

    const U8* p = img->pixels;
    size_t n = w*h;
    size_t stride = img->c * img->s;
    image_t data_type = img->type;

    for (size_t i = 0; i < n; ++i, p += stride)
    {
        switch (data_type)
        {
        case Image_U8: fwrite (p, 1, 3, f); break;
        case Image_F32:
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

U8* read_ppm (const char* path, FILE* file, int* width, int* height, int* components, const char** err)
{
    int magic1 = fgetc (file);
    int magic2 = fgetc (file);

    if (magic1 != 'P')
    {
        *err = "Failed reading ppm file: magic mismatch";
        return 0;
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
        fscanf (file, "%f", &scale);
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
        assert (pixels);
        *components = 3;
        fread (pixels, sizeof(U8), n, file);
    }
    else if (magic2 == '3') // Ascii ppm
    {
        I32 n = w*h*3;
        pixels = (U8*) malloc (n);
        assert (pixels);
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
        assert (pixels);
        *components = 1;
        fread (pixels, sizeof(U8), n, file);
    }
    else if (magic2 == '2') // Ascii pgm
    {
        I32 n = w*h;
        pixels = (U8*) malloc (n);
        assert (pixels);
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
        assert (pixels);
        *components = 1;
        fread (pixels, sizeof(float), n, file);
        float* p = (float*) pixels;
        for (int i = 0; i < n; ++i) *p++ *= scale;
    }
    else
    {
        *err = "Failed reading ppm file: unsupported ppm format";
        return 0;
    }

    *width = w;
    *height = h;

    return pixels;
}
