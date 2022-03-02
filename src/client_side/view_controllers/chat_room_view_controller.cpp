//
// Created by guest on 27/02/2022.
//

#include "chat_room_view_controller.h"
#include "../models/api_wrapper.h"
#include "../views/menu_views/chat_room_menu_view.h"

ChatRoomViewController ::ChatRoomViewController()
    : AbstractAuthedMenuViewController(std::make_shared<ChatRoomMenuView>()) {
  text_field_ = std::make_shared<TextField>(GetMenuView().get(), "", this);

  messages_ = {std::make_shared<Label>(GetMenuView().get(), "msg1"),
               std::make_shared<Label>(GetMenuView().get(), "msg2"),
               std::make_shared<Label>(GetMenuView().get(), "msg3")};

  text_field_->SetPlaceholder("Text:");

  UpdateSubviews();
  listen_to_new_messages_ = true;
}

void ChatRoomViewController::TextChanged(TextField &sender,
                                         const std::string &old_text) {}
void ChatRoomViewController::TextEditingFinished(TextField &sender) {
   SendMessage("test");
  sender.SetInnerText("");
}

void ChatRoomViewController::ReceiveMessage(ChatRoomViewController *chatroom) {
  while (chatroom->listen_to_new_messages_) {
    auto &text_field = chatroom->text_field_;
    if (!text_field->IsEmpty() && !text_field->IsEventResponder()) {
      chatroom->new_messages_pending_ = true;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void ChatRoomViewController::SendMessage(std::string message) {
  auto api_wrapper = ApiWrapper::SendNewMessage(message);

  if ( holds_alternative<LoginError>(api_wrapper) ) {
    // error occurred
    error_message_ = get<LoginError>(api_wrapper).error_message;
  } else {
    // success creating account!
    error_message_ = {};
   }
}

void ChatRoomViewController::SlideMessages(std::string new_message) {
  messages_[2]->SetInnerText(messages_[1]->GetInnerText());
  messages_[1]->SetInnerText(messages_[0]->GetInnerText());
  messages_[0]->SetInnerText(new_message);
  text_field_->SetInnerText("");
  UpdateSubviews();
}

void ChatRoomViewController::MenuViewWillDisappear() {
  AbstractAuthedMenuViewController::MenuViewWillDisappear();
  listen_to_new_messages_ = false;
  t1_.join();
}

void ChatRoomViewController::MenuViewWillAppear() {
  AbstractAuthedMenuViewController::MenuViewWillAppear();
  t1_ = std::thread(ReceiveMessage, this);
}

void ChatRoomViewController::UpdateSubviews() {

  std::vector<std::shared_ptr<AbstractView>> subviews_;

  for (auto &message : messages_)
    subviews_.push_back(message);

  subviews_.push_back(text_field_);

  subviews_.push_back(std::make_shared<MenuButtonItem>(
      GetMenuView().get(), "Back",
      std::optional<std::shared_ptr<AbstractViewController>>{},
      GetMenuView().get()));

  GetMenuView()->UpdateSubviews(subviews_);
}

void ChatRoomViewController::Draw(WINDOW *window) {
  AbstractMenuViewController::Draw(window);
  if (new_messages_pending_) {
    if(ApiWrapper::IsThereNewMessage(0)){
      SlideMessages(ApiWrapper::ReceiveNewMessages(0));}
      new_messages_pending_ = false;
  }
}
