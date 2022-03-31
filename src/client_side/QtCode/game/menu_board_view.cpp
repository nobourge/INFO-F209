#include "menu_board_view.h"
// #include <iostream>
using namespace std;

MenuBoardView::MenuBoardView(int game_id, QVector<QPoint> pawns_,
                             QVector<QPoint> walls_)
    : game_id{game_id}, QGraphicsView{new MenuBoardScene(pawns_, walls_)} {
  QGraphicsItem *item = scene()->itemAt({0, 0}, QTransform());
  MenuCell *newItem = static_cast<MenuCell *>(item);
  if (newItem != nullptr) {
    newItem->setCellPawn(true);
  }
  setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
  // api something
  auto game_or_error = ApiWrapper::GetShared()->GetGame(static_cast<uint32_t>(game_id));
  if (holds_alternative<ApiError>(game_or_error)) {
    // shouldn't happen as it's checked before arriving here
  } else {
    auto game = get<Game>(game_or_error);
    cout<<"do something with the game"<<endl;
    cout<<game.GetBoard()->GetBoardString()<<endl;
    this->setScene(new MenuBoardScene(game.GetBoard()->GetAllPlayersPos(), game.GetBoard()->GetAllWallsPos()));
  }
} // using super class constructor

void MenuBoardView::mousePressEvent(QMouseEvent *event) // Mouse click event
{
  qDebug() << "Custom view clicked.";
  if (mapToScene(event->pos()).x() > 17 * 32 || mapToScene(event->pos()).x() < 0 || mapToScene(event->pos()).y() > 17 * 32 || mapToScene(event->pos()).y() < 0) return;
  qDebug() << "in scene";
  MenuCell *newItem = static_cast<MenuCell *>(scene()->itemAt(mapToScene(event->pos()), QTransform()));

  // cout << mapToScene(event->pos()).x() << endl;
  // cout << mapToScene(event->pos()).y() << endl;
  
  if (newItem->isCellPawn()) {
    qDebug() << "clicked a cell pawn";
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

    firstPos = firstWall->getAbsolutePosition();
    secondPos = newItem->getAbsolutePosition();

    QPointF thirdPos;
      
    int direction_x = firstPos.x() - secondPos.x();
    int direction_y = firstPos.y() - secondPos.y();

    if (direction_x < 0 || direction_y < 0) {
      thirdPos = firstPos + QPoint{abs((firstPos - secondPos).x()/2), abs((firstPos - secondPos).y()/2)};
    }else {
      thirdPos = secondPos + QPoint{abs((firstPos - secondPos).x()/2), abs((firstPos - secondPos).y()/2)};
    }
    
    
    cout << firstPos.x() << " " << firstPos.y() << endl;
    cout << secondPos.x() << " " <<  secondPos.y() << endl;
    cout << thirdPos.x() << " " <<  thirdPos.y() << endl;
    
    thirdWall = static_cast<MenuCell *>(scene()->itemAt(thirdPos, QTransform()));

    placeWall(firstWall, newItem, thirdWall);
    firstWall = nullptr;
    thirdWall = nullptr;
  }
}

void MenuBoardView::placeWall(MenuCell *first, MenuCell *second, MenuCell *third) {
  if (!verifyWall(first->getPosition(), second->getPosition())) return;
  int dx = first->getPosition().x() - second->getPosition().x();
  int dy = first->getPosition().y() - second->getPosition().y();

  bool direction = abs(dx) > 0;

  static_cast<MenuWallCell *>(first)->setWall(direction);
  static_cast<MenuWallCell *>(second)->setWall(direction);
  static_cast<MenuWallCell *>(third)->setWall(direction);
}

bool MenuBoardView::verifyWall(QPoint firstWall, QPoint secondWall) {
  cout<<Translator::Get().PositionToWallMove({firstWall.x(), firstWall.y()}, {secondWall.x(), secondWall.y()})<<endl;
  if (firstWall - secondWall != QPoint{0,2} && firstWall - secondWall != QPoint{2,0}
      && firstWall - secondWall != QPoint{0,-2} && firstWall - secondWall != QPoint{-2,0}
      || (firstWall.x() % 2 != 0 && firstWall.y() % 2!= 0) || (firstWall.x() % 2 != 0 && firstWall.y() % 2!= 0) ) return false;
  return true;
}

void MenuBoardView::playMove(MenuCell *item) {
  // cout<<Translator::Get().PositionToMove({item->getPosition().x()/2, item->getPosition().y()/2})<<endl;
  ancientCell->setCellPixmap(QPixmap(cell_png.c_str()));
  ancientCell->setCellPawn(false);
  item->setCellPixmap(QPixmap(pawn_png.c_str()));
  item->setCellPawn(true);
}

bool MenuBoardView::verifyMove(QPoint pos1, QPoint pos2) {
  Position currentPlayerPos = get<Game>(ApiWrapper::GetShared()->GetGame(static_cast<uint32_t>(game_id))).GetCurrentPlayer()->getPlayerPos();
  cout<<currentPlayerPos.row<<" "<<currentPlayerPos.col<<endl;
  cout<<pos1.y()/2<<" "<<pos1.x()/2<<endl;

  if (currentPlayerPos.row != pos1.y()/2 || currentPlayerPos.col != pos1.x()/2) return false;
  if (pos1.y() == pos2.y() && pos2.x() - pos1.x() == 2) {
    // right
    cout<<"first"<<endl;
    
    cout<<Translator::Get().PositionToPawnMove(EAST, get<Game>(ApiWrapper::GetShared()->GetGame(static_cast<uint32_t>(game_id))).GetCurrentPlayer()->getGoal() )<<endl;
    return true;
  }
  if (pos1.y() == pos2.y() && pos1.x() - pos2.x() == 2) {
    // left
    cout<<"second"<<endl;
    cout<<Translator::Get().PositionToPawnMove(WEST, get<Game>(ApiWrapper::GetShared()->GetGame(static_cast<uint32_t>(game_id))).GetCurrentPlayer()->getGoal() )<<endl;
    return true;
  }
  if (pos1.x() == pos2.x() && pos2.y() - pos1.y() == 2) {
    // down 
    cout<<"third"<<endl;
    cout<<Translator::Get().PositionToPawnMove(SOUTH, get<Game>(ApiWrapper::GetShared()->GetGame(static_cast<uint32_t>(game_id))).GetCurrentPlayer()->getGoal() )<<endl;
    return true;
  }
  if (pos1.x() == pos2.x() && pos1.y() - pos2.y() == 2) {
    // up
    cout<<"fourth"<<endl;
    cout<<Translator::Get().PositionToPawnMove(NORTH, get<Game>(ApiWrapper::GetShared()->GetGame(static_cast<uint32_t>(game_id))).GetCurrentPlayer()->getGoal() )<<endl;
    return true;
  }
  return false;
}