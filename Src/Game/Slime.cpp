#include "Slime.h"
#include "TextureManager.h"

Slime::Slime() {
    attributes.imagePath = "../../assets/slime.png";
    attributes.health = 20;
    attributes.width = 112;
    attributes.height = 112;
    attributes.position = Vector2f(650.0f, 370.0f);
}

Slime::~Slime() {
}

void Slime::Update(float deltaTime) {
    static float totalTime = 0.0f;
    static int direction = 0;
    static float distanceMoved = 0.0f;
    const float moveDistance = 100.0f;

    totalTime += deltaTime;

    if (distanceMoved >= moveDistance) {
        direction = (direction + 1) % 4;
        distanceMoved = 0.0f;
    }

    float moveStep = 100.0f * deltaTime;

    switch (direction) {
        case 0:
            attributes.position[1] += moveStep;
            break;
        case 1: 
            attributes.position[0] -= moveStep;
            break;
        case 2:
            attributes.position[1] -= moveStep;
            break;
        case 3:
            attributes.position[0] += moveStep;
            break;
    }

    distanceMoved += moveStep;
}

void Slime::Render() {
    TextureManager::GetInstance()->Load("slime", attributes.imagePath);
    TextureManager::GetInstance()->Draw("slime", attributes.position[0], attributes.position[1], attributes.width, attributes.height);
}