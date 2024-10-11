#ifndef MAGE_H
#define MAGE_H

#include "MathVector.h"
#include "Object.h"
#include <string>

class Mage : public Object {
    public:
        Mage();
        ~Mage();

        std::string GetImagePath() { return attributes.imagePath; }

        int GetHealth() { return attributes.health; } 
        void SetHealth(int health) { attributes.health = health; }

        Vector2f GetPosition() { return attributes.position; }
        void SetPosition(const Vector2f& position) { attributes.position = position; }

        void Update() override;
        void Render() override;
        void Events(SDL_Event& event) override; 

    private:
        struct Attributes{
            std::string imagePath;
            int width;
            int height;
            int health;
            Vector2f position;
        };

        Attributes attributes;
};

#endif // MAGE_H