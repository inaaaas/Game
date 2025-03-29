#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

class Item {
private:
    std::string m_name;
    int m_damage;

public:
    Item(const std::string& n, int damage);
    void display() const;
    std::string getName() const;
};

#endif 
