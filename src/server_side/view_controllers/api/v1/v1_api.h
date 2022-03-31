//
// Created by Anton Romanova on 15/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_
#define QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_

#include "../../../../common/models/user_server.h"
#include "../../../utils.h"
#include "../../../views/views.h"
#include "../base_quoridor_api.h"
#include <any>
#include <memory>

#define V1_API_PREFIX "/api/v1/"

template <class... Middlewares> class V1Api : public BaseQuoridorApi {
public:
  V1Api() { SetupRoutes(); };

  [[nodiscard]] unsigned int GetVersion() const;

protected:
  void SetupRoutes() override {
    BaseQuoridorApi::SetupRoutes();

#ifndef ROUTE
#define ROUTE(url, func)                                                        \
  GetApp().template route<crow::black_magic::get_parameter_tag(url)>(url)(func)


    // authed
    ROUTE("/api/v1/me", Auth(ThisUserDetailView));

    ROUTE("/api/v1/me/all-users-except-me", Auth(UserExceptMeListView));
    ROUTE("/api/v1/me/add_friend", Auth(AddFriendView));

    ROUTE("/api/v1/me/games", Auth(MyGamesListView));
    ROUTE("/api/v1/me/game/<uint>", Auth<uint32_t>(GameDetailView));
    ROUTE("/api/v1/me/game/<uint>/repr", Auth<uint32_t>(GameRepresentationView));
    ROUTE("/api/v1/me/game/<uint>/my_turn", Auth<uint32_t>(GameIsMyTurnView));
    ROUTE("/api/v1/me/game/<uint>/move", Auth<uint32_t>(SubmitGameMoveView));
    ROUTE("/api/v1/me/games/new", Auth(SubmitNewGameView));

    ROUTE("/api/v1/me/messages/send", Auth(SendMessageView));
    ROUTE("/api/v1/me/messages", Auth(MessagesListView));

    // no auth needed
    ROUTE("/api/v1/users/ranking", RankingListView);
    ROUTE("/api/v1/new_user", CreateNewUserView);

    ROUTE("/api/v1/users", []() {
      crow::json::wvalue output;
      output["users"] = SerializeUsersVector(UserServer::GetAllObjectsFromDB());
      return output;
    });

#undef ROUTE
#else
#error "ROUTE" already defined
#endif
  }

private:
  static constexpr const unsigned version_ = 1;
};

#undef V1_API_PREFIX

#endif // QUORIDOR_SRC_SERVER_SIDE_VIEWS_API_V1_API_H_

