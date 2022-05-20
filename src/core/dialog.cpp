#include "..\..\include\dialog.h"
#include "..\..\lib\nlohmann\json.hpp"

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
    } else {
        randBranch = false;
    }
    for (auto a:dialog_json[s]["next_dialog"]) {
        nextDialog.push_back(a);
    }
    for (auto a:dialog_json[s]["effect"].items()) {
        effect.insert(std::pair<std::string, int>(a.key(), a.value()));
    }
    dialog.close();
}

std::string Dialog::getNextDialog(void) {
    if (!branch) {
        return nextDialog[0];
    } else if (!randBranch) {
        // need to let the user to choose...
        char label = 'a';
        std::cout << "在以下几项中选择：" << std::endl;
        for (auto a:nextDialog) {
            std::cout << "  " << label++ << ". " << Dialog(a).data << std::endl;
        }
        std::cout << "你选择：";
        std::cin >> label;
        return nextDialog[tolower(label) - 'a'];
    } else {
        // randomize
        // <TODO> Add non-uniform random
        std::default_random_engine randEng(time(0));
        std::uniform_int_distribution<unsigned> dist(0, nextDialog.size() - 1);
        return nextDialog[dist(randEng)];
    }
}

void Dialog::showDialog(void) {
    std::ifstream speaker_file("assets\\speaker.json");
    nlohmann::json speaker_json;
    speaker_file >> speaker_json;
    std::cout << std::string(speaker_json[speaker]["prefix"]) << data << std::endl;
}