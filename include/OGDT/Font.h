#pragma once

#include <OGDT/OGDT.h>
#include <OGDT/types.h>

/*
Class: Font
A class for rendering text in 2D and 3D.
*/
class DECLDIR Font
{    
public:
    
    /*
    Enum: render_mode

    screen_space - Render directly in viewport coordinates.
    world_space - Render in world space.
    */
    enum render_mode
    {
        screen_space,
        world_space
    };
    
    /*
    Enum: draw_style

    top_left - Interpret the given position as the text's top left corner.
    centered - Interpret the given position as the text's center.
    */
    enum draw_style
    {
        top_left,
        centered
    };
    
private:
    
    unsigned    tex;            // Texture id.
    int         letter_stride;    // Stride between letters in the texture.
    int         alphabet_width; // Width of the font image.
    render_mode mode;            // Current render mode.
    
    Font (const Font&);
    Font& operator= (const Font&);
    
public:
    
    /*
    Constructor: Font
    Construct a font from the specified alphabet file.
    */
    Font (const char* alphabet_path, int alphabet_width, int alphabet_height);

    /*
    Constructor: Font
    Construct a font from the given alphabet in memory.
    */
    Font (const U8* alphabet_path, int alphabet_width, int alphabet_height);

    /*
    Destructor: ~Font
    Clean up the font.
    */
    ~Font ();
    
    /*
    Function: startRender
    Prepare OpenGL for text rendering.
    
    Parameters:
    
    mode: The mode to render text in.
    */
    void startRender (render_mode mode = world_space);
    
    /*
    Function: endRender
    End font rendering, restoring OpenGL to its original state.
    */
    void endRender ();
    
    /*
    Function: render
    Render the given text.
    */
    void render (float xmin, float ymin, float zmin, float xmax, float ymax, float zmax, const char* text) const;
    
    /*
    Function: render
    Render the given text.
    */
    void render (float px, float py, float pz, const char* text, float font_size = 12, draw_style style = top_left) const;
};
