#include "menu_cell.h"

using namespace std;
MenuCell::MenuCell(int x, int y,int row,int col,int size,bool isPlat, bool player, QPixmap pixmap): player{player}, pos{row, col}, isPlat(isPlat), position{x, y} {
    if (player) setCellPixmap(QPixmap(pawn_png.c_str()), size);
    else setCellPixmap(pixmap, size);
    setOffset(x, y);
}

void MenuCell::setCellPixmap(QPixmap pixmap, int size) {
    this->setPixmap(pixmap.scaled(size,size));
}

void MenuCell::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<"Cell clicked";
    //qDebug()<<event->pos();
    if (player) cout<<"a player was clicked"<<endl;
    cout<<"Pos in vector is ";
    cout<<pos.x()<<" "<<pos.y()<<endl;
}
