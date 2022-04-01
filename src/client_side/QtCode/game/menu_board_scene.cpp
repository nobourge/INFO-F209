#include "menu_board_scene.h"

using namespace std;

MenuBoardScene::MenuBoardScene() {}

MenuBoardScene::MenuBoardScene(QVector<QPoint> pawns_, QVector<QPoint> walls_) {
    for (int row = 0; row < 17; row++) {    // change magic number later
        for (int col = 0; col <17; col++) { // same as above
            if (col % 2 == 0 && row % 2 == 0) {
                if (find(pawns_.begin(), pawns_.end(), QPoint{row, col}) != pawns_.end()) {
                    cout << indexOfPawn << endl;
                    this->addItem(new MenuCell(32*row, 32*col,row,col,32,true, true, pawnPixMap[indexOfPawn]));
                    indexOfPawn++;
                } else this->addItem(new MenuCell(32*row, 32*col,row,col,32,true)); 
            } else {
                if (find(walls_.begin(), walls_.end(), QPoint{row, col}) != walls_.end()) this->addItem(new MenuWallCell(32*row, 32*col,row,col,32, true));
                else this->addItem(new MenuWallCell(32*row, 32*col,row,col,32));
            }
        }
    }
}

MenuBoardScene::MenuBoardScene(vector<pair<int, int>> pawns_, vector<pair<int, int>> walls_) : MenuBoardScene{VectorToQVector(pawns_), VectorToQVector(walls_)} {}

QPoint MenuBoardScene::PairToPoint(pair<int, int> pair ) {
    return {pair.first, pair.second};
}

QVector<QPoint> MenuBoardScene::VectorToQVector(vector<pair<int,int>> vec) {
    QVector<QPoint> temp_vec;
    for (auto pair: vec) {
        temp_vec.push_back(PairToPoint(pair));
    }
    return temp_vec;
}