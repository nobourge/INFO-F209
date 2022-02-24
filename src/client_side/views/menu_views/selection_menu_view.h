
#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_SELECTION_MENU_VIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_SELECTION_MENU_VIEW_H_

#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "abstract_menu_view.h"
#include "views/button.h"


class SelectionMenuView : public AbstractMenuView{
 public:
    SelectionMenuView();
 private:
    constexpr static const char menu_name_[] = "Game Selection";

};



#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEWS_SELECTION_MENU_VIEW_H_