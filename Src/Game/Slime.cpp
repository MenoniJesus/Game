#include "Slime.h"
#include "TextureManager.h"

Slime::Slime() {
    attributes.imagePath = "../../assets/slime.png";
    attributes.health = 50;
    attributes.width = 96;
    attributes.height = 96;
    attributes.position = Vector2f(500.0f, 400.0f);
}

Slime::~Slime() {
}

void Slime::Update(float deltaTime) {
    
}

void Slime::Render(float deltaTime) {
    static int frame = 0;
    static float frameTime = 0.0f;
    const float frameDuration = 0.8f;

    frameTime += deltaTime;
    if (frameTime >= frameDuration) {
        frame = (frame + 1) % 3;
        frameTime = 0.0f;
    }

    int frameX = frame * attributes.width;
    int frameY = 0;

    TextureManager::GetInstance()->Load("slime", attributes.imagePath);
    TextureManager::GetInstance()->DrawFrame("slime", attributes.position[0], attributes.position[1], attributes.width, attributes.height, frameX, frameY);
}