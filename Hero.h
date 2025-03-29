#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Interactable.h"
#include "Combatable.h"
#include "NPC.h"
#include "Item.h"

#include <vector>
#include <iostream>


class Hero : public Character, public Interactable, public Combatable {
private:
    std::vector<std::string> m_inventory;
    int m_level;
    int m_experiencePoints;

public:
    Hero(const std::string& n, int h, int ap, int def) : Character(n, h, ap, def), m_level(1), m_experiencePoints(0) {}
    void displayStats() const override; //from Character
    void takeDamage(int damage) override; //from Charactre
    void interact() override;  //from Interactable
    std::string getDialogue() const override;
    void attack(Character& character) override;    //from combatable
    void displayInventory() const;  
    int getLevel() const;
    int getXP() const;
    void gainXP(int xp);
    const std::vector<std::string>& getInventory() const;
    void useAbility(Character* character) override; 
    ~Hero();
};

#endif 