#include "..\lib\nlohmann\json.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream init_comm("assets\\dialog.json");
    nlohmann::json init_comm_json;
    init_comm >> init_comm_json;
    std::cout << init_comm_json << std::endl;
    std::string s("00000");
    std::cout << init_comm_json[s];
}
