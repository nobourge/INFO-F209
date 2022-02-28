//
// Created by Anton Romanova on 26/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_MODELS_REQUESTS_H_
#define QUORIDOR_SRC_CLIENT_SIDE_MODELS_REQUESTS_H_

#include <curl/curl.h>
#include <string>
#include <unordered_map>
#include "../../includes/crow_all.hpp"

class Requests {
public:
  Requests(const std::string &url,
           const std::optional<std::tuple<std::string, std::string>> login_password = {});
  ~Requests();

  [[nodiscard]] std::string GetText() const;

  [[nodiscard]] crow::json::rvalue GetJson() const {
    return crow::json::load(text_);
  }

private:
  ssize_t WriteData(void *data, size_t size, size_t nmemb) {
    ssize_t message_size_in_bytes = size * nmemb;

    // data is not null terminated, so we need to explicitly tell the size
    text_ += std::string(reinterpret_cast<char *>(data), message_size_in_bytes);
    return static_cast<ssize_t>(size * nmemb);
  }

  static ssize_t InvokeWriteData(void *data, size_t size, size_t nmemb,
                                 void *pInstance) {
      return ((Requests*)(pInstance))->WriteData(data, size, nmemb);
  }

  std::string text_ = {};
  CURL *curl_;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_MODELS_REQUESTS_H_
