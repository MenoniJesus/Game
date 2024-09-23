// TextureManager.cpp
#include "TextureManager.h"
#include "Engine.h"

TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::Load(std::string id, std::string filename) {
    SDL_Surface* surface = SDL_LoadBMP(filename.c_str());
    if (!surface) return false;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
    SDL_FreeSurface(surface);

    if (texture) {
        m_TextureMap[id] = texture;
        return true;
    }
    return false;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip) {
    SDL_Rect srcRect = { 0, 0, width, height };
    SDL_Rect dstRect = { x, y, width, height };
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}