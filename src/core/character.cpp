#include "../../include/character.h"

#include <iostream>

void Character::printCharacter() {
    std::cout << "============== Character " << name << " ==============" << std::endl;
    std::cout << "\tProductivity: " << productivity << std::endl;
    std::cout << "\tDiligence: " << diligence << std::endl;
    std::cout << "\tLeadership: " << leadership << std::endl;
    std::cout << "\tReligion: " << religion << std::endl;
    std::cout << "\tIntellectual: " << intellectual << std::endl;
    std::cout << "\tEloquence: " << eloquence << std::endl;
    std::cout << "\tCreativity: " << creativity << std::endl;
    std::cout << "\tEpiphany: " << epiphany << std::endl;
    std::cout << "================================================" << std::endl;
}