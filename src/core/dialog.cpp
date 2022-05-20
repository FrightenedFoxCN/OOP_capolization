#include "..\..\include\dialog.h"
#include "..\..\lib\nlohmann\json.hpp"

#include <fstream>

Dialog::Dialog(std::string s) {
    std::ifstream dialog("assets\\dialog.json");
    nlohmann::json dialog_json;
    dialog >> dialog_json;
    std::cout << dialog_json[s] << std::endl;
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
}