//
// Created by guest on 27/02/2022.
//

#include "chat_room_view_controller.h"
#include "../views/menu_views/chat_room_menu_view.h"

ChatRoomViewController :: ChatRoomViewController() : MenuViewController(std::make_shared<ChatRoomMenuView>()) {

}