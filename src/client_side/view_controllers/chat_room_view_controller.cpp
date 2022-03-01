//
// Created by guest on 27/02/2022.
//

#include "chat_room_view_controller.h"
#include "../views/menu_views/chat_room_menu_view.h"
#include "../views/menu_views/views/label.h"
#include "../models/api_wrapper.h"

ChatRoomViewController :: ChatRoomViewController() : AbstractAuthedMenuViewController(std::make_shared<ChatRoomMenuView>()) {
  text_field_ = std::make_shared<TextField>(GetMenuView().get(), "", this);

  messages_ = {
      std::make_shared<Label>(GetMenuView().get(), "msg1"),
      std::make_shared<Label>(GetMenuView().get(), "msg2"),
      std::make_shared<Label>(GetMenuView().get(), "msg3")
  };

  text_field_->SetPlaceholder("Text:");

  UpdateSubviews();
  t1 = std::thread(ReceiveMessage, this);
}


void ChatRoomViewController::TextChanged(TextField &sender,
                                         const std::string &old_text) {

}
void ChatRoomViewController::TextEditingFinished(TextField &sender) {
  SendMessage("test");

}
void ChatRoomViewController::ReceiveMessage(ChatRoomViewController *chatroom) {
  chatroom->MessagesReceivable=true;
  while(chatroom->MessagesReceivable) {
    if (!chatroom->messages_.empty() && ApiWrapper::IsThereNewMessage(0)){
      SlideMessages(chatroom,ApiWrapper::ReceiveNewMessages(0));
    }
  }
}
void ChatRoomViewController::SendMessage(std::string message) {
ApiWrapper::SendNewMessages(message);
}
void ChatRoomViewController::SlideMessages(ChatRoomViewController *chatroom,std::string new_message) {
  chatroom->messages_[2]->SetInnerText(chatroom->messages_[1]->GetInnerText());
  chatroom->messages_[1]->SetInnerText(chatroom->messages_[0]->GetInnerText());
  chatroom->messages_[0]->SetInnerText(new_message);
  chatroom->text_field_->SetInnerText("");
  chatroom->UpdateSubviews();
}
void ChatRoomViewController::MenuViewWillDisappear() {
  AbstractAuthedMenuViewController::MenuViewWillDisappear();
  MessagesReceivable=false;
}
