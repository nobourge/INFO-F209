//
// Created by guest on 01/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_VIEW_CONTROLLER_H_
#include "menu_view_controller.h"
#include "../views/menu_views/views/label.h"
#include "../views/menu_views/views/text_field.h"
class GameViewController: public MenuViewController, public TextFieldDelegate{
 public:
 GameViewController();
  void TextChanged(TextField &sender, const std::string &old_text) override;
  void TextEditingFinished(TextField &sender) override;

}
#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_VIEW_CONTROLLER_H_
