#include "SoundManager.h"
#include "GameLoop.h"
#include "WorldGame.h"
#include <SDL2/SDL.h>
#include <iostream>

void GameLoop::Run() {
    WorldGame::GetInstance()->Init();
    SoundManager::GetInstance()->Init();

    Uint32 startTime = SDL_GetTicks();

    SoundManager::GetInstance()->StartMusic("../../audio/testeV2.mp3");

    while (WorldGame::GetInstance()->IsRunning()) {
        Uint32 finalTime = SDL_GetTicks();
        float executionTime = static_cast<float>(finalTime - startTime) / 1000.0f;
        startTime = finalTime;

        WorldGame::GetInstance()->Events();
        WorldGame::GetInstance()->Update(executionTime);
        WorldGame::GetInstance()->Render();
    }

    SoundManager::GetInstance()->Clean();
    WorldGame::GetInstance()->Clean();
}