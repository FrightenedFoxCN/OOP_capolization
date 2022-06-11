#include "../../include/character.h"
#include "../../lib/nlohmann/json.hpp"

#include <iostream>
#include <exception>
#include <map>

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

void Character::applyEffect(std::string id, double amount) {
    std::map<std::string, int> decode = {
        {"PRD", 0}, {"DIL", 1}, {"LDS", 2}, {"RLG", 3},
        {"INT", 4}, {"ELQ", 5}, {"CRT", 6}, {"EPP", 7}
    };
    if (!decode.count(id)) {
        throw std::logic_error("Wrong id");
    }
    int inner_id = decode[id];
    switch (inner_id) {
    case 0:
        increaseProductivity(amount);
        break;
    case 1:
        increaseDiligence(amount);
        break;
    case 2:
        increaseLeadership(amount);
        break;
    case 3:
        increaseReligion(amount);
        break;
    case 4:
        increaseIntellectual(amount);
        break;
    case 5:
        increaseEloquence(amount);
        break;
    case 6:
        increaseCreativity(amount);
        break;
    case 7:
        increaseEpiphany(amount);
        break;
    default:
        throw std::runtime_error("Incorrect inner ID");
        break;
    }
}

void Character::writeToJson(std::string name) {
    
}

bool Character::testCondition(std::string id, double amount, bool(*comp)(double, double)) {
    std::map<std::string, int> decode = {
        {"PRD", 0}, {"DIL", 1}, {"LDS", 2}, {"RLG", 3},
        {"INT", 4}, {"ELQ", 5}, {"CRT", 6}, {"EPP", 7}
    };
    if (!decode.count(id)) {
        throw std::logic_error("Wrong id");
    }
    int inner_id = decode[id];
    switch (inner_id) {
        case 0: return comp(productivity, amount);
        case 1: return comp(diligence, amount);
        case 2: return comp(leadership, amount);
        case 3: return comp(religion, amount);
        case 4: return comp(intellectual, amount);
        case 5: return comp(eloquence, amount);
        case 6: return comp(creativity, amount);
        case 7: return comp(epiphany, amount);
        default: throw std::runtime_error("inner_id Error"); break;
    }
}