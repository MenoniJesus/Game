// Engine.cpp
#include "Engine.h"

Engine* Engine::a_Instance = nullptr;

bool Engine::Init() {
    m_Window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 720, SDL_WINDOW_SHOWN);
    if (!m_Window) return false;

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    if (!m_Renderer) return false;

    if (!TextureManager::GetInstance()->Load("mage", "../../assets/mage.jpg")) {
        return false;
    }

    mage.setImage("mage"); // Definir a imagem do mago

    m_IsRunning = true;
    return true;
}

void Engine::Clean() {
    if (m_Renderer) SDL_DestroyRenderer(m_Renderer);
    if (m_Window) SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

void Engine::Quit() {
    m_IsRunning = false;
}

void Engine::Update() {
    // Atualização do jogo
}

void Engine::Render() {
    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 255, 255); // Definir cor de fundo azul
    SDL_RenderClear(m_Renderer);
    mage.render(m_Renderer); // Renderizar o mago
    SDL_RenderPresent(m_Renderer);
}

void Engine::Events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            Quit();
        }
        mage.handleInput(event); // Lidar com a entrada do mago
    }
}