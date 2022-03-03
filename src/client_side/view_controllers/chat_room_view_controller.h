//
// Created by guest on 27/02/2022.
//

#ifndef INFO_F209_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CHAT_ROOM_VIEW_CONTROLLER_H_
#define INFO_F209_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CHAT_ROOM_VIEW_CONTROLLER_H_

#include "../views/menu_views/views/label.h"
#include "../views/menu_views/views/text_field.h"
#include "abstract_authed_menu_view_controller.h"
#include "../models/user_client.h"
#include "../../common/models/user/message.h"
#include <thread>
#include <atomic>

class ChatRoomViewController : public AbstractAuthedMenuViewController,
                               public TextFieldDelegate {
public:

  static const constexpr long min_interval_between_fetches_millis = 250;
  static const constexpr int max_num_messages_to_display = 3;

  ChatRoomViewController(const UserClient &user_to_chat_with);

  void TextChanged(TextField &sender, const std::string &old_text) override;
  void TextEditingFinished(TextField &sender) override;
  void MenuViewWillDisappear() override;

  void Draw(WINDOW *window) override;

protected:
  void MenuViewWillAppear() override;

private:

  void FetchMessages();

  void SendMessage(const std::string &message);

  void UpdateSubviews();

  [[nodiscard]] bool ShouldFetchMessages() const;

  static long GetTimeInMillis();

  uint64_t last_fetched_messages_;

  UserClient user_to_chat_with_;

  std::optional<std::string> error_message_ = {};

  std::vector<Message> messages_;

  std::shared_ptr<TextField> message_text_field_;
};

#endif // INFO_F209_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_CHAT_ROOM_VIEW_CONTROLLER_H_
