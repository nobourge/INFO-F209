//
// Created by Anton Romanova on 26/02/2022.
//

#include "requests.h"
#include <curl/curl.h>

Requests::Requests(const std::string &url,
                   const std::optional<std::tuple<std::string, std::string>> login_password)
    : curl_(curl_easy_init()) {

  if (!curl_) {
    throw std::runtime_error("Failed to initialize curl");
  }
  auto url_cstr = url.c_str();




  curl_easy_setopt(curl_, CURLOPT_URL, url_cstr);
  curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, Requests::InvokeWriteData);
  curl_easy_setopt(curl_, CURLOPT_WRITEDATA, this);

  if (login_password.has_value()) {
    curl_easy_setopt(curl_, CURLOPT_USERNAME, std::get<0>(*login_password).c_str());
    curl_easy_setopt(curl_, CURLOPT_PASSWORD, std::get<1>(*login_password).c_str());
  }


  CURLcode res = curl_easy_perform(curl_);

  if (res != CURLE_OK) {
    std::string err = "Problem occurred during request: ";
    throw std::runtime_error(err + curl_easy_strerror(res));
  }
}

Requests::~Requests() { curl_easy_cleanup(curl_); }

std::string Requests::GetText() const { return text_; }
