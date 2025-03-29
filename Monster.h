#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
#include "Combatable.h"

class Monster : public Character, public Combatable {
private:
    std::string m_specialAbility;

public:
    Monster(const std::string& n, int h, int ap, int def, const std::string& ability);
    void displayStats() const override;  //from character
    void takeDamage(int damage) override;  //from character
    void attack(Character& character) override;  // from Combatable
    void useSpecialAbility(); 
    void useAbility(Character* target) override;
    ~Monster();
};

#endif
