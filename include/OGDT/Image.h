#pragma once

#include <OGDT/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
  Enum: image_t
  Image data type
*/
typedef enum
{
    Image_U8,
    Image_F32
} image_t;

/*
  Struct: Image
*/
typedef struct
{
    int w; // Width
    int h; // Height
    int c; // Number of components
    int s; // Data type size in bytes
    image_t type;
    U8* pixels;
} Image;

/*
  Function: image
  Construct a new empty image.
*/
void image_init (Image*);

/*
  Function: image
  Construct an image of the given size.
*/
void image (Image*, int width, int height, int num_components, image_t data_type);

/*
  Function: image_from_file
  Read an image from the specified file path.

  Parameters:

  path - Path to the image file
  err - Output error string. 0 on success, non-zero otherwise.

  File formats supported:

  - Those by stbi_image.
  - Binary/ascii ppm/pgm.
*/
void image_from_file (Image*, const char* path, const char** err);

/*
  Function: from_mem
  Read an image from memory.

  Parameters:

  data - A pointer to an image file in memory
  n - The size of the data buffer
*/
void image_from_mem (Image*, const U8* data, int n);

/*
  Function: image_free
  Free the image from memory.
*/
void image_free (Image*);

/*
  Function: image_flip_vertically
  Flip the image vertically.
*/
void image_flip_vertically (Image*);

/*
  Function: write_ppm
  Save the given image to a file.

  The given image must have 3 bytes per pixel.

  If the given image is of type float, the values are assumed to be in the range [0,1].

  Parameters:

  image - The image to be written.
  file - The file where the image should be written.
*/
void write_ppm (const Image*, const char* file);

#ifdef __cplusplus
}
#endif
