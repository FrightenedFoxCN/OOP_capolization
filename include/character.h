#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <string>
#include <vector>
#include "skill.h"

class Character {
    std::string name;
    std::vector<Skill *> skills;
    bool hasSkill(int skillID);
    double productivity = 1.00;
    double leadership = 1.00;
    double religion = 1.00;
public:
    Character() {};
    Character(std::string name) : name(name) {};
    virtual ~Character();
    std::string getName(void) {return name;}
    void setName(std::string name) {this->name = name;}
    int addNewSkill(int skillID);
    int skillLevelUp(int skillID, int levelUp);
};

#endif