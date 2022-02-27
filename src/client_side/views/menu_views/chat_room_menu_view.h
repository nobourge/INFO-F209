#ifndef INFO_F209_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_CHAT_ROOM_MENU_VIEW_H_
#define INFO_F209_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_CHAT_ROOM_MENU_VIEW_H_

#include <iostream>
#include <cstring>
#include <vector>
#include "abstract_menu_view.h"
#include "views/text_field.h"



class ChatRoomMenuView: public AbstractMenuView, public TextFieldDelegate {
 public:
  void TextChanged(TextField &sender, const std::string &old_text) override;
  void TextEditingFinished(TextField &sender) override;
  void MessageChanged(std::string new_message);
  ChatRoomMenuView();
 private:
  std::shared_ptr<TextField>text_field_;
  constexpr static const char menu_name_[] = "Chat Room Menu";
  std::string msg1="msg1";
  std::string msg2="msg2";
  std::string msg3="msg3";
};

#endif //INFO_F209_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_CHAT_ROOM_MENU_VIEW_H_
