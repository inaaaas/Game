//abstract base class
// Use an abstract base class Character to define 
//common attributes and behaviors 
//for all game characters (Heroes, Monsters, NPCs).
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>

class Character {
protected:
    std::string m_name;
    int m_health;
    int m_attackPower;
    int m_defense;

public:
    Character(const std::string& n, int h, int ap, int def);
    virtual void displayStats() const = 0;
    virtual void takeDamage(int damage) = 0;
    int getHealth() const;
    std::string getName() const;
    int getDefense() const;
    virtual ~Character() = default;
};

#endif