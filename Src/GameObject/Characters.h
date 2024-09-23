#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "object.h"

class Characters : public Object {
public:
    // Construtor
    Characters(float x = 0.0f, float y = 0.0f, int hp = 100) 
        : Object(x, y), health(hp) {}

    // Destrutor virtual puro, tornando esta classe abstrata
    virtual ~Characters() = 0;

    // Métodos para obter a vida
    int getHealth() const { return health; }

    // Métodos para definir a vida
    void setHealth(int hp) { health = hp; }

    // Método virtual puro para ser implementado pelas subclasses
    virtual void attack() = 0;

private:
    int health;
};

// Definição do destrutor puro fora da classe
inline Characters::~Characters() {}

#endif // CHARACTERS_H