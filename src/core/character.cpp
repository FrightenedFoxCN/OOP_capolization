#include "../../include/character.h"
#include "../../lib/nlohmann/json.hpp"

#include <iostream>
#include <exception>
#include <fstream>
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

Character *Character::readFromJson(std::string name) {
    nlohmann::json js;
    std::ifstream reader(name + ".json");
    std::string username;
    reader >> js;
    if (js.count("name")) {
        username = js[name];
    } else {
        throw std::runtime_error("Read character name failed");
    }
    Character *character = new Character(username);
    if (js.count("PRD")) {
        character->productivity = js["PRD"].get<double>();
    } else {
        goto ERROR;
    }
    if (js.count("DIL")) {
        character->diligence = js["DIL"].get<double>();
    } else {
        goto ERROR;
    }
    if (js.count("LDS")) {
        character->leadership = js["LDS"].get<double>();
    } else {
        goto ERROR;
    }
    if (js.count("RLG")) {
        character->religion = js["RLG"].get<double>();
    } else {
        goto ERROR;
    }
    if (js.count("INT")) {
        character->intellectual = js["INT"].get<double>();
    } else {
        goto ERROR;
    }
    if (js.count("ELQ")) {
        character->eloquence = js["ELQ"].get<double>();
    } else {
        goto ERROR;
    }
    if (js.count("CRT")) {
        character->creativity = js["CRT"].get<double>();
    } else {
        goto ERROR;
    }
    if (js.count("EPP")) {
        character->creativity = js["EPP"].get<double>();
    } else {
        goto ERROR;
    }
    return character;
    ERROR: throw std::runtime_error("Read character failed");
}

void Character::writeToJson(std::string name) {
    std::map<std::string, double> c_map = {
        {"PRD", productivity}, {"DIL", diligence}, {"LDS", leadership}, {"RLG", religion},
        {"INT", intellectual}, {"ELQ", eloquence}, {"CRT", creativity}, {"EPP", epiphany}
    };
    nlohmann::json j_map;
    j_map.push_back({"name", name});
    j_map.push_back(c_map);
    std::ofstream character(name + ".json");
    character << j_map;
    character.close();
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