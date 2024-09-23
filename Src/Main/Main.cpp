#ifdef __MINGW32__
    #define SDL_MAIN_HANDLED
#endif

#include <SDL.h>
#include <iostream>
#include "../MundoDeJogo/Engine.h"

int main(int argc, char** argv) {
    if (!Engine::GetInstance()->Init()) {
        std::cout << "Engine initialization failed" << std::endl;
        return -1;
    }

    while (Engine::GetInstance()->IsRunning()) {
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
    }

    Engine::GetInstance()->Clean();
    std::cout << "Engine cleaned up and exited" << std::endl;
    return 0;
}