//
// Created by Anton Romanova on 31/03/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_VIEWS_VIEWS_H_
#define QUORIDOR_SRC_SERVER_SIDE_VIEWS_VIEWS_H_

#include "../../common/models/user_server.h"
#include "../../includes/crow_all.hpp"
#include "../utils.h"


crow::json::wvalue RankingListView(
    const crow::request &request
);

crow::json::wvalue UserExceptMeListView(
    UserServer &user, const crow::request &
);

crow::json::wvalue ThisUserDetailView(
    UserServer &user, const crow::request &
);

crow::json::wvalue AddFriendView(
    UserServer &user, const crow::request &request
);

crow::json::wvalue MyGamesListView(
    UserServer &user, const crow::request &
);

crow::json::wvalue GameDetailView(
    UserServer &user, const crow::request &, object_id_t game_id
);

crow::json::wvalue GameRepresentationView(
    UserServer &user, const crow::request &, object_id_t game_id
);

crow::json::wvalue GameIsMyTurnView(
    UserServer &user, const crow::request &, object_id_t game_id
);

crow::json::wvalue SubmitGameMoveView(
    UserServer &user, const crow::request &request, object_id_t game_id
);

crow::json::wvalue SubmitNewGameView(
    UserServer &user, const crow::request &request
);

crow::json::wvalue CreateNewUserView(
    const crow::request &request
);

crow::json::wvalue SendMessageView(
    UserServer &user, const crow::request &request
);

crow::json::wvalue MessagesListView(
    UserServer &user, const crow::request &request
);



#endif // QUORIDOR_SRC_SERVER_SIDE_VIEWS_VIEWS_H_
