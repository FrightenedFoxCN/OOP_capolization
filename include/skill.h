#ifndef _SKILL_H_
#define _SKILL_H_
#include <map>
#include <string>
#include "character.h"

class Skill {
    // class for skills, init with a json database
    int id; // ID to be recognized by parser
    int level; // the level of skill
    std::map<int, double> skillCapability;
public:
    Skill() {};
    Skill(int id, int level); // initialize with parser
    virtual ~Skill();
    int getID(void) {return this->id;}
    int LevelUp(int levelUp); // `levelUp` levels up
    friend Character;
};

#endif