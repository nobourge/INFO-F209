//
// Created by guest on 14/02/2022.
//

#ifndef INFO_F209_SRC_CLIENT_SIDE_VIEW_SELECTIONMENUVIEW_H_
#define INFO_F209_SRC_CLIENT_SIDE_VIEW_SELECTIONMENUVIEW_H_
#include "MainMenuView.h"
class SelectionMenuView {
  MenuView* mv =new MainMenuView({true, false, false, false, false});
 public:
  SelectionMenuView(){}
  void Display(std::vector<bool> toselect,WINDOW* menu) const;
};

#endif //INFO_F209_SRC_CLIENT_SIDE_VIEW_SELECTIONMENUVIEW_H_
