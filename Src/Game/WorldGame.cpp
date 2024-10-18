#include "WorldGame.h"
#include "TextureManager.h"
#include "Persona.h"

WorldGame* WorldGame::s_Instance = nullptr;

bool WorldGame::Init(){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return false;
    }

    m_Window = SDL_CreateWindow("Demo da Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 840, 640, 0);
    if(m_Window == nullptr){
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(m_Renderer == nullptr){
        SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
        return false;
    }

    m_backgroundTextureID = "background";
    if(!TextureManager::GetInstance()->Load(m_backgroundTextureID, "../../assets/telaDeFundo.png")){
        return false;
    }

    return m_IsRunning = true;
}

bool WorldGame::Clean(){
    TextureManager::GetInstance()->Drop(m_backgroundTextureID);
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
    return true;
}

void WorldGame::Quit(){
    m_IsRunning = false;
}

void WorldGame::Update(float deltaTime){
    m_persona.Update(deltaTime);
}

void WorldGame::Render(){
    SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
    SDL_RenderClear(m_Renderer);

    TextureManager::GetInstance()->Draw(m_backgroundTextureID, 0, 0, 840, 640);
    m_persona.Render();

    SDL_RenderPresent(m_Renderer);
}

void WorldGame::Events(){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type){
            case SDL_QUIT:
                Quit();
                break;
            default:
                m_persona.Events(event);
                break;
        }
    }
}