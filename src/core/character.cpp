#include "../../include/character.h"
#include "../../lib/nlohmann/json.hpp"

#include <iostream>
#include <exception>
#include <fstream>
#include <map>

void Character::printCharacter() {
    std::cout << "============== Character " << name << " ==============" << std::endl;
    std::cout << "\tProductivity:\t" << productivity << std::endl;
    std::cout << "\tDiligence:\t" << diligence << std::endl;
    std::cout << "\tLeadership:\t" << leadership << std::endl;
    std::cout << "\tReligion:\t" << religion << std::endl;
    std::cout << "\tIntellectual:\t" << intellectual << std::endl;
    std::cout << "\tEloquence:\t" << eloquence << std::endl;
    std::cout << "\tCreativity:\t" << creativity << std::endl;
    std::cout << "\tEpiphany:\t" << epiphany << std::endl;
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
        productivity += amount;
        break;
    case 1:
        diligence += amount;
        break;
    case 2:
        leadership += amount;
        break;
    case 3:
        religion += amount;
        break;
    case 4:
        intellectual += amount;
        break;
    case 5:
        eloquence += amount;
        break;
    case 6:
        creativity += amount;
        break;
    case 7:
        epiphany += amount;
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
        username = js["name"];
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
        {"PRD", productivity}, {"DIL", diligence}, {"LDS", leadership}, 
        {"RLG", religion}, {"INT", intellectual}, {"ELQ", eloquence}, {"CRT", creativity}, 
        {"EPP", epiphany}
    };
    nlohmann::json j_map {
        {"PRD", productivity}, 
        {"DIL", diligence}, 
        {"LDS", leadership},
        {"RLG", religion}, 
        {"INT", intellectual}, 
        {"ELQ", eloquence}, 
        {"CRT", creativity}, 
        {"EPP", epiphany},
        {"name", this->getName()}
    };
    std::ofstream writer(name + ".json");
    writer << j_map;
    writer.close();
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