#include "menu_board_scene.h"
#include "assets.h"

using namespace std;

MenuBoardScene::MenuBoardScene() {
    for (int row = 0; row < 17; row++) {    // change magic number later
        for (int col = 0; col <17; col++) { // same as above
            if (col % 2 == 0 && row % 2 == 0) this->addItem(new MenuCell(32*row, 32*col,row,col,32,true));
            else this->addItem(new MenuWallCell(32*row, 32*col,row,col,32));
        }
        this->addItem(new MenuCell(32*0, 32*0,0,0,32,true, true, QPixmap(pawn_png.c_str())));
    }

}

MenuBoardScene::MenuBoardScene(QVector<QPoint> pawns_, QVector<QPoint> walls_) {
    for (int row = 0; row < 17; row++) {    // change magic number later
        for (int col = 0; col <17; col++) { // same as above
            if (col % 2 == 0 && row % 2 == 0) {
                if (find(pawns_.begin(), pawns_.end(), QPoint{row, col}) != pawns_.end()) this->addItem(new MenuCell(32*row, 32*col,row,col,32,true, true));
                else this->addItem(new MenuCell(32*row, 32*col,row,col,32,true)); 
            } else {
                if (find(walls_.begin(), walls_.end(), QPoint{row, col}) != walls_.end()) this->addItem(new MenuWallCell(32*row, 32*col,row,col,32, true));
                else this->addItem(new MenuWallCell(32*row, 32*col,row,col,32));
            }
        }
    }
}