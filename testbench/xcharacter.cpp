#include "../include/character.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include "../src/utils/include/comparator.h"
using namespace std;

int main(){
    string username;
    cin >> username;
    fstream ios("test.json", ios_base::in | ios_base::out | ios_base::trunc);
    Character *character = new Character(username);
    character->applyEffect("DIL", 4);
    character->applyEffect("RLG", -1);
    cout << character->testCondition("LDS", 3, compareEqual) << endl;
    cout << character->testCondition("CRT", 1, compareGreaterorEqual) << endl;
    assert(ios.good());
    character->writeToJson(ios);
    ios.seekg(0, ios::beg);
    Character *new_character = Character::readFromJson(ios);
    new_character->printCharacter();
    ios.close();
    return 0;
}