//
// Created by noe on 26.03.22.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_QTCODE_BOARD_SCENE_H_
#define QUORIDOR_SRC_CLIENT_SIDE_QTCODE_BOARD_SCENE_H_

#include <QGraphicsScene>
class MenuBoardScene : public QGraphicsScene {
  //QVector<QVector<MenuCell*>> cells;
 public:
  MenuBoardScene();
  ~MenuBoardScene(){
    /*
    for(int i=0;i<cells.size();i++){
      for(int j=0;j<cells.size();j++){
        delete(cells[i][j]);
      }
    }
     */
  }
 public slots:

};

#endif //QUORIDOR_SRC_CLIENT_SIDE_QTCODE_BOARD_SCENE_H_
