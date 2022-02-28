//
// Created by guest on 27/02/2022.
//

#ifndef INFO_F209_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CHAT_ROOM_VIEW_CONTROLLER_H_
#define INFO_F209_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CHAT_ROOM_VIEW_CONTROLLER_H_

#include "../views/menu_views/views/label.h"
#include "../views/menu_views/views/text_field.h"
#include "menu_view_controller.h"

class ChatRoomViewController : public MenuViewController,
                               public TextFieldDelegate {
public:
  ChatRoomViewController();

  void TextChanged(TextField &sender, const std::string &old_text) override;
  void TextEditingFinished(TextField &sender) override;

private:
  void UpdateSubviews() {

    std::vector<std::shared_ptr<AbstractView>> subviews_;


    for (auto &message : messages_)
      subviews_.push_back(message);


    subviews_.push_back(text_field_);

    subviews_.push_back(std::make_shared<MenuButtonItem>(
        GetMenuView().get(), "Back",
        std::optional<std::shared_ptr<AbstractViewController>>{},
        GetMenuView().get())
    );

    GetMenuView()->UpdateSubviews(subviews_);
  }

  std::vector<std::shared_ptr<Label>> messages_;
  std::shared_ptr<TextField> text_field_;
};

#endif // INFO_F209_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CHAT_ROOM_VIEW_CONTROLLER_H_
