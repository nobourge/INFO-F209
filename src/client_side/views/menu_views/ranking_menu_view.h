
#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_RANKING_MENU_VIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_RANKING_MENU_VIEW_H_

#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "abstract_menu_view.h"
#include "views/text_field.h"


class RankingMenuView : public AbstractMenuView{
 public:
    RankingMenuView();
 private:
    constexpr static const char menu_name_[] = "Ranking Menu";

};



#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEWS_RANKING_MENU_VIEW_H_