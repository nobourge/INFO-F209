#include "menu_cell.h"

using namespace std;
MenuCell::MenuCell(int x, int y,int row,int col,int size,bool isPlat, bool player, QPixmap pixmap): player{player}, pos{row, col}, isPlat(isPlat), position{x, y} {
    setCellPixmap(pixmap);
    setOffset(x, y);
}

void MenuCell::setCellPixmap(QPixmap pixmap, int size) {
    this->setPixmap(pixmap.scaled(size,size));
}

void MenuCell::mousePressEvent(QGraphicsSceneMouseEvent *event){}
