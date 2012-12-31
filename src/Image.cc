#include <OGDT/Image.h>
#include <OGDT/Exception.h>
#include "stb_image.c"
#include <cstdio>


using namespace OGDT;


Image::Image () : pixels (nullptr)
{
}


void Image::from_file (const char* path, Image& img)
{
	FILE* file = fopen (path, "rb");
    if (!file)
    {
        std::ostringstream os;
        os << "Error opening file: " << file;
        throw EXCEPTION (os);
    }
	if (img.pixels) stbi_image_free (img.pixels);
	img.pixels = stbi_load_from_file (file, &img.w, &img.h, &img.c, 0);
	fclose (file);
}


void Image::from_mem (const U8* data, int n, Image& img)
{
	if (img.pixels) stbi_image_free (img.pixels);
	img.pixels = stbi_load_from_memory ((const unsigned char*)data, n, &img.w, &img.h, &img.c, 0);
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


U8& Image::operator () (int row, int col)
{
	return pixels [row*w + col];
}


U8 Image::operator () (int row, int col) const
{
	return pixels [row*w + col];
}


U8& Image::operator [] (int i)
{
	return pixels [i];
}


U8 Image::operator [] (int i) const
{
	return pixels [i];
}


U8& Image::r (int row, int col)
{
	return pixels[(row*w + col) * c];
}


U8 Image::r (int row, int col) const
{
	return pixels[(row*w + col) * c];
}


U8& Image::g (int row, int col)
{
	return pixels[(row*w + col) * c + 1];
}


U8 Image::g (int row, int col) const
{
	return pixels[(row*w + col) * c + 1];
}


U8& Image::b (int row, int col)
{
	return pixels[(row*w + col) * c + 2];
}


U8 Image::b (int row, int col) const
{
	return pixels[(row*w + col) * c + 2];
}


U8& Image::a (int row, int col)
{
	return pixels[(row*w + col) * c + 3];
}


U8 Image::a (int row, int col) const
{
	return pixels[(row*w + col) * c + 3];
}
