#include "TextureManager.h"
#include "WorldGame.h"

TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::Load(std::string id, std::string filename){
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if(surface == nullptr){
        SDL_Log("IMG_Load Error: %s, %s", filename.c_str(), SDL_GetError());
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(WorldGame::GetInstance()->GetRenderer(), surface);
    if(texture == nullptr){
        SDL_Log("SDL_CreateTextureFromSurface Error: %s", SDL_GetError());
        return false;
    }

    m_TextureMap[id] = texture;
    return true;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip){
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect destRect = {x, y, width, height};
    SDL_RenderCopyEx(WorldGame::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &destRect, 0, NULL, flip);
}

void TextureManager::Drop(std::string id){
    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);
}

void TextureManager::Clean(){
    std::map<std::string, SDL_Texture*>::iterator it;
    for(it = m_TextureMap.begin(); it != m_TextureMap.end(); it++){
        SDL_DestroyTexture(it->second);
    }

    m_TextureMap.clear();
}