#ifndef MENUWALLCELL_H
#define MENUWALLCELL_H


#include "menu_cell.h"
#include "assets.h"
#include <QMouseEvent>

class MenuWallCell : public MenuCell {
    bool hasWall;
public:
    MenuWallCell(int x, int y,int row,int col,int size=20, QPixmap pixmap=QPixmap(no_wall_png.c_str()));
    void setWall(bool isHorizontal);
    void unsetWall();
    
    bool isCellPawn() override {return false;}
    bool isCellWall() override {return true;}
};

#endif