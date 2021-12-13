//
// Created by Anton Romanova on 10/12/2021.
//

#ifndef QUORIDOR_SERVER_SIDE_API_CONTROLLER_V1_USER_CONTROLLER_H_
#define QUORIDOR_SERVER_SIDE_API_CONTROLLER_V1_USER_CONTROLLER_H_

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GameController : public oatpp::web::server::api::ApiController {
 public:

  MyController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) /* Inject object mapper */)
  : oatpp::web::server::api::ApiController(objectMapper)
      {}

  ENDPOINT("GET", "/", root) {
    return createResponse(Status::CODE_200, "Hello World!");
  }

  // TODO - more endpoints here

};

#include OATPP_CODEGEN_END(ApiController)

#endif //QUORIDOR_SERVER_SIDE_API_CONTROLLER_V1_USER_CONTROLLER_H_
