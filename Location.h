#ifndef LOCATION_H
#define LOCATION_H

#include <vector>
#include <string>
#include "Character.h"

class Location {
private:
    std::string m_locationName;
    std::vector<Character*> entities;

public:
    Location(const std::string& locationName);
    ~Location();

    const std::string& getName() const;
    void addEntity(Character* character); //avelacnel characterin ays location  
    void removeEntity(Character* character); // jnjel characterin ays locationic
};

#endif
