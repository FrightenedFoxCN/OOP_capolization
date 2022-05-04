#ifndef _POLICY_H_
#define _POLICY_H_

#include <string>
#include <map>

class Policy {
    int id;
    std::string name;
    std::map<int, double> effect;
};

#endif