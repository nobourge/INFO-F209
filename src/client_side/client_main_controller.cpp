#include <string>
#include <cstring>
#include "client_main_controller.h"



EnumFactory::SelectionableMenu ControllerMainMenu::Control(){
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
    if (y=="10") {
      EnumFactory::SelectionableMenu next=mn.ReceiveEnterMessage();
      if(next!=EnumFactory::null){
        endwin();
        return next;
      }
    }else{
    mn.ReceiveMessage(y);}
  }
  endwin();
  return EnumFactory::null;
}

EnumFactory::SelectionableMenu ControllerLoginClient::Control(){
  std::vector<bool> toSelect;
  LoginView lv({true, false, false});
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
    if (y=="10") {
      EnumFactory::SelectionableMenu next=lg.ReceiveEnterMessage();
      if(next==EnumFactory::SelectionableMenu::Pseudo){
        char pseudo[80];
        echo();
        mvwgetstr(menu,4,70,pseudo);
        lg.SetUsername(pseudo);
        lv.setchamp(pseudo,0);

      }else if(next==EnumFactory::SelectionableMenu::MDP){
        char mdp[80];
        echo();
        mvwgetstr(menu,6,70,mdp);
        lg.setPassword(mdp);
        lv.setchamp(mdp,1);

      }
      else if(next==EnumFactory::SelectionableMenu::Main){
        endwin();
        return next;
      }
    }else{
    lg.ReceiveMessage(y);}
  }
  endwin();
  return EnumFactory::null;
}


EnumFactory::SelectionableMenu ControllerHelpClient::Control(){
  HelpView hv;
  Help hp;
  WINDOW* menu;
  initscr();
  attron(A_STANDOUT);
  clear();
  noecho();
  while(true){
    menu = newwin(150,150,0,0);
    hv.Display(menu);
    keypad(menu,true);
    int x;
    x = wgetch(menu);
    std::string y=std::to_string(x);
    if (y=="10") {
      EnumFactory::SelectionableMenu next=hp.ReceiveEnterMessage();
        endwin();
        return next;
      }
  }
  endwin();
  return EnumFactory::null;
}



EnumFactory::SelectionableMenu ControllerStartScreenClient::Control(){
  std::vector<bool> toSelect;
  StartScreenView mv ({true, false, false});
  StartScreen mn;
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
    if (y=="10") {
      EnumFactory::SelectionableMenu next=mn.ReceiveEnterMessage();
      if(next!=EnumFactory::null){
        endwin();
        return next;
      }
    }else{
      mn.ReceiveMessage(y);}
  }
  endwin();
  return EnumFactory::null;
}


EnumFactory::SelectionableMenu ControllerTypeOfGameSelectClient::Control(){
  std::vector<bool> toSelect;
  TypeOfGameSelectView mv ({true, false, false,false});
  TypeOfGameSelect mn;
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
    if (y=="10") {
      EnumFactory::SelectionableMenu next=mn.ReceiveEnterMessage();
      if(next!=EnumFactory::null){
        endwin();
        return next;
      }
    }else{
      mn.ReceiveMessage(y);}
  }
  endwin();
  return EnumFactory::null;
}