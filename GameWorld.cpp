#include "GameWorld.h"
#include "Location.h"
#include <iostream>
#include <algorithm>

GameWorld::GameWorld() : m_currentLocation(nullptr) {}

GameWorld::~GameWorld() {
    for (Location* location : m_locations) {
        delete location;
    }
}

void GameWorld::addLocation(Location* location) {
    m_locations.push_back(location);
    if (m_currentLocation == nullptr) {
        m_currentLocation = location;
    }
}

void GameWorld::moveToLocation(const std::string& locationName) {
     bool found = false;
    for (Location* loc : m_locations) {
        if (loc->getName() == locationName) {
            m_currentLocation = loc;
            found = true;
            std::cout << "Moved to " << m_currentLocation->getName() << "." << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Location not found: " << locationName << std::endl;
    }
}

std::vector<Location*> GameWorld::getLocations() const {
    return m_locations;
}
