// Implement pure abstract interfaces (Interactable, Combatable)
// to define specific interaction and combat behaviors
// that can be dynamically applied to characters.
#ifndef INTERACTABLE_H
#define INTERACTABLE_H
#include "Character.h"
#include <string>

class Interactable {
public:
    virtual void interact() = 0;
    virtual std::string getDialogue() const = 0;
    virtual ~Interactable() = default;
};

#endif
