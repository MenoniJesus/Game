#include "Persona.h"
#include "TextureManager.h"
#include "SoundManager.h"

Persona::Persona() {
    attributes.imagePath = "../../assets/persona.jpg";
    attributes.health = 50;
    attributes.width = 128;
    attributes.height = 160; 
    attributes.position = Vector2f(0.0f, 200.0f);
    attributes.velocity = Vector2f(0.0f, 0.0f);
}

Persona::~Persona() {
}

void Persona::Update(float deltaTime) {
    attributes.position[0] += attributes.velocity[0] * deltaTime;
    attributes.position[1] += attributes.velocity[1] * deltaTime;

    if (attributes.position[1] < 224) {
        attributes.position[1] = 224;
    } else if (attributes.position[1] > 480) {
        attributes.position[1] = 480;
    }

    if (attributes.position[0] < -20) {
        attributes.position[0] = -20;
    } else if (attributes.position[0] > 760) {
        attributes.position[0] = 760;
    }
}

void Persona::Render() {
    TextureManager::GetInstance()->Load("persona", attributes.imagePath);
    TextureManager::GetInstance()->Draw("persona", attributes.position[0], attributes.position[1], attributes.width, attributes.height);
}

void Persona::Events(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                attributes.velocity[1] = -112; 
                //SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
            case SDLK_s:
                attributes.velocity[1] = 112; 
                //SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
            case SDLK_a: 
                attributes.velocity[0] = -112; 
                //SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
            case SDLK_d:
                attributes.velocity[0] = 112; 
                //SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
        }
    } else if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
            case SDLK_s:
                attributes.velocity[1] = 0; 
                break;
            case SDLK_a:
            case SDLK_d:
                attributes.velocity[0] = 0; 
                break;
        }
    }
}