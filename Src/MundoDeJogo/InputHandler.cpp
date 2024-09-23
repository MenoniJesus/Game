#include "InputHandler.h"

void InputHandler::HandleInput(Mage& mage) {
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);

    if (keystate[SDL_SCANCODE_UP]) {
        mage.setY(mage.getY() - 1);
    }
    if (keystate[SDL_SCANCODE_DOWN]) {
        mage.setY(mage.getY() + 1);
    }
    if (keystate[SDL_SCANCODE_LEFT]) {
        mage.setX(mage.getX() - 1);
    }
    if (keystate[SDL_SCANCODE_RIGHT]) {
        mage.setX(mage.getX() + 1);
    }
}