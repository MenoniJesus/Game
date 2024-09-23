// object.h
#ifndef OBJECT_H
#define OBJECT_H

#include "math-vector.h"

class Object {
public:
    Object(float x = 0.0f, float y = 0.0f) : position(x, y) {}

    float getX() const { return position.x; }
    float getY() const { return position.y; }

    void setX(float x) { position.x = x; }
    void setY(float y) { position.y = y; }

    Mylib::Math::Vector2f getPosition() const { return position; }
    void setPosition(float x, float y) { position.set(x, y); }
    void setPosition(const Mylib::Math::Vector2f& pos) { position = pos; }

private:
    Mylib::Math::Vector2f position;
};

#endif // OBJECT_H