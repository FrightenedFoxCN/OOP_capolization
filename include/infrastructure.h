#ifndef _INFRASTRUCTURE_H_
#define _INFRASTRUCTURE_H_

#include <string>
class Infrastructure {
    int id;
    std::string name;
    int level = 1;
    int productId;
    int productivity;
    double addition = 1.00;
public:
    Infrastructure() {};
    Infrastructure(int id, std::string name);
    #ifdef DEBUG
    Infrastructure(int id, std::string name, int product, double productivity, double addition);
    #endif
    virtual ~Infrastructure() {}
    int getProductivity(void) {return productivity * addition; }
    double increaseAddition(double multiplier) {addition *= multiplier; }
    int levelUp(int level);
};

#endif