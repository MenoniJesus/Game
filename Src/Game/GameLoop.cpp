#include "GameLoop.h"
#include "WorldGame.h"
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <iostream>

void GameLoop::Run() {
    WorldGame::GetInstance()->Init();

    Uint32 startTime = SDL_GetTicks();

    int frequencia = 22050;
    Uint16 formato = AUDIO_S16SYS;
    int canal = 2;
    int buffer = 4096;

    Mix_OpenAudio(frequencia, formato, canal, buffer);
    Mix_Music *musica;
    Mix_Chunk *efeitoSonoro1;

    efeitoSonoro1 = Mix_LoadWAV("../../audio/Sus.wav");
    musica = Mix_LoadMUS("../../audio/FFIdg.mp3");

    Mix_PlayChannel(-1, efeitoSonoro1, 0);
    Mix_PlayMusic(musica, -1);

    while (WorldGame::GetInstance()->IsRunning()) {
        WorldGame::GetInstance()->Events();
        WorldGame::GetInstance()->Update();
        WorldGame::GetInstance()->Render();
        Uint32 finalTime = SDL_GetTicks();
        float executionTime = static_cast<float>(finalTime - startTime) / 1000.0f;
        startTime = finalTime;
    }

    Mix_FreeChunk(efeitoSonoro1);
    Mix_FreeMusic(musica);
    Mix_CloseAudio();
    WorldGame::GetInstance()->Clean();
}