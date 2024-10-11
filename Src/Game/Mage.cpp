#include "Mage.h"
#include "TextureManager.h"

Mage::Mage() {
    attributes.imagePath = "../../assets/mage.jpg";
    attributes.health = 100;
    attributes.width = 64;
    attributes.height = 64; 
    attributes.position = Vector2f(0.0f, 0.0f);
}

Mage::~Mage() {
}

void Mage::Update() {
    //movimentação aqui
}

void Mage::Render() {
    TextureManager::GetInstance()->Load("mage", attributes.imagePath);
    TextureManager::GetInstance()->Draw("mage", attributes.position[0], attributes.position[1], attributes.width, attributes.height);
}

void Mage::Events(SDL_Event& event) {
}