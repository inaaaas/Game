#ifndef QUESTMANAGER_H
#define QUESTMANAGER_H

#include <vector>
#include "Quest.h"
#include "Hero.h"

class QuestManager {
private:
    std::vector<Quest*> activeQuests;
    std::vector<Quest*> completedQuests;

public:
    QuestManager();
    ~QuestManager();

    void assignQuest(Quest* quest);
    void checkQuestCompletion();
    void completeQuest(int index, Hero* hero);
};

#endif
