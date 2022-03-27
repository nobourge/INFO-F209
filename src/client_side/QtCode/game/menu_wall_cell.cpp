#include "menu_wall_cell.h"

MenuWallCell::MenuWallCell(int x, int y,int row,int col,int size, QPixmap pixmap) : MenuCell{x, y,row,col,size,false, pixmap} {}

void MenuWallCell::setWall(bool isHorizontal) {
    if (isHorizontal) setCellPixmap(QPixmap("../QtCode/game/assets/wallHorizontal.png"));
    else setCellPixmap(QPixmap("../QtCode/game/assets/wallVertical.png"));
}

void MenuWallCell::unsetWall() {
    setCellPixmap(QPixmap("../QtCode/game/assets/noWall.png"));
}