//
// Created by guest on 01/03/2022.
//

#include "game_view_controller.h"
#include "../views/menu_views/game_view.h"
#include "../views/menu_views/help_menu_view.h"
GameViewController::GameViewController() : AbstractAuthedMenuViewController(std::make_shared<GameView>()) {

}

std::optional<std::shared_ptr<AbstractViewController>> GameViewController::Tick() {

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