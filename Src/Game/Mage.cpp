#include "Mage.h"
#include "TextureManager.h"

Mage::Mage() {
    attributes.imagePath = "../../assets/mage.jpg";
    attributes.health = 100;
    attributes.width = 4;
    attributes.height = 4; 
    attributes.position = Mylib::Math::Vector2f(0.0f, 0.0f);
}

Mage::~Mage() {
}

std::string Mage::GetImagePath() {
    return attributes.imagePath;
}

int Mage::GetHealth() {
    return attributes.health;
}

void Mage::SetHealth(int health) {
    attributes.health = health;
}

Mylib::Math::Vector2f Mage::GetPosition() {
    return attributes.position;
}

void Mage::SetPosition(const Mylib::Math::Vector2f& position) {
    attributes.position = position;
}

void Mage::Update() {
}

void Mage::Render() {
}

void Mage::Events(SDL_Event& event) {
}