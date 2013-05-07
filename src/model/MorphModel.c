#include "MorphModel.h"
#include <math.h>
#include <stdlib.h> // free
#include <string.h> // strcmp

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

#ifndef __GNUC__ // Not compiling with GNU C compiler
float fmin (float a, float b)
{
    return a <= b ? a : b;
}

float fmax (float a, float b)
{
    return a >= b ? a : b;
}
#endif


static const float TO_RAD = M_PI / 180.0f;


static void safe_free (void* ptr)
{
    if (ptr)
    {
        free (ptr);
        ptr = 0;
    }
}


void model_free (MorphModel* model)
{
    safe_free (model->vertices);
    safe_free (model->normals);
    safe_free (model->texCoords);
    safe_free (model->triangles);
    safe_free (model->skins);
    safe_free (model->animations);
}


void model_scale (MorphModel* model, float sx, float sy, float sz)
{
    unsigned i;
    unsigned n = model->numVertices * model->numFrames;
    vec3* v = model->vertices;
    for (i = 0; i < n; ++i, ++v)
    {
        v->x *= sx;
        v->y *= sy;
        v->z *= sz;
    }
}


void model_pitch (MorphModel* model, float angle)
{
    unsigned i;
    unsigned n = model->numVertices * model->numFrames;
    vec3* v = model->vertices;
    float sa = sin (angle * TO_RAD);
    float ca = cos (angle * TO_RAD);
    for (i = 0; i < n; ++i, ++v)
    {
        vec3 p = *v;
        v->y = p.y * ca - p.z * sa;
        v->z = p.y * sa + p.z * ca;
    }
}


void model_yaw (MorphModel* model, float angle)
{
    unsigned i;
    unsigned n = model->numVertices * model->numFrames;
    vec3* v = model->vertices;
    float sa = sin (angle * TO_RAD);
    float ca = cos (angle * TO_RAD);
    for (i = 0; i < n; ++i, ++v)
    {
        vec3 p = *v;
        v->x =  p.x * ca + p.z * sa;
        v->z = -p.x * sa + p.z * ca;
    }
}


void model_roll (MorphModel* model, float angle)
{
    unsigned i;
    unsigned n = model->numVertices * model->numFrames;
    vec3* v = model->vertices;
    float sa = sin (angle * TO_RAD);
    float ca = cos (angle * TO_RAD);
    for (i = 0; i < n; ++i, ++v)
    {
        vec3 p = *v;
        v->x = p.x * ca - p.y * sa;
        v->y = p.x * sa + p.y * ca;
    }
}


void model_to_ground (MorphModel* model)
{
    unsigned i, f;
    vec3* v = model->vertices;

    // Compute the minimum y coordinate for each frame and translate
    // the model appropriately.
    for (f = 0; f < model->numFrames; ++f)
    {
        vec3* w = v;
        float y = v->y;

        for (i = 0; i < model->numVertices; ++i, ++v)
        {
            y = fmin (y, v->y);
        }

        v = w;
        for (i = 0; i < model->numVertices; ++i, ++v)
        {
            v->y -= y;
        }
    }
}


void model_compute_boxes (MorphModel* model, float* points)
{
    unsigned f;
    vec3* v = model->vertices;
    for (f = 0; f < model->numFrames; ++f)
    {
        float xmin = v->x;
        float xmax = v->x;
        float ymin = v->y;
        float ymax = v->y;
        float zmin = v->z;
        float zmax = v->z;

        unsigned i;
        for (i = 0; i < model->numVertices; ++i, ++v)
        {
            xmin = fmin (xmin, v->x);
            ymin = fmin (ymin, v->y);
            zmin = fmin (zmin, v->z);
            xmax = fmax (xmax, v->x);
            ymax = fmax (ymax, v->y);
            zmax = fmax (zmax, v->z);
        }

        *points++ = xmin; *points++ = ymin; *points++ = zmin;
        *points++ = xmax; *points++ = ymax; *points++ = zmax;
    }
}


void model_compute_aabb
    (MorphModel* model, unsigned frame,
    float* xmin, float* xmax, float* ymin, float* ymax, float* zmin, float* zmax)
{
    model_compute_aabb_se (model, frame, frame, xmin, xmax, ymin, ymax, zmin, zmax);
}


void model_compute_aabb_se
    (MorphModel* model, unsigned frame_start, unsigned frame_end,
    float* xmin, float* xmax, float* ymin, float* ymax, float* zmin, float* zmax)
{
    vec3 vmin, vmax;
    unsigned i;
    unsigned n = model->numVertices * (frame_end - frame_start + 1);
    vec3* v = model->vertices + frame_start * model->numVertices;
    vmin = *v;
    vmax = *v;
    for (i = 0; i < n; ++i, ++v)
    {
        vmin.x = fmin (vmin.x, v->x);
        vmax.x = fmax (vmax.x, v->x);
        vmin.y = fmin (vmin.y, v->y);
        vmax.y = fmax (vmax.y, v->y);
        vmin.z = fmin (vmin.z, v->z);
        vmax.z = fmax (vmax.z, v->z);
    }
    *xmin = vmin.x;
    *xmax = vmax.x;
    *ymin = vmin.y;
    *ymax = vmax.y;
    *zmin = vmin.z;
    *zmax = vmax.z;
}


void model_compute_anim_aabb
    (MorphModel* model, const char* anim_name,
    float* xmin, float* xmax, float* ymin, float* ymax, float* zmin, float* zmax)
{
    unsigned i;
    unsigned n = model->numAnimations;
    animation* a = model->animations;
    for (i = 0; i < n; ++i, ++a)
    {
        if (strcmp (a->name, anim_name) == 0)
        {
            model_compute_aabb_se (model, a->start, a->end, xmin, xmax, ymin, ymax, zmin, zmax);
            break;
        }
    }
}


animation* model_find_animation (MorphModel* model, const char* name)
{
    unsigned i;
    unsigned n = model->numAnimations;
    animation* anim = model->animations;
    for (i = 0; i < n; ++i, ++anim)
    {
        if (strcmp (anim->name, name) == 0) return anim;
    }
    return 0;
}
