//
// Created by guest on 17/02/2022.
//
#include <string>
#include <cstring>
#include "client_login_controller.h"
#include "ncurses.h"
#include "client_login_model.hpp"
#include "login_view.h"

std::string ControllerLoginClient ::Control(){
  std::vector<bool> toSelect;
  LoginView lv ({true, false, false});
  Login lg;
  WINDOW* menu;
  initscr();
  attron(A_STANDOUT);
  clear();
  noecho();
  while(true){
    toSelect = lg.getButtonState();
    lv.settoSelect(toSelect);
    menu = newwin(150,150,0,0);
    lv.Display(menu);
    keypad(menu,true);
    int x;
    x = wgetch(menu);
    std::string y=std::to_string(x);
    lg.ReceiveMessage(y);
  }
  endwin();
  return NULL;
}