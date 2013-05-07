#pragma once

#include <OGDT/types.h>
#include <OGDT/Exception.h>

namespace C
{
#include <OGDT/Font.h>
}

namespace OGDT
{

/*
  Class: Font
  A class for rendering text in 2D and 3D.
*/
class Font
{
    C::Font* font;

    Font (const Font&);
    Font& operator= (const Font&);

public:

    /*
      Enum: font_render_mode

      screen_space - Render directly in viewport coordinates.
      world_space - Render in world space.
    */
    enum render_mode
    {
        screen_space,
        world_space
    };

    /*
      Enum: font_draw_style

      top_left - Interpret the given position as the text's top left corner.
      centered - Interpret the given position as the text's center.
    */
    enum draw_style
    {
        top_left,
        centered
    };

    /*
      Constructor: Font
      Construct a font from the specified alphabet file.
    */
    Font (const char* alphabet_path, int alphabet_width, int alphabet_height, int stride) {
        const char* err;
        font = C::font_from_file (alphabet_path, alphabet_width, alphabet_height, stride, &err);
        if (err) throw EXCEPTION ("Font creation failed");
    }

    /*
      Constructor: Font
      Construct a font from the given alphabet in memory.
    */
    Font (const U8* alphabet_pixels, int alphabet_width, int alphabet_height, int stride) {
        font = C::font_from_mem (alphabet_pixels, alphabet_width, alphabet_height, stride);
    }

    /*
      Destructor: ~Font
      Clean up the font.
    */
    ~Font () { C::font_free (&font); }

    /*
      Function: start
      Prepare OpenGL for text rendering.

      Parameters:

      mode: The mode to render text in.
    */
    void start (render_mode mode = screen_space) {
        C::font_start (font, (C::font_render_mode) mode);
    }

    /*
      Function: end
      End font rendering, restoring OpenGL to its original state.
    */
    void end () { C::font_end (font); }

    /*
      Function: render
      Render the given text.
    */
    void render (float px, float py, float pz,
                 const char* text, float font_size = 0, draw_style style = top_left) const {
        C::font_render (font, px, py, pz, text, font_size, (C::font_draw_style) style);
    }

    /*
      Function: render
      Render the given text.
    */
    void render (float xmin, float ymin, float zmin,
                 float xmax, float ymax, float zmax, const char* text) const {
        C::font_render_to_aabb (font, xmin, ymin, zmin, xmax, ymax, zmax, text);
    }
};

} // namespace OGDT
