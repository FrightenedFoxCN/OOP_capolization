#define DEBUG

#include "..\include\dialog.h"
#include <Windows.h>

int main() {
   Dialog dial("00000");
   dial.showDialog();
   while (dial.hasNextDialog()){
      Sleep(1000);
      std::string nextDial =  dial.getNextDialog();
      dial = Dialog(nextDial);
      dial.showDialog();
   }
}