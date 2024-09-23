#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>

class TextureManager {
public:
    static TextureManager* GetInstance() {
        if (s_Instance == nullptr) {
            s_Instance = new TextureManager();
        }
        return s_Instance;
    }

    bool Load(std::string id, std::string filename);
    void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
    SDL_Texture* GetTexture(std::string id) { return m_TextureMap[id]; }

private:
    TextureManager() = default;
    static TextureManager* s_Instance;
    std::map<std::string, SDL_Texture*> m_TextureMap;
};

#endif // TEXTUREMANAGER_H