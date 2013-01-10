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
public:
    
    enum DataType
    {
        Image_U8,
        Image_F32
    };
    
private:
    
    int w; // Width
    int h; // Height
    int c; // Number of components
    int s; // Data type size in bytes
    DataType t;
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
    Constructor: Image
    Construct an image of the given size.
    */
    Image (int width, int height, int num_components, DataType data_type);
    
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
    template <class T>
    T& operator () (int row, int col) {
        return (T&) pixels [(row*w + col) * sizeof(T)];
    }
    
    /*
    Operator: ()
    Return the value at the given position.
    */
    template <class T>
    T operator () (int row, int col) const {
        return (T) pixels [(row*w + col) * sizeof(T)];
    }
    
    /*
    Operator: []
    Return a mutable reference to the value at the given position.
    */
    template <class T>
    T& operator [] (int i) {
        return (T&) pixels [i * sizeof(T)];
    }
    
    /*
    Operator: []
    Return the value at the given position.
    */
    template <class T>
    T operator [] (int i) const {
        return (T) pixels [i * sizeof(T)];
    }
    
    /*
    Function: r
    Return a mutable reference to the red component of the pixel at the given position.
    */
    template <class T>
    T& r (int row, int col) {
        return (T&) pixels[((row*w + col) * c) * sizeof(T)];
    }
    
    /*
    Function: r
    Return the red component of the pixel at the given position.
    */
    template <class T>
    T r (int row, int col) const {
        return (T) pixels[((row*w + col) * c) * sizeof(T)];
    }
    
    /*
    Function: g
    Return a mutable reference to the green component of the pixel at the given position.
    */
    template <class T>
    T& g (int row, int col) {
        return (T&) pixels[((row*w + col) * c + 1) * sizeof(T)];
    }
    
    /*
    Function: g
    Return the green component of the pixel at the given position.
    */
    template <class T>
    T g (int row, int col) const {
        return (T) pixels[((row*w + col) * c + 1) * sizeof(T)];
    }
    
    /*
    Function: b
    Return a mutable reference to the green component of the pixel at the given position.
    */
    template <class T>
    T& b (int row, int col) {
        return (T&) pixels[((row*w + col) * c + 2) * sizeof(T)];
    }
    
    /*
    Function: b
    Return the blue component of the pixel at the given position.
    */
    template <class T>
    T b (int row, int col) const {
        return (T) pixels[((row*w + col) * c + 2) * sizeof(T)];
    }
    
    /*
    Function: a
    Return a mutable reference to the green component of the pixel at the given position.
    */
    template <class T>
    T& a (int row, int col) {
        return (T&) pixels[((row*w + col) * c + 3) * sizeof(T)];
    }
    
    /*
    Function: a
    Return the alpha component of the pixel at the given position.
    */
    template <class T>
    T a (int row, int col) const {
        return (T) pixels[((row*w + col) * c + 3) * sizeof(T)];
    }
    
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
    
    /*
    Function: dataSize
    Return the size of a pixel component.
    */
    int dataSize () const { return s; }
    
    /*
    Function: dataType
    Return the image's data type.
    */
    DataType dataType () const { return t; }
};

/*
Function: write_ppm
Save the given image to a file.

The given image must have 3 bytes per pixel.

If the given image is of type float, the values are assumed to be in the range [0,1].

Parameters:

image - The image to be written.
file - The file where the image should be written.
*/
void write_ppm (const Image& image, const char* file);

} // namespace OGDT
