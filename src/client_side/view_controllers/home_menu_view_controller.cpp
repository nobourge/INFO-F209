#include <string>
#include "home_menu_view_controller.h"


HomeMenuViewController::HomeMenuViewController()
    : MenuViewController(std::make_shared<HomeMenuView>()) {}




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
