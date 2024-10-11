#ifndef OBJECT_H
#define OBJECT_H

#include "Types.h"

#include <SDL2/SDL.h>

class Object {
    public:
        Object() : position(0.0f, 0.0f) {}
        virtual ~Object() {}

        virtual void Update() = 0;
        virtual void Render() = 0;
        virtual void Events(SDL_Event& event) = 0;

    protected:
        Vector2f position;
};

#endif // OBJECT_H