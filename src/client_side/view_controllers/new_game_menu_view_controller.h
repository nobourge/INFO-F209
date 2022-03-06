#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_NEW_GAME_MENU_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_NEW_GAME_MENU_VIEW_CONTROLLER_H_

#include "../views/menu_views/new_game_menu_view.h"
#include "abstract_authed_menu_view_controller.h"
#include "ncurses.h"
#include "../views/menu_views/views/text_field.h"
#include <string>


class NewGameMenuViewController : public AbstractAuthedMenuViewController, public TextFieldDelegate {
 public:
   NewGameMenuViewController();
   void TextChanged(TextField &sender, const std::string &old_text) override;
   void TextEditingFinished(TextField &sender) override;
   void CreateGame();
   void ReloadSubviews();

 protected:
   void MenuViewWillAppear() override;

 private:
   std::shared_ptr<TextField> title_field_;
   std::shared_ptr<TextField> opponent_username_field_;
   std::optional<std::string> notification_message_;
   bool created = false;
};



#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_NEW_GAME_MENU_VIEW_CONTROLLER_H_