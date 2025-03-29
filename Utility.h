#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector> 
#include <ctime>
#include <iostream>
#include <fstream>
#include "Hero.h"

namespace Utility {
    int getValidatedInput(int min, int max);
    void saveGame(const Hero* hero, const std::string& filename);
    //std::string loadGameState(const std::string& filename);
    Hero* loadGame(const std::string& filename);
}

#endif
