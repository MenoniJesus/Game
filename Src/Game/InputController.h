#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <SDL2/SDL.h>
#include "Mage.h"
#include "SoundManager.h"

class InputController {
public:
    static InputController* GetInstance() {
        return s_Instance = (s_Instance != nullptr) ? s_Instance : new InputController();
    }

    void handleKeyboardEvent(const SDL_Event& event);
    void setMage(Mage* mage) { m_mage = mage; }

private:
    InputController() {}
    Mage* m_mage;

    static InputController* s_Instance;
};

#endif // INPUTCONTROLLER_H