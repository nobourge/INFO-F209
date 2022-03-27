#include "menu_cell.h"

using namespace std;
MenuCell::MenuCell(int x, int y,int row,int col,int size,bool isPlat, QPixmap pixmap): pos{row, col},isPlat(isPlat) {
    setCellPixmap(pixmap, size);
    setOffset(x, y);
}

void MenuCell::setCellPixmap(QPixmap pixmap, int size) {
    this->setPixmap(pixmap.scaled(size,size));
}

void MenuCell::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<"Cell clicked";
    //qDebug()<<event->pos();
    cout<<"Pos in vector is "; 
    cout<<pos.x()<<" "<<pos.y()<<endl;
}