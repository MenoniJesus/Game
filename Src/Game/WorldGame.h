#ifndef WORDLGAME_H
#define WORDLGAME_H

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "Mage.h"

class WorldGame {
    public:
        static WorldGame* GetInstance() {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new WorldGame();
        }

        bool Init();
        bool Clean();
        void Quit();

        void Update();
        void Render();
        void Events();

        inline bool IsRunning(){return m_IsRunning;}
        inline SDL_Renderer* GetRenderer(){return m_Renderer;}

    private:
        WorldGame(){}
        bool m_IsRunning;

        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;

        static WorldGame* s_Instance;
};

#endif // WORDLGAME_H
