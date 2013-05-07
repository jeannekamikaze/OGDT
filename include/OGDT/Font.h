#pragma once

#include <OGDT/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
  Package: Font
  A package for rendering text in 2D and 3D.
*/

typedef struct Font Font;

/*
  Enum: font_render_mode

  screen_space - Render directly in viewport coordinates.
  world_space - Render in world space.
*/
typedef enum
{
    font_screen_space,
    font_world_space
} font_render_mode;

/*
  Enum: font_draw_style

  top_left - Interpret the given position as the text's top left corner.
  centered - Interpret the given position as the text's center.
*/
typedef enum
{
    font_top_left,
    font_centered
} font_draw_style;

/*
  Function: font_from_file
  Construct a font from the specified alphabet file.

  Parameters:

  alphabet_path - Path to the alphabet file.
  alphabet_width - Alphabet image width.
  alphabet_height - Alphabet image height.
  stride - Horizontal stride between characters in the alphabet image.
  err - Output error string. 0 on success, non-zero otherwise.
*/
Font* font_from_file (const char* alphabet_path, int alphabet_width, int alphabet_height, int stride, const char** err);

/*
  Function: font_from_mem
  Construct a font from the given alphabet in memory.

  Parameters:

  alphabet_pixels - Pointer to the alphabet's pixels in memory.
  alphabet_width - Alphabet image width.
  alphabet_height - Alphabet image height.
  stride - Horizontal stride between characters in the alphabet image.
*/
Font* font_from_mem (const U8* alphabet_pixels, int alphabet_width, int alphabet_height, int stride);

/*
  Function: font_free
  Clean up the font.
*/
void font_free (Font**);

/*
  Function: font_start
  Prepare OpenGL for text rendering.

  Parameters:

  mode - The mode to render text in. 0 defaults to font_screen_space.
*/
void font_start (Font*, font_render_mode mode);

/*
  Function: font_end
  End font rendering, restoring OpenGL to its original state.
*/
void font_end (Font*);

/*
  Function: font_render
  Render the given text.

  Parameters:

  font_size - 0 defaults to a font size of 12.
  style - 0 defaults to font_top_left.
*/
void font_render (const Font*, float px, float py, float pz,
                  const char* text, float font_size, font_draw_style style);

/*
  Function: font_render_to_aabb
  Render the given text.
*/
void font_render_to_aabb (const Font*, float xmin, float ymin, float zmin,
                          float xmax, float ymax, float zmax, const char* text);

#ifdef __cplusplus
}
#endif
