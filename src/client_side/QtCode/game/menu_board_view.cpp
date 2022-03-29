#include "menu_board_view.h"
#include <iostream>
using namespace std;

MenuBoardView::MenuBoardView(int game_id, QVector<QPoint> pawns_,
                             QVector<QPoint> walls_)
    : game_id{game_id}, QGraphicsView{new MenuBoardScene(pawns_, walls_)} {
  QGraphicsItem *item = scene()->itemAt({0, 0}, QTransform());
  MenuCell *newItem = static_cast<MenuCell *>(item);
  if (newItem != nullptr) {
    newItem->setCellPawn(true);
  }
} // using super class constructor

void MenuBoardView::mousePressEvent(QMouseEvent *event) // Mouse click event
{
  qDebug() << "Custom view clicked.";
  if (event->position().x() > 17 * 32 || event->position().x() < 0 ||
      event->position().y() > 17 * 32 || event->position().y() < 0)
    return; // change magic number to const later
  MenuCell *newItem = static_cast<MenuCell *>(
      scene()->itemAt(mapToScene(event->pos()), QTransform()));
  if (newItem->isCellPawn()) {
    playerSelected = true;
    ancientCell = newItem;
    return;
  } else if (newItem->isCellWall() && firstWall == nullptr) {
    firstWall = newItem;
    return;
  }
  if (playerSelected && newItem->getPlat() &&
      verifyMove(ancientCell->getPosition(), newItem->getPosition())) {
    playerSelected = false;
    playMove(newItem);
  } else if (firstWall != nullptr) {
    cout << "placing a wall !" << endl;
    placeWall(firstWall, newItem);
    firstWall = nullptr;
  }
}

void MenuBoardView::placeWall(MenuCell *first, MenuCell *second) {
  if (!verifyWall(first->getPosition(), second->getPosition()))
    return;
  int dx = first->getPosition().x() - second->getPosition().x();
  int dy = first->getPosition().y() - second->getPosition().y();

  bool direction = abs(dx) > 0;

  static_cast<MenuWallCell *>(first)->setWall(direction);
  static_cast<MenuWallCell *>(second)->setWall(direction);
}

bool MenuBoardView::verifyWall(QPoint firstWall, QPoint secondWall) {return true;}

void MenuBoardView::playMove(MenuCell *item) {
  ancientCell->setCellPixmap(QPixmap(cell_png.c_str()));
  ancientCell->setCellPawn(false);
  item->setCellPixmap(QPixmap(pawn_png.c_str()));
  item->setCellPawn(true);
}

bool MenuBoardView::verifyMove(QPoint pos1, QPoint pos2) {
  if (pos1.y() == pos2.y() && pos2.x() - pos1.x() == 2) {
    return true;
  }
  if (pos1.y() == pos2.y() && pos1.x() - pos2.x() == 2) {
    return true;
  }
  if (pos1.x() == pos2.x() && pos2.y() - pos1.y() == 2) {
    return true;
  }
  if (pos1.x() == pos2.x() && pos1.y() - pos2.y() == 2) {
    return true;
  }
  return false;
}