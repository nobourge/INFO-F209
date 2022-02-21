#include <string>
#include <cstring>
#include "home_menu_view_controller.h"
#include "../../common/constants.h"

std::optional<std::shared_ptr<AbstractViewController>> HomeMenuViewController::Tick() {
  WINDOW *window;
  initscr();
  attron(A_STANDOUT);
  clear();
  noecho();
  while (!next_view_controller_.has_value()) {
    window = newwin(150, 150, 0, 0);
    GetHomeMenuView().Draw(window);
    keypad(window, true);
    ParseMessage(wgetch(window));
  }
  endwin();
  return next_view_controller_.value();
}

const HomeMenuView &HomeMenuViewController::GetHomeMenuView() const {
  return home_menu_view_;
}

HomeMenuViewController::HomeMenuViewController() : home_menu_view_(HomeMenuView()) {
  home_menu_view_.SetDelegate(this);
}

void HomeMenuViewController::ParseMessage(const int &character) {
  switch (character) {
    case KEY_DOWN:
      home_menu_view_.MoveCursorUp();
      break;
    case KEY_UP:
      home_menu_view_.MoveCursorDown();
      break;
    case '\n':
      home_menu_view_.Click();
      break;
    default:
      break;
  }
}

void HomeMenuViewController::NextViewControllerSelected(std::optional<std::shared_ptr<AbstractViewController>> next_view_controller) {
  next_view_controller_ = next_view_controller;
}

//std::shared_ptr<AbstractViewController> ControllerLoginClient::Tick() {
////  std::vector<bool> toSelect;
////  LoginMenuView lv(nullptr, nullptr, {true, false, false});
////  Login lg;
////  WINDOW* menu;
////  initscr();
////  attron(A_STANDOUT);
////  clear();
////  noecho();
////  while(true){
////    toSelect = lg.getButtonState();
////    lv.settoSelect(toSelect);
////    menu = newwin(150,150,0,0);
////    lv.Draw();
////    keypad(menu,true);
////    int x;
////    x = wgetch(menu);
////    std::string y=std::to_string(x);
////    if (y=="10") {
////      EnumFactory::SelectionableMenu next=lg.ReceiveEnterMessage();
////      if(next==EnumFactory::SelectionableMenu::Pseudo){
////        char pseudo[80];
////        echo();
////        mvwgetstr(menu,4,70,pseudo);
////        lg.SetUsername(pseudo);
////        lv.setchamp(pseudo,0);
////
////      }else if(next==EnumFactory::SelectionableMenu::MDP){
////        char mdp[80];
////        echo();
////        mvwgetstr(menu,6,70,mdp);
////        lg.setPassword(mdp);
////        lv.setchamp(mdp,1);
////
////      }
////      else if(next==EnumFactory::SelectionableMenu::Main){
////        endwin();
////        return next;
////      }
////    }else{
////    lg.ReceiveMessage(y);}
////  }
////  endwin();
//  return EnumFactory::null;
//}