#include "../include/character.h"

bool Character::hasSkill(int skillID) {
    for (auto a:skills) {
        if (a->getID() == skillID) {
            return true;
        }
    }
    return false;
}

int Character::addNewSkill(int skillID) {
    if (hasSkill(skillID)) {
        Skill *s = new Skill(skillID, 1);
        skills.push_back(s);
        return 0;
    } else {
        return 1;
    }
}

int Character::skillLevelUp(int skillID, int levelUp) {
    for (auto a:skills) {
        if (a->getID() == skillID) {
            a->LevelUp(levelUp);
            return 0;
        }
    }
    return 1;
}

Character::~Character() {
    for (auto a: this->skills) {
        delete a;
    }
}