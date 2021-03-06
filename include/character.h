#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <string>
#include <vector>

class Character {
    std::string name;
    double productivity = 1.00;
    double diligence = 1.00;
    double leadership = 1.00;
    double religion = 1.00;
    double intellectual = 1.00;
    double eloquence = 1.00;
    double creativity = 1.00;
    double epiphany = 1.00;
public:
    Character() {};
    Character(std::string name) : name(name) {};
    virtual ~Character() {};
    std::string getName(void) {return name;}
    void setName(std::string name) {this->name = name;}

    void applyEffect(std::string id, double amount);
    bool testCondition(std::string id, double amount, bool(*comp)(double, double));
    void writeToJson(std::fstream &os);
    static Character *readFromJson(std::fstream &is);

    // Only used for debug
    void printCharacter();
};

#endif