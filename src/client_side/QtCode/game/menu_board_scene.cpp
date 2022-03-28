#include "menu_board_scene.h"

using namespace std;

MenuBoardScene::MenuBoardScene() {
    for (int row = 0; row < 17; row++) {    // change magic number later
        for (int col = 0; col <17; col++) { // same as above
            if (col % 2 == 0 && row % 2 == 0) this->addItem(new MenuCell(32*row, 32*col,row,col,32,true));
            else this->addItem(new MenuWallCell(32*row, 32*col,row,col,32));
        }
        this->addItem(new MenuCell(32*0, 32*0,0,0,32,true,QPixmap(pawn_png.c_str())));
        //this->addItem(new MenuCell(32*0, 32*0,0,0,32,true,QPixmap("assets/pawn.png")));

    }

}

