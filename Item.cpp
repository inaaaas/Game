#include "Item.h"

Item::Item(const std::string& n, int damage)
    : m_name(n), m_damage(damage) {}

void Item::display() const {
    std::cout << "Item Name: " << m_name << ", Damage: " << m_damage << std::endl;
}
std::string Item::getName() const {
    return m_name;
}