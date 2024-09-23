#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL2/SDL.h>
#include "../GameObject/Mage.h"

class InputHandler {
public:
    void HandleInput(Mage& mage);
};

#endif // INPUTHANDLER_H