#include <cstring>
#include "controller.h"
#include "view/SelectionMenuView.h"
#include "main_menu.hpp"
#include "ncurses.h"


string ControllerMainMenu ::Control(){
  std::vector<bool> toSelect = {false, true, false, false, false};
  SelectionMenuView Menu;
  MainMenu mn;
  WINDOW* menu;
  initscr();
  attron(A_STANDOUT);
  clear();
  noecho();
  while(true){
    toSelect = mn.getButtonState();
    menu = newwin(150,150,0,0);
    Menu.Display(toSelect,menu);
    keypad(menu,true);
    int x;
    x = wgetch(menu);
    std::string y=std::to_string(x);
    std::cout << y << std::endl;
    mn.ReceiveMessage(y);
  }
  endwin();
  return null;
}