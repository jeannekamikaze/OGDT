#ifndef _MD2_RENDER_H
#define _MD2_RENDER_H

#include "MorphModel.h"


#ifdef __cplusplus
extern "C" {
#endif

/// Renders the given MD2 model.
/// 'currentFrame' corresponds to the current frame of animation.
/// 'p' is the linear interpolation coefficient.
/// The model is interpolated between frames 'frame1' and 'frame2'.
void MorphModel_render (const MorphModel* model, unsigned frame1, unsigned frame2, float p);


/// Renders the given MD2 model.
/// The model is rendered at frame 'currentFrame'.
void MorphModel_render_static (const MorphModel* model, unsigned int currentFrame);

#ifdef __cplusplus
}
#endif


#endif // _MD2_RENDER_H
