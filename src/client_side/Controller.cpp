//
// Created by guest on 14/02/2022.
//
#include <cstring>
#include "Controller.h"
#include "view/SelectionMenuView.h"
#include "MainMenu.hpp"
void Controller ::Control(){
  std::vector<bool> toSelect = {false, true, false, false, false};
  SelectionMenuView Menu;
  MainMenu mn;
  while(true){

    toSelect=mn.getButtonState();
    Menu.Display(toSelect);
    std::string x;
    std::cin>>x;
    mn.ReceiveMessage(x);
  }
}