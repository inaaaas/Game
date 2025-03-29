// Implement pure abstract interfaces (Interactable, Combatable)
// to define specific interaction and combat behaviors
// that can be dynamically applied to characters.
#ifndef COMBATABLE_H
#define COMBATABLE_H
#include "Character.h"
#include <string>

class Combatable {
public:
    virtual void attack(Character& character) = 0;
    virtual void useAbility(Character* character) = 0;
    virtual ~Combatable() = default;
};

#endif
