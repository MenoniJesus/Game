#include "InputController.h"
#include <SDL_mixer.h>

InputController* InputController::s_Instance = nullptr;

void InputController::handleKeyboardEvent(const SDL_Event& event) {

    int freq = 22050;
    Uint16 format = AUDIO_S16SYS;
    int channel = 2;
    int buffer = 4096;

    Mix_OpenAudio(freq, format, channel, buffer);
    Mix_Chunk *soundStep;

    soundStep = Mix_LoadWAV("../../audio/step_sound.wav");

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                SDL_Log("Up arrow key");
                //Mix_PlayChannel(-1, soundStep, 0);
                break;
            case SDLK_s:
                SDL_Log("Down arrow key");
                //Mix_PlayChannel(-1, soundStep, 0);
                break;
            case SDLK_a:
                SDL_Log("Left arrow key");
                //Mix_PlayChannel(-1, soundStep, 0);
                break;
            case SDLK_d:
                SDL_Log("Right arrow key");
                //Mix_PlayChannel(-1, soundStep, 0);
                break;
        }
    }
    Mix_FreeChunk(soundStep);
    Mix_CloseAudio();
}