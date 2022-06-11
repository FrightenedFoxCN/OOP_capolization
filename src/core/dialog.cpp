#include "..\..\include\dialog.h"
#include "..\..\lib\nlohmann\json.hpp"
#include "..\utils\include\comparator.h"

#include <fstream>
#include <random>

Dialog::Dialog(std::string s) {
    std::ifstream dialog("assets\\dialog.json");
    nlohmann::json dialog_json;
    dialog >> dialog_json;
    id = dialog_json[s]["id"].get<int>();
    data = dialog_json[s]["data"];
    speaker = dialog_json[s]["speaker"];
    branch = dialog_json[s]["has_branch"].get<bool>();
    if (dialog_json[s].contains("rand_branch")) {
        randBranch = dialog_json[s]["rand_branch"].get<bool>();
        uint32_t tot_possibility = 0;
        for (auto a:dialog_json[s]["possibility"]) {
            tot_possibility += a.get<uint32_t>();
        }
        for (auto a:dialog_json[s]["possibility"]) {
            possibility.push_back(float(a) / float(tot_possibility));
        }
    } else {
        randBranch = false;
    }
    for (auto a:dialog_json[s]["next_dialog"]) {
        nextDialog.push_back(a);
    }
    for (auto a:dialog_json[s]["effect"].items()) {
        effect.insert(std::pair<std::string, int>(a.key(), a.value()));
    }
    if (dialog_json[s].contains("cond")) {
        condBranch = true;
        for (auto a:dialog_json[s]["cond_branch"].items()) {
            nextCondDialog.push_back(std::pair<std::string, double>(a.key(), a.value()));
        }
    } else {
        condBranch = false;
    }
    
    dialog.close();
}

std::string Dialog::getNextDialog(void) {
    if (effect.size()) {
        for (auto a:effect) {
            try {
                character->applyEffect(a.first, a.second);
            } catch(std::logic_error) {
                std::cout << "数据文件已损坏" << std::endl;
            }
        }
    }
    if (!branch) {
        return nextDialog[0];
    } else if (condBranch) {
        for (int i = 0; i < nextCondDialog.size(); i++) {
            std::string id = nextCondDialog[i].first.substr(0, 3);
            std::string op = nextCondDialog[i].first.substr(3);
            if (op == "==") {
                if (character->testCondition(id, nextCondDialog[i].second, compareEqual)) {
                    return nextDialog[i];
                }
            }
            else if (op == "<>") {
                if (character->testCondition(id, nextCondDialog[i].second, compareNotEqual)) {
                    return nextDialog[i];
                }
            }
            else if (op == ">") {
                if (character->testCondition(id, nextCondDialog[i].second, compareGreaterThan)) {
                    return nextDialog[i];
                }
            }
            else if (op == ">=") {
                if (character->testCondition(id, nextCondDialog[i].second, compareGreaterorEqual)) {
                    return nextDialog[i];
                }
            }
            else if (op == "<") {
                if (character->testCondition(id, nextCondDialog[i].second, compareLessThan)) {
                    return nextDialog[i];
                }
            }
            else if (op == "<=") {
                if (character->testCondition(id, nextCondDialog[i].second, compareLessorEqual)) {
                    return nextDialog[i];
                }
            }
        }
    } else if (!randBranch) {
        // need to let the user to choose...
        char label = 'a';
        std::cout << "在以下几项中选择：" << std::endl;
        for (auto a:nextDialog) {
            std::cout << "  " << label++ << ". " << Dialog(a).data << std::endl;
        }
        std::cout << "你选择：";
        std::cin >> label;
        if (label == 'q') {
            return "";
        }
        return nextDialog[tolower(label) - 'a'];
    } else {
        // randomize
        std::default_random_engine randEng(time(0));
        std::uniform_real_distribution<float> dist(0, 1);
        uint32_t dialog_index = 0;
        float tot_possibility = 0;
        for (; tot_possibility < dist(randEng); dialog_index++) {
            tot_possibility += possibility[dialog_index];
        }
        return nextDialog[dialog_index];
    }
}

void Dialog::showDialog(void) {
    std::ifstream speaker_file("assets\\speaker.json");
    nlohmann::json speaker_json;
    speaker_file >> speaker_json;
    std::cout << std::string(speaker_json[speaker]["prefix"]) << data << std::endl;
}