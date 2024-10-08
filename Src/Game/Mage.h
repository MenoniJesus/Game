#ifndef MAGE_H
#define MAGE_H

#include "MathVector.h"
#include "Object.h"
#include <string>

class Mage : public Object {
    public:
        Mage();
        ~Mage();

        std::string GetImagePath();

        int GetHealth();
        void SetHealth(int health);

        Mylib::Math::Vector2f GetPosition();
        void SetPosition(const Mylib::Math::Vector2f& position);

        void Update() override;
        void Render() override;
        void Events(SDL_Event& event) override;

    private:
        typedef struct Attributes{
            std::string imagePath;
            int width;
            int height;
            int health;
            Mylib::Math::Vector2f position;
        } Attributes;

        Attributes attributes;
};

#endif // MAGE_H