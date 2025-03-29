#include "Hero.h"

#include <iostream>

void Hero::displayStats() const {
    std::cout << "Hero Name: " << m_name << std::endl;
    std::cout << "Health: " << m_health << std::endl;
    std::cout << "Attack Power: " << m_attackPower << std::endl;
    std::cout << "Defense: " << m_defense << std::endl;
    std::cout << "Level: " << m_level << std::endl;
    std::cout << "Experience Points: " << m_experiencePoints << std::endl;
}

void Hero::takeDamage(int damage) {
    int damageTaken = damage - m_defense;
    if (damageTaken < 0) 
    { 
        damageTaken = 0;
    }
    m_health -= damageTaken;

    if (m_health < 0) 
    {
        m_health = 0;
    }
    std::cout << m_name << " takes " << damageTaken << " damage and now has " << m_health << " health left." << std::endl;
}

void Hero::interact() {
    std::cout << m_name << " interacts with an NPC." << std::endl;
}

void Hero::attack(Character& character) {
    std::cout << m_name << " attacks " << character.getName() << " for " << m_attackPower << " damage!" << std::endl;
    character.takeDamage(m_attackPower);
}

Hero::~Hero() {
    std::cout << "Hero destroyed." << std::endl;
}



int Hero::getLevel() const {
    return m_level;
}

int Hero::getXP() const {
    return m_experiencePoints;
}

void Hero::gainXP(int xp) {
    m_experiencePoints += xp;
    std::cout << m_name << " gained " << xp << " XP!\n";
}

const std::vector<std::string>& Hero::getInventory() const {
    return m_inventory;
}

std::string Hero::getDialogue() const {
    return "Hello! I am " + m_name + ". How can I help you?"; // Example dialogue
}

void Hero::displayInventory() const {
    if (m_inventory.empty()) {
        std::cout << "Your inventory is empty.\n";
    } else {
        std::cout << "Inventory: \n";
        for (const auto& item : m_inventory) {
            std::cout << "- " << item << "\n";
        }
    }
}

void Hero::useAbility(Character* character) {
    std::cout << m_name << " uses a special ability on " << character->getName() << "!" << std::endl;
}
