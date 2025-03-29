#include "Character.h" 

Character::Character(const std::string& n, int h, int ap, int def)
        : m_name(n), m_health(h), m_attackPower(ap), m_defense(def) {}

std::string Character::getName() const {
    return m_name;
}

int Character::getDefense() const {
    return m_defense;
}

int Character::getHealth() const {
    return m_health;
}

