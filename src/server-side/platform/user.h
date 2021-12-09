//
// Created by Anton Romanova on 09/12/2021.
//

#ifndef INFO_F209_HEADERS_SERVER_SIDE_USER_H_
#define INFO_F209_HEADERS_SERVER_SIDE_USER_H_

#include <string>
#include <ctime>

class User {

  bool IsTempAccessTokenValid(const std::string &access_token);
  std::unique_ptr<std::string> GetTempAccessToken(const std::string &password);
  bool IsPasswordValid(const std::string &password);


  std::string &GetUsername() const;
  SetUsername();

  bool IsUserConnected() const;

 protected:
  time_t GetLastConnectionTime() const;
  time_t SetLastConnectionTime

 private:
  std::string username_;
  time_t last_connection_time_;

};

#endif //INFO_F209_HEADERS_SERVER_SIDE_USER_H_
