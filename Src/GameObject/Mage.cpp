#include "Mage.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

Mage::Mage() : texture(nullptr){
     std::cout << "Mage created!" << std::endl;
}

Mage::~Mage(){
     if (texture)
     {
          SDL_DestroyTexture(texture);
     }
     std::cout << "Mage destroyed!" << std::endl;
}

void Mage::castFireball(){
     std::cout << "Casting Fireball!" << std::endl;
}

void Mage::handleInput(SDL_Event &event){
     if (event.type == SDL_KEYDOWN)
     {
          switch (event.key.keysym.sym)
          {
          case SDLK_f:
               castFireball();
               break;
          default:
               std::cout << "Unknown input!" << std::endl;
               break;
          }
     }
}

void Mage::setImage(const std::string &imagePath){
     this->imagePath = imagePath;
     SDL_Surface *surface = IMG_Load(imagePath.c_str());
     if (!surface)
     {
          std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
          return;
     }
     texture = SDL_CreateTextureFromSurface(renderer, surface);
     SDL_FreeSurface(surface);
     if (!texture)
     {
          std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
          return;
     }
     SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);
     std::cout << "Image set to: " << imagePath << std::endl;
}

void Mage::render(SDL_Renderer *renderer){
     if (texture)
     {
          SDL_RenderCopy(renderer, texture, nullptr, &destRect);
     }
}