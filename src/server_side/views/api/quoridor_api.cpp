//
// Created by Anton Romanova on 14/02/2022.
//

#include "quoridor_api.h"

const unsigned QuoridorAPI::kQuoridorApiVersion = 0;

const crow::SimpleApp &QuoridorAPI::GetApp() const {
  return app;
}

QuoridorAPI::QuoridorAPI() {
  SetupRoutes();
}

void QuoridorAPI::SetupRoutes() {

  CROW_ROUTE(app, "/")([] () {
    auto page = crow::mustache::load("index.html");
    return page.render();
  });

//  CROW_ROUTE(app, "/api")

}

void QuoridorAPI::Run() {
  app.port(PORT).multithreaded().run();
}
