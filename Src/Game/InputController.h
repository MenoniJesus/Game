#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <SDL2/SDL.h>

class InputController {
    public:
        static InputController* GetInstance() {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new InputController();
        }

        void handleKeyboardEvent(const SDL_Event& event);

    private:
        InputController() {}
        void onKeyDown(const SDL_KeyboardEvent& keyEvent);

        static InputController* s_Instance;
};

#endif // INPUTCONTROLLER_H