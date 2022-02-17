#include <string>
#include <cstring>
#include "client_main_controller.h"
#include "view/MainMenuView.h"
#include "main_menu.hpp"
#include "ncurses.h"



std::string ControllerMainMenu ::Control(){
  std::vector<bool> toSelect;
  MainMenuView mv ({true, false, false});
  MainMenu mn;
  WINDOW* menu;
  initscr();
  attron(A_STANDOUT);
  clear();
  noecho();
  while(true){
    toSelect = mn.getButtonState();
    mv.settoSelect(toSelect);
    menu = newwin(150,150,0,0);
    mv.Display(menu);
    keypad(menu,true);
    int x;
    x = wgetch(menu);
    std::string y=std::to_string(x);
    mn.ReceiveMessage(y);
  }
  endwin();
  return NULL;
}