//
// Created by Anton Romanova on 09/12/2021.
//

#ifndef QUORIDOR_HEADERS_SERVER_SIDE_PLATFORM_USER_H_
#define QUORIDOR_HEADERS_SERVER_SIDE_PLATFORM_USER_H_

#include <string>
#include <ctime>

class User {
  bool IsTempAccessTokenValid(const std::string &access_token);
  std::unique_ptr<std::string> GetTempAccessToken(const std::string &password);
  bool IsPasswordValid(const std::string &password);


  std::string &GetUsername() const;

  // whether the user has had any interaction with the server in some fixed interval of secs
  bool IsUserConnected() const;

 protected:
  time_t GetLastConnectionTime() const;
  void SetLastConnectionTimeToNow();
};

#endif //QUORIDOR_HEADERS_SERVER_SIDE_PLATFORM_USER_H_
