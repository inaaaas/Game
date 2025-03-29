#include "Monster.h"
#include <iostream>

Monster::Monster(const std::string& n, int h, int ap, int def, const std::string& ability)
    : Character(n, h, ap, def), m_specialAbility(ability) {}

void Monster::displayStats() const {
    std::cout << "Monster Name: " << m_name << std::endl;
    std::cout << "Health: " << m_health << std::endl;
    std::cout << "Attack Power: " << m_attackPower << std::endl;
    std::cout << "Defense: " << m_defense << std::endl;
    std::cout << "Special Ability: " << m_specialAbility << std::endl;
}

void Monster::takeDamage(int damage) {
    int damageTaken = damage - m_defense;
    if (damageTaken < 0) {
        damageTaken = 0; 
    }
    m_health -= damageTaken;

    if (m_health < 0) {
        m_health = 0; 
    }
    std::cout << m_name << " takes " << damageTaken << " damage and now has " << m_health << " health left." << std::endl;
}

void Monster::attack(Character& character) {
    std::cout << m_name << " attacks " << character.getName() << " for " << m_attackPower << " damage!" << std::endl;
    character.takeDamage(m_attackPower);
}

void Monster::useSpecialAbility() {
    std::cout << m_name << " uses special ability: " << m_specialAbility << std::endl;
}

Monster::~Monster() {
    std::cout << "Monster destroyed." << std::endl;
}

void Monster::useAbility(Character* target) {
    std::cout << m_name << " uses a special ability!\n";
    target->takeDamage(m_attackPower * 1.5);
}
