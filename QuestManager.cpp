#include "QuestManager.h"
#include <iostream>

QuestManager::QuestManager() {}

QuestManager::~QuestManager() {
    for (Quest* quest : activeQuests) {
        delete quest;
    }
    for (Quest* quest : completedQuests) {
        delete quest;
    }
}

void QuestManager::assignQuest(Quest* quest) {
    activeQuests.push_back(quest);
    std::cout << "Assigned quest: " << quest->getName() << std::endl;
}

void QuestManager::checkQuestCompletion() {
    for (auto it = activeQuests.begin(); it != activeQuests.end();) {
        if ((*it)->isCompleted()) { 
            completedQuests.push_back(*it);
            it = activeQuests.erase(it);
        } else {
            ++it;
        }
    }
}
