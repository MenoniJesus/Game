// Mage.h
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
        // Lógica para lidar com a entrada do mago
    }

private:
    std::string m_TextureID;
    int m_X = 100; // Posição inicial X
    int m_Y = 100; // Posição inicial Y
    int m_Width = 64; // Largura da imagem
    int m_Height = 64; // Altura da imagem
};

#endif // MAGE_H
