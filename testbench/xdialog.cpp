#define DEBUG

#include "..\include\dialog.h"
#include <Windows.h>
#include <fstream>
#include <iomanip>

int main() {
   std::fstream f("history.json");
   bool continueFlag = false;
   if (f.good()) {
      char isContinue;
      std::cout << "请选择是否从上次的存档点继续游戏[y/n]" << std::endl; 
      while (1) {
         std::cin >> isContinue;
         if (isContinue == 'y') {
            continueFlag = true;
            break;
         }
         else if (isContinue == 'n') {
            break;
         }
         else {
            std::cout << "请输入y或n进行选择" << std::endl;
         }
      }
   }
   Dialog dial;
   if (continueFlag == false) {
      dial = Dialog("00000");
   }
   else {
      std::string prevDial;
      f.open("history.json", std::ios::in);
      f >> prevDial;
      dial = Dialog(prevDial);
      f.close();
   }
   dial.showDialog();
   while (dial.hasNextDialog()){
      Sleep(1000);
      std::string nextDial =  dial.getNextDialog();
      if (nextDial.length() == 0) {
         if (f.good()) {
            f.open("history.json", std::ios::out);
            f << std::setfill('0') << std::setw(5) << dial.getDialogId();
         }
         else {
            f.open("history.json", std::ios::ate);
            f << std::setfill('0') << std::setw(5) << dial.getDialogId();
         }
         f.close();
      }
      dial = Dialog(nextDial);
      dial.showDialog();
   }
}