//
// Created by Anton Romanova on 10/12/2021.
//

#ifndef QUORIDOR_SERVER_SIDE_API_V1_USER_H_
#define QUORIDOR_SERVER_SIDE_API_V1_USER_H_

#include "score.h"
#include "game.h"
#include <string>
#include <memory>
#include <optional>

class APIUser {
 public:
  [[nodiscard]] static bool Create(const std::string &username, const std::string &password);
  [[nodiscard]] static bool IsUserRegistered(const std::string &username);

  std::unique_ptr<std::optional<std::string>> GetAccessToken(const std::string &password);

  bool ResetPassword(const std::string &new_password, const std::string &secret_question_answer);
  bool DeleteAccount(const std::string &password);

  bool SetBio(const std::string &access_token, const std::string &new_bio);
  [[nodiscard]] const std::string &GetBio() const;

  [[nodiscard]] Score GetScore() const;
  [[nodiscard]] std::unique_ptr<std::vector<std::shared_ptr<APIUser>>> GetFriends() const;

  [[nodiscard]] std::unique_ptr<std::vector<std::shared_ptr<Game>>> GetGameRequests(const std::string &access_token) const;
  [[nodiscard]] std::unique_ptr<std::vector<std::shared_ptr<Game>>> GetGames(const std::string &access_token) const;
};

#endif //QUORIDOR_SERVER_SIDE_API_V1_USER_H_
