//
// Created by guest on 12/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_MENUVIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_MENUVIEW_H_

#endif //QUORIDOR_SRC_CLIENT_SIDE_MENUVIEW_H_

#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>

class MenuView{

public:
    virtual void OpenMenu() = 0;
    const int decalage = 4;
    const char* name;
};