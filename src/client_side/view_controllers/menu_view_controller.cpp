//
// Created by Anton Romanova on 21/02/2022.
//

#include "menu_view_controller.h"

MenuViewController::MenuViewController(const std::shared_ptr<AbstractMenuView> &view) : AbstractViewController(),
                                                                                        MenuViewDelegate(), menu_view_(view) {
  menu_view_->SetDelegate(this);
}
std::optional<std::shared_ptr<AbstractViewController>> MenuViewController::Tick() {
  WINDOW *window;
  initscr();
  attron(A_STANDOUT);
  clear();
  noecho();

  MenuViewWillAppear();

  while (!next_view_controller_.has_value()) {
    window = newwin(150, 150, 0, 0);
    GetMenuView()->Draw(window);
    keypad(window, true);
    RespondToKeyboardEvent(wgetch(window));
  }
  endwin();
  auto next_vc = std::move(next_view_controller_.value());

  next_view_controller_ = {};


  MenuViewWillDisappear();
  return next_vc;
}


void MenuViewController::PresentViewController(std::optional<std::shared_ptr<AbstractViewController>> next_view_controller) {
  next_view_controller_ = next_view_controller;
}

const std::shared_ptr<AbstractMenuView> &MenuViewController::GetMenuView() const {
  return menu_view_;
}

void MenuViewController::RespondToKeyboardEvent(const int &character) {
  menu_view_->PropagateEvent(character);
}
