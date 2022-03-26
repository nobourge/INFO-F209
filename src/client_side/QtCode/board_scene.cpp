//
// Created by noe on 26.03.22.
//

#include "board_scene.h"
#include "QGraphicsRectItem"
using namespace std;

MenuBoardScene::MenuBoardScene() {
  auto *rect = new QGraphicsRectItem();
  rect->setRect(0, 0, 100, 100);
  this->addItem(rect);
  /*
  for (int row = 0; row < 17; row++) {    // change magic number later
    for (int col = 0; col <17; col++) { // same as above
      // this->addItem(new MenuCell(32*row, 32*col, 32));
      if (col % 2 == 0 && row % 2 == 0) this->addItem(new MenuCell(32*row, 32*col,row,col,32));
      else this->addItem(new MenuWallCell(32*row, 32*col,row,col,32));
    }
    this->addItem(new MenuPlayerCell(32*0, 32*0,0,0,32));

  }
   */

}