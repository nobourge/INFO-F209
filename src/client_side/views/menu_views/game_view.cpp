//
// Created by guest on 01/03/2022.
//

#include "game_view.h"
GameView::GameView() : AbstractMenuView(menu_name_) {
  UpdateSubviews({
                     std::make_shared<MenuButtonItem>(this, "Back", std::optional<std::shared_ptr<AbstractViewController>>{}, this)
                 }
  );
}

void GameView::Draw(WINDOW *window) const {
  initscr();
  wrefresh(window);
  wattr_on(window, MENU_NAME_EFFECT, nullptr);
  int center_y = COLS / 2;
  int right_end_y = COLS-2;
  mvwprintw(window, 0, center_y - (strlen(GetName()) / 2), GetName());
  wattr_off(window, MENU_NAME_EFFECT, nullptr);

  for (int view_idx = 0; view_idx < GetSubviews().size(); ++view_idx) {
    const auto &view = GetSubviews().at(view_idx);

    wattr_on(window, view->GetNcursesEffectForCurrentState(), nullptr);

    mvwprintw(window,
              GetVerticalPadding()
                  + view_idx * (GetVerticalGutterSize() + 1), // + 1 for title -1 for extra gutter cancels out
              right_end_y - (view->GetInnerText().size()),
              view->GetInnerText().c_str());
    wattr_off(window, view->GetNcursesEffectForCurrentState(), nullptr);
  }
}