#include "Quest.h"



Quest::Quest(const std::string& questName, const std::string& questDescription)
    : m_questName(questName), m_questDescription(questDescription),completed(false) {}

Quest::~Quest() {}

const std::string& Quest::getName() const {
    return m_questName;
}

const std::string& Quest::getDescription() const {
    return m_questDescription;
}

bool Quest::isCompleted() const {
    return completed;
}
