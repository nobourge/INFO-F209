//
// Created by Anton Romanova on 14/02/2022.
//

#include "base_quoridor_api.h"
#include "../../../common/constants.h"

const unsigned BaseQuoridorApi::kQuoridorApiVersion = 0;

///
/// \return
crow::SimpleApp &BaseQuoridorApi::GetApp() {
  return app;
}

BaseQuoridorApi::BaseQuoridorApi() {}

///

void BaseQuoridorApi::SetupRoutes() {
  CROW_ROUTE(GetApp(), "/")([] () {
    auto page = crow::mustache::load("index.html");
    return page.render();
  });
}

///

void BaseQuoridorApi::Run() {
  app.port(SERVER_PORT).multithreaded().run();
}
