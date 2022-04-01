
#ifndef MENUBAORDVIEW_H
#define MENUBAORDVIEW_H

#include <menu_board_scene.h>
#include <QGraphicsView>
#include <QMouseEvent>
#include <iostream>
#include <QPoint>

class MenuBoardView : public QGraphicsView {
    bool playerSelected=false;
    bool wallSelected=false;
    MenuCell* ancientCell=nullptr;
    MenuCell* firstWall=nullptr;
    MenuCell* thirdWall=nullptr;
    int game_id;
    QPointF firstPos;
    QPointF secondPos;

    bool SendMoveToServer(DIRECTION moveDirection, DIRECTION winningDirection) const;
    

public:
    MenuBoardView(int game_id, QVector<QPoint> pawns_={}, QVector<QPoint> walls_={});
    void playMove(MenuCell*);
    bool verifyMove(QPoint,QPoint);
    void placeWall(MenuCell*, MenuCell*, MenuCell*) const;
    bool verifyWall(QPoint, QPoint) const;
public slots:
    void mousePressEvent(QMouseEvent *event);
};

#endif