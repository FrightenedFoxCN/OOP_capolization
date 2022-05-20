#ifndef _DIALOG_H_
#define _DIALOG_H_

#include "character.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>

class Dialog {
    int id;
    std::string data;
    std::string speaker;
    bool branch;
    bool randBranch;
    std::vector<std::string> nextDialog;
    std::map<std::string, int> effect;
public:
    Dialog() {}
    Dialog(std::string);
    #ifdef DEBUG
    void showDialogDebug(void) {
        std::cout << "id: " << id << std::endl
                  << "data: " << data << std::endl
                  << "speaker: " << speaker << std::endl
                  << "branch: " << branch << std::endl
                  << "randBranch: " << randBranch << std::endl
                  << "nextDialog:" << std::endl;
        for (auto a:nextDialog) {
            std::cout << "\t" << a << std::endl;
        }
        std::cout << "effect:" << std::endl;
        for (auto a:effect) {
            std::cout << "\t" << a.first << ":" << a.second << std::endl;
        }
    }
    #endif
    void showDialog(void);
    bool hasNextDialog(void) {return nextDialog.size();}
    bool hasBranch(void) {return branch;}
    bool isRandBranch(void) {return randBranch;}
    std::string getNextDialog(void);
    void applyEffect(Character &c);
    friend Character;
};

#endif