#include <OGDT/Font.h>
#include <OGDT/Image.h>
#include <OGDT/Exception.h>
#include <OGDT/gl_utils.h>
#include <algorithm>
#include <cstring>


using namespace OGDT;


// Renders the given text.
// pos corresponds to the bottom left corner of the rendered text.
// size represents the size (width and height) of each letter in object space.
void renderText(const char* text, float px, float py, float pz, int font_size, int alphabet_width, float size);

void enter2D();
void leave2D();


Font::Font (const char* alphabet_path, int w, int h)
    : letter_stride (43), alphabet_width (w)
{
    Image img;
    Image::from_file (alphabet_path, img);
    glGenTextures (1, &tex);
    glBindTexture (GL_TEXTURE_2D, tex);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    gluBuild2DMipmaps (GL_TEXTURE_2D, GL_ALPHA, w, h, GL_ALPHA, GL_UNSIGNED_BYTE, img);
    glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glBindTexture (GL_TEXTURE_2D, 0);
}


Font::~Font ()
{
    glDeleteTextures(1, &tex);
}


void Font::startRender (render_mode mode)
{
    glPushAttrib(GL_LIGHTING_BIT);
    glPushAttrib(GL_POLYGON_BIT);
    glPushAttrib(GL_DEPTH_BUFFER_BIT);
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glPolygonMode(GL_FRONT, GL_FILL);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    
    this->mode = mode;
    if (mode == screen_space) enter2D();
}


void Font::endRender ()
{
    if (mode == screen_space) leave2D();
    
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
    
    glPopAttrib();
    glPopAttrib();
    glPopAttrib();
}


void Font::render (float xmin, float ymin, float zmin, float xmax, float ymax, float zmax, const char* text) const
{
    // Compute the size of the longest line and total height to determine the font's size.
    int width  = 0;
    int height = 1;
    int currentWidth = 0;
    size_t len = strlen (text);
    
    const char* ptr = text;
    const char* end = ptr + len;
    for (; ptr != end; ++ptr)
    {
        char c0 = *ptr;
        char c1 = *(ptr+1);
        
        if (c0 == '\n' || (c0 == '\\' && c1 == 'n'))
        {
            height++;
            width = std::max (width, currentWidth);
            currentWidth = 0;
            if (c0 != '\n') ptr++;
        }
        else currentWidth++;
    }
    
    if (text[len-1] != '\n')
    {
        width = std::max (width, currentWidth);
    }
    
    float font_width  = (xmax - xmin) / (float) width;
    float font_height = (ymax - ymin) / (float) height;
    float font_size   = std::min (font_width, font_height);
    
    /*vec3 topLeft = min;
    topLeft.y = max.y;*/
    float xtl = xmin;
    float ytl = ymax;
    float ztl = zmin;
    
    renderText (text, xtl, ytl, ztl, letter_stride, alphabet_width, font_size);
}


void Font::render (float px, float py, float pz, const char* text, float font_size, draw_style style) const
{
    float xpos, ypos, zpos;

    size_t len = strlen (text);
    
    // Compute the text origin.
    switch (style)
    {
    case centered:
    {
        // Compute average line size and number of lines.
        int sum = 0;
        int line_size = 0;
        int num_lines = 1;
        
        const char* ptr = text;
        const char* end = ptr + len;
        for (; ptr != end; ++ptr)
        {
            char c0 = *ptr;
            char c1 = *(ptr+1);
            
            if (c0 == '\n' || (c0 == '\\' && c1 == 'n'))
            {
                sum += line_size;
                line_size = 0;
                num_lines++;
                if (c0 != '\n') ptr++;
            }
            else line_size += 1;
        }
        sum += line_size;
        int avg_size = sum / num_lines;
        
        // pos_ = pos - up3 * font_size * num_lines - right3 * avg_size / 2 * font_size;
        xpos = px - avg_size / 2 * font_size;
        ypos = py - font_size * num_lines;
        zpos = pz;
        break;
    }
        
    case top_left:
        //pos_ = pos - up3 * font_size;
        xpos = px;
        ypos = py - font_size;
        zpos = pz;
        break;
        
    default: break;
    }
    
    renderText(text, xpos, ypos, zpos, letter_stride, alphabet_width, font_size);
}


void renderText (const char* text, float px, float py, float pz, int letter_stride, int alphabet_width, float size)
{
    float starting_x = px;
    float stride = (float) letter_stride / (float) alphabet_width;
    
    glBegin (GL_QUADS);
    
    for (const char* ptr = text; *ptr; ++ptr)
    {
        char c = *ptr;
        char c1 = *(ptr+1);
        
        if (c == '\n' || (c == '\\' && c1 == 'n')) //eol
        {
            py -= size;
            px = starting_x;
            if (c != '\n') ptr++;
        }
        else
        {
            if (c < 0x20 || c >= 127) c = '?';
            
            float x;
            if (c == 0x20) x = 0;
            else
            {
                x = (c - 0x20) * stride;
            }
            
            // Render quad for this character.
            
            glTexCoord2f(x, 1.0);
            glVertex3f(px, py, pz);
            
            glTexCoord2f(x + stride, 1.0);
            glVertex3f(px + size, py, pz);
            
            glTexCoord2f(x + stride, 0.0);
            glVertex3f(px + size, py + size, pz);
            
            glTexCoord2f(x, 0.0);
            glVertex3f(px, py + size, pz);
            
            if (c == 0x20) px += size/2; //make spaces thinner
            else px += size;
        }
    }
    
    glEnd ();
}


void enter2D ()
{
    int vPort[4];
    
    glGetIntegerv(GL_VIEWPORT, vPort);
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, vPort[2], 0, vPort[3], -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
}


void leave2D ()
{
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}
