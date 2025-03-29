#ifndef NPC_H
#define NPC_H

#include "Character.h"
#include "Interactable.h"
#include "Quest.h"

class NPC : public Character, public Interactable {
private:
    std::string m_dialogue;
    std::vector<Quest*> quests; 

public:
    NPC(const std::string& n, int h, int ap, int def, const std::string& dialogue);
    void displayStats() const override; //from character
    void takeDamage(int damage) override;//from character
    void interact() override; //from Interactable
    void giveQuest(Quest* quest);
    const std::vector<Quest*>& getQuests() const;
    virtual ~NPC();
};

#endif
