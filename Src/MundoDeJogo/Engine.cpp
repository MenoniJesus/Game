#include "Engine.h"
#include "../MundoDeJogo/TextureManager.h"

int Engine::mageX = 200;
int Engine::mageY = 100;
int Engine::gelecaX = 600;
int Engine::gelecaY = 300;
Engine::Direction Engine::gelecaDirection = LEFT;

Engine* Engine::a_Instance = nullptr;

bool Engine::Init(){
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0){
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError()); 
        return false;
    }

    m_Window = SDL_CreateWindow("Teste", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);   
    if(m_Window == nullptr){
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(m_Renderer == nullptr){
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

    TextureManager::GetInstance()->Load("Geleca", "../../assets/gosmaVermelha.jpg");
    TextureManager::GetInstance()->Load("Mage", "../../assets/mage.jpg");
    return m_IsRunning = true;
}

void Engine::Update() {
    UpdateGeleca();
}

void Engine::UpdateGeleca() {
    switch (gelecaDirection) {
        case LEFT:
            gelecaX -= 2;
            if (gelecaX <= 500) {
                gelecaDirection = UP;
            }
            break;
        case UP:
            gelecaY -= 2;
            if (gelecaY <= 200) {
                gelecaDirection = RIGHT;
            }
            break;
        case RIGHT:
            gelecaX += 2;
            if (gelecaX >= 700) {
                gelecaDirection = DOWN;
            }
            break;
        case DOWN:
            gelecaY += 2;
            if (gelecaY >= 400) {
                gelecaDirection = LEFT;
            }
            break;
    }
}

void Engine::Render(){
    SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
    SDL_RenderClear(m_Renderer);

    TextureManager::GetInstance()->Draw("Geleca", gelecaX, gelecaY, 128, 128);
    TextureManager::GetInstance()->Draw("Mage", mageX, mageY, 192, 192);
    SDL_RenderPresent(m_Renderer);
    
    SDL_Delay(1000/60);
}

void Engine::Events(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            Quit();
            break;
        
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_LEFT){
                mageX -= 10;
                Engine::Render();
            } else if(event.key.keysym.sym == SDLK_RIGHT){
                mageX += 10;
                Engine::Render();
            } else if(event.key.keysym.sym == SDLK_UP){
                mageY -= 10;
                Engine::Render();
            } else if(event.key.keysym.sym == SDLK_DOWN){
                mageY += 10;
                Engine::Render();
            } else {
                SDL_Log("Infelizmente ainda nao faz nada :(");
            }
            break;
    }
}

bool Engine::Clean(){
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();
}

void Engine::Quit(){
    m_IsRunning = false;
}