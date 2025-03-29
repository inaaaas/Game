#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include <vector>
#include <string>
#include "Location.h"

class GameWorld {
private:
    std::vector<Location*> m_locations;
    Location* m_currentLocation;

public:
    GameWorld();
    ~GameWorld();

    void addLocation(Location* location);
    void moveToLocation(const std::string& locationName);
    std::vector<Location*> getLocations() const;
};
#endif