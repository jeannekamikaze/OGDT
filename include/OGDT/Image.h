#pragma once

#include <OGDT/OGDT.h>
#include <OGDT/types.h>

namespace OGDT
{

/*
Class: Image
*/
class DECLDIR Image
{
	int w;
	int h;
	int c;
	U8* pixels;

	Image (const Image&);
	Image& operator= (const Image&);

public:

	/*
	Constructor: Image
	Constuct an empty image.
	*/
	Image ();

	/*
	Function: from_file
	Read an image from the specified file path.
	*/
	static void from_file (const char* path, Image&);

	/*
	Function: from_mem
	Read an image from memory.
	*/
	static void from_mem (const U8* data, int n, Image&);

	~Image ();

	/*
	Function: flipVertically
	Flip the image vertically.
	*/
	void flipVertically ();

	/*
	Operator: ()
	Return a mutable reference to the value at the given position.
	*/
	U8& operator () (int row, int col);

	/*
	Operator: ()
	Return the value at the given position.
	*/
	U8 operator () (int row, int col) const;

	/*
	Operator: []
	Return a mutable reference to the value at the given position.
	*/
	U8& operator [] (int i);

	/*
	Operator: []
	Return the value at the given position.
	*/
	U8 operator [] (int i) const;

	/*
	Function: r
	Return a mutable reference to the red component of the pixel at the given position.
	*/
	U8& r (int row, int col);

	/*
	Function: r
	Return the red component of the pixel at the given position.
	*/
	U8 r (int row, int col) const;

	/*
	Function: g
	Return a mutable reference to the green component of the pixel at the given position.
	*/
	U8& g (int row, int col);

	/*
	Function: g
	Return the green component of the pixel at the given position.
	*/
	U8 g (int row, int col) const;

	/*
	Function: g
	Return a mutable reference to the green component of the pixel at the given position.
	*/
	U8& b (int row, int col);

	/*
	Function: b
	Return the blue component of the pixel at the given position.
	*/
	U8 b (int row, int col) const;

	/*
	Function: g
	Return a mutable reference to the green component of the pixel at the given position.
	*/
	U8& a (int row, int col);

	/*
	Function: a
	Return the alpha component of the pixel at the given position.
	*/
	U8 a (int row, int col) const;

	/*
	Operator: const U8*
	Return a const U8 pointer to the image's pixels.
	*/
	operator const U8* () const { return pixels; }

	/*
	Function: width
	Return the image's width.
	*/
	int width () const { return w; }

	/*
	Functionm: height
	Return the image's height.
	*/
	int height () const { return h; }

	/*
	Function: numComponents
	Return the image's number of components per pixel.
	*/
	int numComponents () const { return c; }
};

} // namespace OGDT
