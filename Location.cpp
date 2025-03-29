#include "Location.h"
#include <iostream>

Location::Location(const std::string& locationName) : m_locationName(locationName) {}

Location::~Location() {
    for (Character* character : entities) {
        delete character;
    }
}

const std::string& Location::getName() const {
    return m_locationName;
}

void Location::addEntity(Character* character) {
    entities.push_back(character);
    std::cout << character->getName() << " has entered " << m_locationName << "." << std::endl;
}

void Location::removeEntity(Character* character) {
    auto it = std::remove(entities.begin(), entities.end(), character);
    if (it != entities.end()) {
        entities.erase(it, entities.end());
        std::cout << character->getName() << " has left " << m_locationName << "." << std::endl;
    }
}

