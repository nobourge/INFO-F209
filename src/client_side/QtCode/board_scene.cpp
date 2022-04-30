//
// Created by noe on 26.03.22.
//

#include <QLabel>
#include "board_scene.h"
#include "QGraphicsRectItem"
using namespace std;

BoardScene::BoardScene() {
  int cells_quantity = 17; // change magic number later
  int size = (666/cells_quantity);


  for (int row = 0; row < cells_quantity; row++) {
    for (int col = 0; col < cells_quantity; col++) {
      auto *rect = new QGraphicsRectItem();
      rect->setRect(row*size,col*size,size, size);
      this->addItem(rect);

/*
      QLabel *gif_anim = new QLabel();
      QMovie *movie = new QMovie(image);
      gif_anim->setMovie(movie);
      movie->start();
      QGraphicsProxyWidget *proxy = this.addWidget(gif_anim);
*/

      /*
      // this->addItem(new MenuCell(32*row, 32*col, 32));
      if (col % 2 == 0 && row % 2 == 0)
        //this->addItem(new Cell(32*row, 32*col,row,col,32));
      else
        //this->addItem(new WallCell(32*row, 32*col,row,col,32));
        */
    }
    //this->addItem(new PlayerCell(32*0, 32*0,0,0,32));

  }


}