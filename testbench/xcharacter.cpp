#include "../include/character.h"
#include <string>
#include <iostream>
#include "../src/utils/include/comparator.h"
using namespace std;

int main(){
    string username;
    cin >> username;
    Character *character = new Character(username);
    character->applyEffect("DIL", 4);
    character->applyEffect("RLG", -1);
    cout << character->testCondition("LDS", 3, compareEqual) << endl;
    cout << character->testCondition("CRT", 1, compareGreaterorEqual) << endl;
    character->writeToJson("test");
    Character *new_character = Character::readFromJson("test");
    new_character->printCharacter();
    return 0;
}