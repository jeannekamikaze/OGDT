#include <OGDT/model.h>

using namespace OGDT;

struct ModelInstance::_impl
{
    const Model& model;

    const Animation* anim;
    bool animation_active;
    bool loop;
    float t;
    float speed;

    _impl (const Model& _model)
        : model (_model), anim (nullptr), animation_active (false)
        , loop (false), t (0.0f), speed (1.0f) {}
};

ModelInstance::ModelInstance (const Model& model)
    : impl (new _impl(model)) {}

ModelInstance::~ModelInstance () {
    delete impl;
}

void ModelInstance::update (float dt) {
    if (impl->animation_active) {
        dt *= impl->speed;
        impl->t += dt;
        if (impl->loop) {
            if (impl->t > impl->anim->duration) {
                impl->t = impl->t - impl->anim->duration;
            }
        }
        else if (impl->t > impl->anim->duration - 1) {
                impl->t = impl->anim->duration - 1;
                impl->animation_active = false;
        }
    }
}

void ModelInstance::setAnimation (const char* name, bool loop) {
    impl->anim = impl->model.getAnimation(name);
    if (impl->anim) {
        impl->animation_active = true;
        impl->loop = loop;
        impl->t = 0.0f;
    }
    else impl->animation_active = false;
}

const char* ModelInstance::getAnimation () const {
    if (impl->anim) return impl->anim->name;
    else return "";
}

void ModelInstance::setAnimationSpeed (float speed) {
    impl->speed = speed;
}

bool ModelInstance::isAnimationDone () const {
    return !impl->animation_active;
}

bool ModelInstance::isAnimated () const {
    return impl->model.isAnimated();
}

void ModelInstance::render () const {
    if (impl->model.isAnimated()) {
        impl->model.render (impl->t, impl->anim);
    }
    else impl->model.render ();
}
