//
// Created by Anton Romanova on 21/02/2022.
//

#include "menu_view_controller.h"

MenuViewController::MenuViewController(AbstractMenuView * view) : AbstractViewController(), home_menu_view_(view) {

}
std::optional<std::shared_ptr<AbstractViewController>> MenuViewController::Tick() {
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
