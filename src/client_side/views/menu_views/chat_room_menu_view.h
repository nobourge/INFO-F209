#ifndef INFO_F209_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_CHAT_ROOM_MENU_VIEW_H_
#define INFO_F209_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_CHAT_ROOM_MENU_VIEW_H_

#include <iostream>
#include <cstring>
#include <vector>
#include "abstract_menu_view.h"
#include "views/text_field.h"



class ChatRoomMenuView: public AbstractMenuView {
 public:
  ChatRoomMenuView();
 private:
  constexpr static const char menu_name_[] = "Chat Room Menu";
};

#endif //INFO_F209_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_CHAT_ROOM_MENU_VIEW_H_
