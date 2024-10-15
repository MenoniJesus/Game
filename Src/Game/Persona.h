#ifndef PERSONA_H
#define PERSONA_H

#include "Object.h"
#include "MathVector.h"
#include <string>

class Persona : public Object {
public:
    Persona();
    ~Persona();

    std::string GetImagePath() { return attributes.imagePath; }

    int GetHealth() { return attributes.health; } 
    void SetHealth(int health) { attributes.health = health; }

    Vector2f GetPosition() { return attributes.position; }
    void SetPosition(const Vector2f& position) { attributes.position = position; }

    void Update(float deltaTime);
    void Render();
    void Events(const SDL_Event& event); 

private:
    struct Attributes {
        std::string imagePath;
        int width;
        int height;
        int health;
        Vector2f position;
        Vector2f velocity;
    };

    Attributes attributes;
};

#endif // PERSONA_H