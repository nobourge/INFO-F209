#include "menu_board_view.h"

#include <utility>
using namespace std;

MenuBoardView::MenuBoardView(int game_id, QVector<QPoint> pawns_,
                             QVector<QPoint> walls_)
    : game_id{game_id}, QGraphicsView{new MenuBoardScene(std::move(pawns_),
                                                         std::move(walls_))} {
  should_continue_fetching_ = std::make_shared<bool>(true);
  QGraphicsItem *item = scene()->itemAt({0, 0}, QTransform());

  MenuCell *newItem = dynamic_cast<MenuCell *>(item);

  if (newItem != nullptr) {
    newItem->setCellPawn(true);
  }
  setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
  // api something
  boardFetcher = new BoardFetcher(this, game_id, should_continue_fetching_);
  connect(boardFetcher, SIGNAL(updated()), this, SLOT(redrawScene()));
  drawScene();
  boardFetcher->start();
}

void MenuBoardView::drawScene() {
  auto game_or_error =
      ApiWrapper::GetShared()->GetGame(static_cast<uint32_t>(game_id));
  if (holds_alternative<ApiError>(game_or_error)) {
    // shouldn't happen as it's checked before arriving here
  } else {
    auto game = get<Game>(game_or_error);
    cout << "here" << endl;
    cout << game.GetBoard()->GetBoardString() << endl;
    this->setScene(new MenuBoardScene(game.GetBoard()->GetAllPlayersPos(),
                                      game.GetBoard()->GetAllWallsPos()));
  }
}

void MenuBoardView::mousePressEvent(QMouseEvent *event) // Mouse click event
{
  // redrawScene();
  if (mapToScene(event->pos()).x() > 17 * 32 ||
      mapToScene(event->pos()).x() < 0 ||
      mapToScene(event->pos()).y() > 17 * 32 ||
      mapToScene(event->pos()).y() < 0)
    return;
  MenuCell *newItem = dynamic_cast<MenuCell *>(
      scene()->itemAt(mapToScene(event->pos()), QTransform()));

  if (newItem->isCellPawn()) {
    playerSelected = true;
    ancientCell = newItem;
    return;
  } else if (newItem->isCellWall() && firstWall == nullptr) {
    firstWall = newItem;
    return;
  }
  if (playerSelected && newItem->getPlat()) {
    playerSelected = false;
    if (verifyMove(ancientCell->getPosition(), newItem->getPosition()))
      playMove(newItem);
  } else if (firstWall != nullptr) {
    placeWall(firstWall, newItem);
    firstWall = nullptr;
  }
}

void MenuBoardView::placeWall(MenuCell *first, MenuCell *second) const {
  if (!verifyWall(first->getPosition(), second->getPosition()))
    return;
  int dx = first->getPosition().x() - second->getPosition().x();

  bool direction = abs(dx) > 0;

  dynamic_cast<MenuWallCell *>(first)->setWall(direction);
  dynamic_cast<MenuWallCell *>(second)->setWall(direction);
}

bool MenuBoardView::verifyWall(QPoint firstWall, QPoint secondWall) const {
  if (firstWall - secondWall != QPoint{0, 2} &&
          firstWall - secondWall != QPoint{2, 0} &&
          firstWall - secondWall != QPoint{0, -2} &&
          firstWall - secondWall != QPoint{-2, 0} ||
      (firstWall.x() % 2 != 0 && firstWall.y() % 2 != 0) ||
      (firstWall.x() % 2 != 0 && firstWall.y() % 2 != 0))
    return false;

  string move = Translator::Get().PositionToWallMove(
      {firstWall.x(), firstWall.y()}, {secondWall.x(), secondWall.y()});

  optional<ApiError> voidOrGood = ApiWrapper::GetShared()->PerformGameMove(
      static_cast<object_id_t>(game_id), move);

  if (voidOrGood.has_value()) {
    // bad move
    return false;
  }
  return true;
}

void MenuBoardView::playMove(MenuCell *item) {
  ancientCell->setCellPixmap(QPixmap(cell_png.c_str()));
  ancientCell->setCellPawn(false);
  item->setCellPixmap(QPixmap(pawn_png.c_str()));
  item->setCellPawn(true);
}

bool MenuBoardView::SendMoveToServer(DIRECTION moveDirection,
                                     DIRECTION winningDirection) const {
  string move =
      Translator::Get().PositionToPawnMove(moveDirection, winningDirection);
  optional<ApiError> voidOrGood = ApiWrapper::GetShared()->PerformGameMove(
      static_cast<uint32_t>(game_id), move);
  if (voidOrGood.has_value()) {
    // bad move or api
    return false;
  } else {
    // good move
    return true;
  }
}

bool MenuBoardView::verifyMove(QPoint pos1, QPoint pos2) {
  Game game = get<Game>(
      ApiWrapper::GetShared()->GetGame(static_cast<uint32_t>(game_id)));
  shared_ptr<Player> currentPlayer = game.GetCurrentPlayer();
  UserClient current_user =
      get<UserClient>(ApiWrapper::GetShared()->GetCurrentUser());
  if (currentPlayer->getPlayerPos().row != pos1.y() / 2 ||
      currentPlayer->getPlayerPos().col != pos1.x() / 2 ||
      currentPlayer->GetUserId() != current_user.GetId())
    return false;

  if (pos1.y() == pos2.y() && pos2.x() - pos1.x() == 2) {
    // right
    return SendMoveToServer(EAST, currentPlayer->getGoal());
  }
  if (pos1.y() == pos2.y() && pos1.x() - pos2.x() == 2) {
    // left
    return SendMoveToServer(WEST, currentPlayer->getGoal());
  }
  if (pos1.x() == pos2.x() && pos2.y() - pos1.y() == 2) {
    // down
    return SendMoveToServer(SOUTH, currentPlayer->getGoal());
    ;
  }
  if (pos1.x() == pos2.x() && pos1.y() - pos2.y() == 2) {
    // up
    return SendMoveToServer(NORTH, currentPlayer->getGoal());
    ;
  }
  return false;
}

void MenuBoardView::redrawScene() {
  cout << "inside that thinh" <<endl; 
  this->scene()->deleteLater();
  this->drawScene();
}
MenuBoardView::~MenuBoardView() {
  *should_continue_fetching_ = false;
  boardFetcher->quit();
  boardFetcher->wait();
}
