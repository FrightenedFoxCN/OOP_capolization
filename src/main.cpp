#define DEBUG

#include "..\include\dialog.h"
#include <Windows.h>
#include <fstream>
#include <iomanip>

int main() {
   std::string userName;
   std::cout << "请输入您的用户名（新用户可新建用户名）" << std::endl;
   std::cin >> userName;
   std::string userFileName = userName + "_history.json";
   std::fstream f(userFileName);
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
      f.open(userFileName, std::ios::in);
      f >> prevDial;
      dial = Dialog(prevDial);
      f.close();
   }
   dial.showDialog();
   while (dial.hasNextDialog()){
    #ifdef NDEBUG
      Sleep(1000);
    #endif
      std::string nextDial =  dial.getNextDialog();
      if (nextDial.length() == 0) {
         if (f.good()) {
            f.open(userFileName, std::ios::out);
            f << std::setfill('0') << std::setw(5) << dial.getDialogId();
         }
         else {
            f.open(userFileName, std::ios::ate);
            f << std::setfill('0') << std::setw(5) << dial.getDialogId();
         }
         f.close();
         return 0;
      }
      dial = Dialog(nextDial);
      dial.showDialog();
   }
}