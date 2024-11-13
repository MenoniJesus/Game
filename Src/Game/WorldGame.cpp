#include "WorldGame.h"
#include "TextureManager.h"
#include "Persona.h"
#include "SoundManager.h"

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
    if(!TextureManager::GetInstance()->Load(m_backgroundTextureID, "../../assets/FundoIFTECH.png")){
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
    m_slime.Update(deltaTime);

    if (CheckCollision(m_persona, m_slime)) {
        SoundManager::GetInstance()->PlaySoundEffect("../../audio/bonkMeme.wav"); 

        if (m_persona.GetPosition()[0] < m_slime.GetPosition()[0]) {
            m_persona.SetPosition(Vector2f(std::max(m_slime.GetPosition()[0] - m_persona.GetWidth(), -20.0f), m_persona.GetPosition()[1]));
        } else {
            m_persona.SetPosition(Vector2f(std::min(m_slime.GetPosition()[0] + m_slime.GetWidth(), 760.0f), m_persona.GetPosition()[1]));
        }

        if (m_persona.GetPosition()[1] < m_slime.GetPosition()[1]) {
            m_persona.SetPosition(Vector2f(m_persona.GetPosition()[0], std::max(m_slime.GetPosition()[1] - m_persona.GetHeight(), 224.0f)));
        } else {
            m_persona.SetPosition(Vector2f(m_persona.GetPosition()[0], std::min(m_slime.GetPosition()[1] + m_slime.GetHeight(), 480.0f)));
        }
    }
}

void WorldGame::Render(){
    SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
    SDL_RenderClear(m_Renderer);

    TextureManager::GetInstance()->Draw(m_backgroundTextureID, 0, 0, 840, 640);
    m_persona.Render();
    m_slime.Render();

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

bool WorldGame::CheckCollision(const Persona& persona, const Slime& slime) {
    float personaLeft = persona.GetPosition()[0];
    float personaRight = persona.GetPosition()[0] + 64;
    float personaTop = persona.GetPosition()[1];
    float personaBottom = persona.GetPosition()[1] + 64;

    float slimeLeft = slime.GetPosition()[0];
    float slimeRight = slime.GetPosition()[0] + 64;
    float slimeTop = slime.GetPosition()[1];
    float slimeBottom = slime.GetPosition()[1] + 64;

    return !(personaLeft >= slimeRight || personaRight <= slimeLeft || personaTop >= slimeBottom || personaBottom <= slimeTop);
}