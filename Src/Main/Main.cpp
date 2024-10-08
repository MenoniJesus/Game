#ifdef __MINGW32__
    #define SDL_MAIN_HANDLED
#endif

#include <SDL2/SDL.h>
#include <iostream>
#include "../Game/WorldGame.h"

int main(int argc, char** argv){
    WorldGame::GetInstance()->Init();

    Uint32 startTime = SDL_GetTicks();

    while(WorldGame::GetInstance()->IsRunning()){
        WorldGame::GetInstance()->Events();
        WorldGame::GetInstance()->Update();
        WorldGame::GetInstance()->Render();
        Uint32 finalTime = SDL_GetTicks();
        long executionTime = (finalTime - startTime) / 1000.0f;
        startTime = finalTime;
        SDL_Log("Execution Time: %ld", executionTime);
    }

    WorldGame::GetInstance()->Clean();
    return 0;
}