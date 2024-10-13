#ifndef OBJECT_H
#define OBJECT_H

#include "Types.h"

#include <SDL2/SDL.h>

class Object {
    public:
        Object() : position(0.0f, 0.0f) {}
        virtual ~Object() {}

    protected:
        Vector2f position;
};

#endif // OBJECT_H