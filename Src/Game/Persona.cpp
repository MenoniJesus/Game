#include "Persona.h"
#include "TextureManager.h"
#include "SoundManager.h"

Persona::Persona() {
    attributes.imagePath = "../../assets/persona.jpg";
    attributes.health = 100;
    attributes.width = 100;
    attributes.height = 180; 
    attributes.position = Vector2f(0.0f, 220.0f);
}

Persona::~Persona() {
}

void Persona::Update() {
}

void Persona::Render() {
    TextureManager::GetInstance()->Load("persona", attributes.imagePath);
    TextureManager::GetInstance()->Draw("persona", attributes.position[0], attributes.position[1], attributes.width, attributes.height);
}

void Persona::Events(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                attributes.position[1] -= 16;
                SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
            case SDLK_s:
                attributes.position[1] += 16;
                SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
            case SDLK_a: 
                attributes.position[0] -= 16;
                SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
            case SDLK_d:
                attributes.position[0] += 16;
                SoundManager::GetInstance()->PlaySoundEffect("../../audio/step_sound.wav");
                break;
        }
    }
}
