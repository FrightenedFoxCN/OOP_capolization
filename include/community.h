#ifndef _COMMUNITY_H_
#define _COMMUNITY_H_

#include <string>
#include <vector>
#include "infrastructure.h"
#include "character.h"

class Community {
    int id;
    std::string name;
    std::vector<Infrastructure *> infras;
    Character leader;
    int population = 0;
public:
    Community() {};
    Community(int id, std::string name);
    #ifdef _DEBUG
    Community(int id, std::string name, std::vector<Infrastructure *> infras, Character leader);
    #endif
    virtual ~Community();
    int addInfrastructure(int id);
    #ifdef DEBUG
    int addInfrastructure(Infrastructure *infra);
    #endif
    int hasInfrastructure(int id);
    #ifdef DEBUG
    int hasInfrastructure(Infrastructure *infra);
    #endif
    int delInfrastructure(int id);
    #ifdef DEBUG
    int delInfrastructure(Infrastructure *infra);
    #endif
    const Character& getLeader(void) const {return leader; };
    int setLeader(const Character& c) {leader = c; }
    int getPopulation(void) const {return population; }
    int setPopulation(int p) {population = p; }
};

#endif