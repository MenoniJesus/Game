#ifndef MAGE_H
#define MAGE_H

#include <SDL2/SDL.h>
#include <string>
#include "../MundoDeJogo/TextureManager.h"

class Mage {
public:
    void setImage(const std::string& id) {
        m_TextureID = id;
    }

    void render(SDL_Renderer* renderer) {
        TextureManager::GetInstance()->Draw(m_TextureID, m_X, m_Y, m_Width, m_Height, SDL_FLIP_NONE);
    }

    void handleInput(const SDL_Event& event) {
        
    }

    int getX() const { return m_X; }
    int getY() const { return m_Y; }
    void setX(int x) { m_X = x; }
    void setY(int y) { m_Y = y; }

private:
    std::string m_TextureID;
    int m_X = 100; 
    int m_Y = 100; 
    int m_Width = 64; 
    int m_Height = 64; 
};

#endif // MAGE_H