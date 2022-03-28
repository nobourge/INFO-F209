#ifndef MENUBOARDSCENE_H
#define MENUBAORDSCENE_H

#include <menu_cell.h>
#include <menu_wall_cell.h>
#include <QGraphicsScene>
#include <QVector>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>
#include <algorithm>
#include "assets.h"

class MenuBoardScene : public QGraphicsScene {
    QVector<QVector<MenuCell*>> cells;
public:
    MenuBoardScene();
    MenuBoardScene(QVector<QPoint> pawns_, QVector<QPoint> walls_);
    ~MenuBoardScene(){
        for(int i=0;i<cells.size();i++){
            for(int j=0;j<cells.size();j++){
                delete(cells[i][j]);
            }
        }
    }
public slots:

};

#endif
