#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <string>
#include "TextureManager.h"
#include "../GameObject/Mage.h"
#include "InputHandler.h"

class Engine {
public:
    static Engine* GetInstance() {
        if (a_Instance == nullptr) {
            a_Instance = new Engine();
        }
        return a_Instance;
    }

    bool Init();
    void Clean();
    void Quit();
    void Update();
    void Render();
    void Events();
    bool IsRunning() const { return m_IsRunning; }
    SDL_Renderer* GetRenderer() const { return m_Renderer; }

private:
    Engine() = default;
    static Engine* a_Instance;
    SDL_Window* m_Window = nullptr;
    SDL_Renderer* m_Renderer = nullptr;
    bool m_IsRunning = false;
    Mage mage;
    InputHandler inputHandler;
};

#endif // ENGINE_H