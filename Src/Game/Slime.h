#ifndef SLIME_H
#define SLIME_H

#include "Object.h"
#include "MathVector.h"
#include <string>

class Slime : public Object {
public:
    Slime();
    ~Slime();

    std::string GetImagePath() const { return attributes.imagePath; }

    int GetHealth() const { return attributes.health; } 
    void SetHealth(int health) { attributes.health = health; }

    Vector2f GetPosition() const { return attributes.position; }
    void SetPosition(const Vector2f& position) { attributes.position = position; }

    int GetWidth() const { return attributes.width; }
    int GetHeight() const { return attributes.height; }

    void Update(float deltaTime);
    void Render();

private:
    struct Attributes {
        std::string imagePath;
        int width;
        int height;
        int health;
        Vector2f position;
    };

    Attributes attributes;
};

#endif // SLIME_H