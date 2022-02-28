//
// Created by Anton Romanova on 28/02/2022.
//

#include "user_client.h"

UserClient::UserClient(const crow::json::rvalue &json)
    : User(static_cast<int>(json["id"]),
           Username{json["username"].s()},
           static_cast<int>(json["created_timestamp"]),
           static_cast<int>(json["score"])) {}
