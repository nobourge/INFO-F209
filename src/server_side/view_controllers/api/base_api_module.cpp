//
// Created by Anton Romanova on 15/02/2022.
//

#include "base_api_module.h"

template<class... Middlewares>
void BaseApiModule<Middlewares...>::SetupRoutes(const std::string &base_url, crow::Crow<Middlewares...> &app) {
  for (auto &module : submodules) {
    module.SetupRoutes(base_url, app);
  }
}