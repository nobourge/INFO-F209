
#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_Game_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_Game_H_

#include"board.h"
#include"Player.h"
#include"memory"

class Game{
    std::shared_ptr<Board> board=std::make_shared<Board>();
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<Player> currentPlayer;

public:
    Game();
    void SwitchCurrentPlayer();
    void StartTheGame();
    int getScore();
    bool hasCurrentPlayerWon();
};


#endif