#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "home_menu_view.h"

HomeMenuView::HomeMenuView() : AbstractMenuView(menu_name_) {
  UpdateButtons(GetSubmenus());
}

const ButtonHandlersDict &HomeMenuView::GetSubmenus() {
  return submenus_;
}

//void LoginMenuView::Draw() const {
//  initscr();
//  wrefresh(GetWindow());
//  wattr_on(GetWindow(), A_BOLD, 0);
//  int center_y = COLS / 2;
//  mvwprintw(GetWindow(), 0, center_y - (strlen(name) / 2), name);
//  wattr_off(GetWindow(), A_BOLD, 0);
//  for (unsigned long int i = 0; i < words.size(); i++) {
//    if (toSelect[i]) {
//      wattr_on(GetWindow(), A_UNDERLINE, 0);
//    }
//    mvwprintw(GetWindow(), decalage + i * 2, center_y - (strlen(words[i].c_str()) / 2), words[i].c_str());
//    wattr_off(GetWindow(), A_UNDERLINE, 0);
//    mvwprintw(GetWindow(), decalage + i * 2, 70, champ[i].c_str());
//  }
//};
//LoginMenuView::LoginMenuView(const char *name,
//                             WINDOW *window,
//                             std::vector<bool> toSelect) : AbstractMenuView(name, window), toSelect(toSelect) {}
//void LoginMenuView::settoSelect(std::vector<bool> toselect) { toSelect = toselect; }
//void LoginMenuView::setchamp(std::string newstr, int index) { champ[index] = newstr; }
