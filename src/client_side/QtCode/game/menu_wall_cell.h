#ifndef MENUWALLCELL_H
#define MENUWALLCELL_H


#include "menu_cell.h"
#include "assets.h"
#include <QMouseEvent>

class MenuWallCell : public MenuCell {
    bool hasWall;
public:
    MenuWallCell(int x, int y,int row,int col,int size=20, QPixmap pixmap=QPixmap(noWall_png));
    void setWall(bool isHorizontal);
    void unsetWall();
    
    bool isCellPawn() override {return false;}
    bool isCellWall() override {return true;}
};

#endif