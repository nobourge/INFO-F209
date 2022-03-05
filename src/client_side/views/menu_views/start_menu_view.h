
#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_START_MENU_VIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_START_MENU_VIEW_H_

#include <iostream>
#include <cstring>
#include <vector>
#include "abstract_menu_view.h"
#include "views/button.h"


class StartMenuView : public AbstractMenuView {
 public:
  static constexpr char menu_name_[] = "Welcome";
  [[nodiscard]] std::string GetBackButtonName() const override;
  StartMenuView();
};

#endif