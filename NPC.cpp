#include "NPC.h"
#include <iostream>

NPC::NPC(const std::string& n, int h, int ap, int def, const std::string& dialog)
    : Character(n, h, ap, def), m_dialogue(dialog) {}


void NPC::displayStats() const {
    std::cout << "NPC Name: " << m_name << std::endl;
    std::cout << "Health: " << m_health << std::endl;
    std::cout << "Attack Power: " << m_attackPower << std::endl;
    std::cout << "Defense: " << m_defense << std::endl;
    std::cout << "Dialogue: " << m_dialogue << std::endl;
}

void NPC::takeDamage(int damage) {
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

void NPC::interact() {
    std::cout << m_name << ": " << m_dialogue << std::endl;
}

void NPC::giveQuest(Quest* quest) {
    quests.push_back(quest);
    std::cout << m_name << " has given you the quest: " << quest->getName() << std::endl;
}

const std::vector<Quest*>& NPC::getQuests() const {
    return quests;
}

NPC::~NPC() {
    std::cout << "NPC destroyed." << std::endl;
    for (Quest* quest : quests) {
        delete quest;
    }
}
