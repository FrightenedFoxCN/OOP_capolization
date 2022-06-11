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
    void increaseProductivity(double amount) {this->productivity += amount; }
    void increaseDiligence(double amount) {this->diligence += amount; }
    void increaseLeadership(double amount) {this->leadership += amount; }
    void increaseReligion(double amount) {this->religion += amount; }
    void increaseIntellectual(double amount) {this->intellectual += amount; }
    void increaseEloquence(double amount) {this->eloquence += amount; }
    void increaseCreativity(double amount) {this->creativity += amount; }
    void increaseEpiphany(double amount) {this->epiphany += amount; }

    void applyEffect(std::string id, double amount);
    bool testCondition(std::string id, double amount, bool(*comp)(double, double));
    void writeToJson(std::string name);
    static Character *readFromJson(std::string name);

    // Only used for debug
    void printCharacter();
};

#endif