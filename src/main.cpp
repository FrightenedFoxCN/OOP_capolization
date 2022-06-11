#define DEBUG

#include "..\include\dialog.h"
#include <Windows.h>
#include <fstream>
#include <iomanip>

Character *Dialog::character = new Character();

int main() {
   SetConsoleOutputCP(65001);
   std::string userName;
   std::cout << "请输入您的用户名（新用户可新建用户名）" << std::endl;
   std::cin >> userName;
   std::cout << "当游戏进行到需要您进行键盘输入时，输入q即可退出" << std::endl;
   std::string userFileName = "data\\" + userName + "_history.json";
   std::fstream f(userFileName);
   bool continueFlag = false;
   if (f.good()) {
      f.close();
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
      dial.setCharacterName(userName);
   }
   else {
      std::string prevDial;
      f.open(userFileName, std::ios::in);
      getline(f, prevDial);
      dial = Dialog(prevDial);
      Dialog::character->readFromJson(f);
      dial.setCharacter(Dialog::character);
      f.close();
      f.open(userFileName, std::ios::in | std::ios::trunc);
      f.close();
   }
   dial.showDialog();
   while (dial.hasNextDialog()){
    #ifdef NDEBUG
      Sleep(1000);
    #endif
      std::string nextDial =  dial.getNextDialog();
      if (nextDial.length() == 0) {
         f.open(userFileName, std::ios::out);
         f << std::setfill('0') << std::setw(5) << dial.getDialogId() << std::endl;
         Dialog::character->writeToJson(f);
         f.close();
         return 0;
      }
      dial = Dialog(nextDial);
      dial.showDialog();
   }
}