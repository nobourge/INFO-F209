//
// Created by Anton Romanova on 14/02/2022.
//

#include "base_quoridor_api.h"

const unsigned BaseQuoridorApi::kQuoridorApiVersion = 0;

crow::SimpleApp &BaseQuoridorApi::GetApp() {
  return app;
}

BaseQuoridorApi::BaseQuoridorApi() {
  SetupRoutes();
}

void BaseQuoridorApi::SetupRoutes() {
  CROW_ROUTE(GetApp(), "/")([] () {
    auto page = crow::mustache::load("index.html");
    return page.render();
  });
}

void BaseQuoridorApi::Run() {
  app.port(PORT).multithreaded().run();
}
