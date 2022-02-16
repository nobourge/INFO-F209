//
// Created by guest on 16/02/2022.
//

#ifndef INFO_F209_SRC_CLIENT_SIDE_CLIENT_MVC_FACTORY_H_
#define INFO_F209_SRC_CLIENT_SIDE_CLIENT_MVC_FACTORY_H_

class ClientMVCFactory {
 public:
  AbstractController* getController(string mvcname);
};

#endif //INFO_F209_SRC_CLIENT_SIDE_CLIENT_MVC_FACTORY_H_
