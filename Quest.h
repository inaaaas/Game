#ifndef QUEST_H
#define QUEST_H

#include <string>
#include <vector>

class Quest {
private:
    std::string m_questName;
    std::string m_questDescription;
    bool completed;

public:
    Quest(const std::string& questName, const std::string& questDescription);
    ~Quest();

    const std::string& getName() const;
    const std::string& getDescription() const;
    bool isCompleted() const;
};

#endif
