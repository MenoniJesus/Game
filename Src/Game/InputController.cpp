#include "InputController.h"

InputController* InputController::s_Instance = nullptr;

void InputController::handleKeyboardEvent(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                SDL_Log("Up arrow key");
                SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
            case SDLK_s:
                SDL_Log("Down arrow key");
                SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
            case SDLK_a:
                SDL_Log("Left arrow key");
                SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
            case SDLK_d:
                SDL_Log("Right arrow key");
                SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
        }
    }
}