//
// Created by Anton Romanova on 21/02/2022.
//

#include "abstract_menu_view_controller.h"

AbstractMenuViewController::AbstractMenuViewController(const std::shared_ptr<AbstractMenuView> &view) : AbstractViewController(),
                                                                                        MenuViewDelegate(), menu_view_(view) {
  menu_view_->SetDelegate(this);
}
std::optional<std::shared_ptr<AbstractViewController>>
AbstractMenuViewController::Tick() {
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


void AbstractMenuViewController::PresentViewController(std::optional<std::shared_ptr<AbstractViewController>> next_view_controller) {
  next_view_controller_ = next_view_controller;
}

const std::shared_ptr<AbstractMenuView> &
AbstractMenuViewController::GetMenuView() const {
  return menu_view_;
}

void AbstractMenuViewController::RespondToKeyboardEvent(const int &character) {
  menu_view_->PropagateEvent(character);
}
