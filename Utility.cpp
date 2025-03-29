#include "Utility.h"

int Utility::getValidatedInput(int min, int max) {
    if (max < min) { 
        std::cerr << "Error: Invalid input range (" << min << " - " << max << ").\n";
        return min;
    }

    std::string input;
    int choice;

    while (true) {
        std::cout << "Enter a choice (" << min << "-" << max << "): ";
        std::getline(std::cin, input);

        bool isValid = !input.empty();
        for (char c : input) {
            if (!std::isdigit(c)) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            try {
                choice = std::stoi(input);
                if (choice >= min && choice <= max) {
                    return choice;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
        }

        std::cout << "Invalid input! Please enter a number between " << min << " and " << max << ".\n";
    }
}

    void Utility::saveGame(const Hero* hero, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << hero->getName() << "\n";
            file << hero->getLevel() << "\n";
            file << hero->getXP() << "\n";
            file.close();
            std::cout << "Game saved successfully!\n";
        } else {
            std::cout << "Error saving game!\n";
        }
    }


Hero* Utility::loadGame(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string name;
            int level, xp;
            std::getline(file, name);
            file >> level >> xp;
            file.close();
            
            Hero* hero = new Hero(name, 80, 15, 5); 
            for (int i = 1; i < level; i++) {
                hero->gainXP(100); 
            }
            hero->gainXP(xp);
            std::cout << "Game loaded successfully!\n";
            return hero;
        }
        std::cout << "Error loading game!\n";
        return nullptr;
    }