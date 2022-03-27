#ifndef MENUCELL_H
#define MENUCELL_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>

using namespace std;
class MenuCell : public QGraphicsPixmapItem {
    QPoint pos;
    bool player=false;
    bool isPlat=false;
public:
    MenuCell(int x, int y,int row,int col,int size=20,bool isPlat=false,QPixmap pixmap=QPixmap("../QtCode/game/assets/cell.png"));
    void setCellPixmap(QPixmap image, int size=32);

    QPoint getPosition(){return pos;}
    
    bool getPlat(){return isPlat;}
    virtual bool isCellPawn(){return player;}
    virtual bool isCellWall(){return false;}
    
    virtual void setCellPawn(bool newPlayer){player=newPlayer;}
public slots:
     void mousePressEvent(QGraphicsSceneMouseEvent *event);
     
};

#endif