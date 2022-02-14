//
// Created by guest on 14/02/2022.
//
#include <cstring>
#include "Controller.h"
#include "view/SelectionMenuView.h"
#include "MainMenu.hpp"
#include "ncurses.h"


void Controller ::Control(){
  std::vector<bool> toSelect = {false, true, false, false, false};
  SelectionMenuView Menu;
  MainMenu mn;
  WINDOW* menu;
  initscr();
  clear();
  noecho();
  cbreak();
  while(true){
    toSelect=mn.getButtonState();
    menu=newwin(150,150,0,0);
    Menu.Display(toSelect,menu);
    //std::string x;
    //std::cin>>x;
    int x;
    keypad(menu,true);
    x=wgetch(menu);
    std::string y=std::to_string(x);
    mn.ReceiveMessage(y);
  }
  endwin();
}