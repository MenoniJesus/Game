#include "Engine.h"
#include <iostream>

Engine* Engine::a_Instance = nullptr;

bool Engine::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_Window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 720, SDL_WINDOW_SHOWN);
    if (!m_Window) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    if (!m_Renderer) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Inicializar SDL_image
    if (!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG)) {
        std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
        return false;
    }

    if (!TextureManager::GetInstance()->Load("mage", "../../assets/mage.jpg")) {
        std::cout << "Failed to load texture: mage" << std::endl;
        return false;
    }

    mage.setImage("mage"); 

    m_IsRunning = true;
    std::cout << "Initialization successful" << std::endl;
    return true;
}

void Engine::Clean() {
    std::cout << "Cleaning up" << std::endl;
    if (m_Renderer) SDL_DestroyRenderer(m_Renderer);
    if (m_Window) SDL_DestroyWindow(m_Window);
    IMG_Quit(); 
    SDL_Quit();
}

void Engine::Quit() {
    std::cout << "Quitting" << std::endl;
    m_IsRunning = false;
}

void Engine::Update() {
    inputHandler.HandleInput(mage);
}

void Engine::Render() {
    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 255, 255); 
    SDL_RenderClear(m_Renderer);
    mage.render(m_Renderer); 
    SDL_RenderPresent(m_Renderer);
}

void Engine::Events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            Quit();
        }
        mage.handleInput(event); 
    }
}