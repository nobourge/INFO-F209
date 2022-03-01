//
// Created by guest on 27/02/2022.
//

#ifndef INFO_F209_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CHAT_ROOM_VIEW_CONTROLLER_H_
#define INFO_F209_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CHAT_ROOM_VIEW_CONTROLLER_H_

#include "../views/menu_views/views/label.h"
#include "../views/menu_views/views/text_field.h"
#include "abstract_authed_menu_view_controller.h"
#include <thread>

class ChatRoomViewController : public AbstractAuthedMenuViewController,
                               public TextFieldDelegate {
public:
  ChatRoomViewController();

  void TextChanged(TextField &sender, const std::string &old_text) override;
  void TextEditingFinished(TextField &sender) override;
  void SlideMessages(std::string new_message);
  void MenuViewWillDisappear() override;

  void Draw(WINDOW *window) override;

protected:
  void MenuViewWillAppear() override;

private:
  static void ReceiveMessage(ChatRoomViewController *chatroom);
  void SendMessage(std::string message);

  void UpdateSubviews();

  std::atomic_bool listen_to_new_messages_ = false;
  std::atomic_bool new_messages_pending_ = false;
  std::vector<std::shared_ptr<Label>> messages_;
  std::shared_ptr<TextField> text_field_;
  std::thread t1_;
};

#endif // INFO_F209_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CHAT_ROOM_VIEW_CONTROLLER_H_
