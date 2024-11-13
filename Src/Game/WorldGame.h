#ifndef WORLDGAME_H
#define WORLDGAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Persona.h"
#include "Slime.h"

class WorldGame {
    public:
        static WorldGame* GetInstance() {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new WorldGame();
        }

        bool Init();
        bool Clean();
        void Quit();
        void Update(float deltaTime);
        void Render();
        void Events();

        inline bool IsRunning(){return m_IsRunning;}
        inline SDL_Renderer* GetRenderer(){return m_Renderer;}

    private:
        WorldGame(){}
        bool m_IsRunning;

        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;

        Persona m_persona;
        Slime m_slime;
        std::string m_backgroundTextureID;

        static WorldGame* s_Instance;

        bool CheckCollision(const Persona& persona, const Slime& slime);
};

#endif // WORLDGAME_H