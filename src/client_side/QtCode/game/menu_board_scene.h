#ifndef MENUBOARDSCENE_H
#define MENUBAORDSCENE_H

#include <menu_cell.h>
#include <menu_wall_cell.h>
#include "../../models/api_wrapper.h"
#include <QGraphicsScene>
#include <QVector>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>
#include <algorithm>
#include "assets.h"

class MenuBoardScene : public QGraphicsScene {
    int indexOfPawn = 0;
    const QVector<QPixmap> pawnPixMap {QPixmap(pawn_png.c_str()), QPixmap(red_pawn_png.c_str())};
    QPoint PairToPoint(pair<int, int> pair);
    QVector<QPoint> VectorToQVector(vector<pair<int, int>> vec);    
public:
    MenuBoardScene();
    MenuBoardScene(QVector<QPoint> pawns_, QVector<QPoint> walls_);
    MenuBoardScene(vector<pair<int, int>> pawns_, vector<pair<int, int>> walls_);
    
public slots:

};

#endif
