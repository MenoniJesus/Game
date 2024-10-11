#include "GameLoop.h"
#include "WorldGame.h"
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <iostream>

void GameLoop::Run() {
    WorldGame::GetInstance()->Init();

    Uint32 startTime = SDL_GetTicks();

    int freq = 22050;
    Uint16 format = AUDIO_S16SYS;
    int channel = 2;
    int buffer = 4096;

    Mix_OpenAudio(freq, format, channel, buffer);
    Mix_Music *music;

    music = Mix_LoadMUS("../../audio/testeV2.mp3");

    Mix_PlayMusic(music, -1);

    while (WorldGame::GetInstance()->IsRunning()) {
        WorldGame::GetInstance()->Events();
        WorldGame::GetInstance()->Update();
        WorldGame::GetInstance()->Render();
        Uint32 finalTime = SDL_GetTicks();
        float executionTime = static_cast<float>(finalTime - startTime) / 1000.0f;
        startTime = finalTime;
    }
    
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    WorldGame::GetInstance()->Clean();
}