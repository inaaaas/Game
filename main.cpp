#include <iostream>
#include "Hero.h"
#include "Monster.h"
#include "GameWorld.h"
#include "QuestManager.h"
#include "Utility.h"

void createHero(Hero*& hero);
void combat(Hero* hero, Monster* monster, QuestManager& qm);
void changeLocation(std::string& currentLocation, Hero* hero, GameWorld& world);

int main() {
    std::cout << "Welcome to Quest\n";
    Hero* hero = nullptr;
    GameWorld world;            
    QuestManager questManager; 
    std::string currentLocation = "Enchanted Forest";

    std::cout << "Starting the game\n..........\n";
    
    while (true) {
        if (!hero) {
            std::cout << "1. Create Hero\n2. Exit\nChoose an option: ";
            int choice = Utility::getValidatedInput(1, 2);
            if (choice == 1) {
                createHero(hero); 
                changeLocation(currentLocation, hero, world);  
            } else {
                break;
            }
        } else {

            std::cout << "\nCurrent Location: " << currentLocation << "\n";
            std::cout << "1. Change location\n2. Start attacking\n3. View Stats\n4. View Inventory\n5. Save Game\n6. Load Game\n7. Exit\n";
            std::cout << "Choose an option: ";
            int choice = Utility::getValidatedInput(1, 7);

            switch (choice) {
                case 1:
                    changeLocation(currentLocation, hero, world);
                    break;
                case 2: {
                    Monster* goblin = new Monster("Goblin", 50, 10, 3, "Rush the rock");
                    combat(hero, goblin, questManager);
                    delete goblin;
                    break;
                }
                case 3:
                    hero->displayStats();
                    break;
                case 4: 
                    hero->displayInventory();
                    break;
                case 5:
                    Utility::saveGame(hero, "file.txt");
                    break;
                case 6:
                    delete hero; 
                    hero = Utility::loadGame("file.txt");
                    break;
                case 7:
                    delete hero;
                    return 0;
            }
        }
    }

    delete hero;
    return 0;
}

void createHero(Hero*& hero) {
    std::string heroName;
    std::cout << "Enter hero name: ";
    std::cin >> heroName;

    int heroType;
    std::cout << "Choose hero type (1. Warrior, 2. Mage, 3. Rogue): ";
    std::cin >> heroType;

    switch (heroType) {
        case 1:
            hero = new Hero(heroName, 100, 20, 10);
            break;
        case 2:
            hero = new Hero(heroName, 80, 15, 5); 
            break;
        case 3:
            hero = new Hero(heroName, 90, 18, 7);
            break;
        default:
            std::cout << "Invalid hero type. Please try again.\n";
            createHero(hero);
    }

    std::cout << "Hero created: " << hero->getName() << " the " << typeid(*hero).name() << "\n";
    hero->displayStats();
}

void combat(Hero* hero, Monster* monster, QuestManager& qm [[maybe_unused]]) {
    std::cout << hero->getName() << " engages in combat with " << monster->getName() << "!\n";
    while (hero->getHealth() > 0 && monster->getHealth() > 0) {
        hero->attack(*monster);
        if (monster->getHealth() > 0) {
            monster->attack(*hero);
        }
    }

    if (hero->getHealth() > 0) {
        std::cout << hero->getName() << " has defeated the " << monster->getName() << "!\n";
        hero->gainXP(20);
    } else {
        std::cout << hero->getName() << " has been defeated!\n";
    }
}


void changeLocation(std::string& currentLocation, Hero* hero, GameWorld& world) {
    std::vector<Location*> locations = world.getLocations();
    
    if (locations.empty()) {
        std::cout << "No locations available to travel to.\n";
        return;
    }

    std::cout << "Available Locations:\n";
    for (size_t i = 0; i < locations.size(); ++i) {
        std::cout << i + 1 << ". " << locations[i]->getName() << "\n";
    }

    std::cout << "Choose a location (1-" << locations.size() << "): ";
    int choice = Utility::getValidatedInput(1, locations.size());

    currentLocation = locations[choice - 1]->getName();
    std::cout << "You have moved to " << currentLocation << ".\n";
}
