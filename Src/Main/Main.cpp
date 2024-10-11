#ifdef __MINGW32__
    #define SDL_MAIN_HANDLED
#endif

#include <SDL2/SDL.h>
#include <iostream>
#include "../Game/GameLoop.h"

int main(int argc, char** argv) {
    GameLoop gameLoop;
    gameLoop.Run();
    return 0;
}