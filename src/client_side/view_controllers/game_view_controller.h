//
// Created by guest on 01/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_VIEW_CONTROLLER_H_
#include "abstract_authed_menu_view_controller.h"
#include "../views/menu_views/views/label.h"
#include "../views/menu_views/views/text_field.h"
class GameViewController: public AbstractAuthedMenuViewController{
 public:
 GameViewController();
  std::optional<std::shared_ptr<AbstractViewController>> Tick() override;

};
#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_VIEW_CONTROLLER_H_
