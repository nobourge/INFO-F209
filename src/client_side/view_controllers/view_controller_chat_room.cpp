//
// Created by guest on 27/02/2022.
//

#include "view_controller_chat_room.h"
#include "../models/api_wrapper.h"
#include "../views/menu_views/chat_room_menu_view.h"

ChatRoomViewController::ChatRoomViewController(
    const UserClient &user_to_chat_with)
    : AbstractAuthedMenuViewController(std::make_shared<ChatRoomMenuView>()),
      user_to_chat_with_(user_to_chat_with) {
  message_text_field_ =
      std::make_shared<TextField>(GetMenuView().get(), "", this);
  message_text_field_->SetPlaceholder("New message:");

  UpdateSubviews();
}

void ChatRoomViewController::TextChanged(TextField &sender,
                                         const std::string &old_text) {}

void ChatRoomViewController::TextEditingFinished(TextField &sender) {
  if (&sender == message_text_field_.get()) {
    if (!message_text_field_->IsEmpty()) {
      SendMessage(message_text_field_->GetUserEnteredText());
      message_text_field_->SetInnerText("");
    }
  }
}

void ChatRoomViewController::SendMessage(const std::string &message) {
  auto api_wrapper = ApiWrapper::GetShared();

  if (api_wrapper.has_value()) {
    auto message_res = api_wrapper->SendNewMessage(user_to_chat_with_, message);
    if (message_res.has_value()) {
      error_message_ = message_res->error_message;
    }
  } else {
    error_message_ = "Not signed in";
  }

  UpdateSubviews();
}

void ChatRoomViewController::MenuViewWillDisappear() {
  AbstractAuthedMenuViewController::MenuViewWillDisappear();
}

void ChatRoomViewController::MenuViewWillAppear() {
  AbstractAuthedMenuViewController::MenuViewWillAppear();
  FetchMessages();
}

void ChatRoomViewController::UpdateSubviews() {
  std::vector<std::shared_ptr<AbstractView>> subviews_;

  if (error_message_.has_value()) {
    subviews_.push_back(
        std::make_shared<Label>(GetMenuView().get(), *error_message_));
  } else {
    long start = std::max(
        static_cast<int>(messages_.size()) - max_num_messages_to_display, 0);

    for (int i = start; i < messages_.size(); i++) {
      auto &message = messages_.at(i);
      auto label =
          std::make_shared<Label>(GetMenuView().get(), message.GetContent());

      // make bubbles highlighted
      if (message.GetSenderId() != user_to_chat_with_.GetId()) {
        // if the sender is this user
        label->SetDisplayMode(Label::UNDERLINE);
      }
      subviews_.push_back(label);
    }

    // separator
    subviews_.push_back(
        std::make_shared<Label>(GetMenuView().get(), "__________"));

    subviews_.push_back(message_text_field_);
  }

  GetMenuView()->UpdateSubviews(subviews_);
}

void ChatRoomViewController::Draw(WINDOW *window) {
  if (ShouldFetchMessages()) {
    FetchMessages();
  }
  AbstractMenuViewController::Draw(window);
}

void ChatRoomViewController::FetchMessages() {
  auto fetch_res =
      ApiWrapper::GetShared()->GetConversationWithUser(user_to_chat_with_);
  if (std::holds_alternative<ApiError>(fetch_res)) {
    error_message_ = std::get<ApiError>(fetch_res).error_message;
    messages_ = {};
  } else {
    error_message_ = {};
    auto new_messages = std::get<std::vector<Message>>(fetch_res);
    if (messages_ != new_messages) {
      messages_ = std::move(new_messages);
      UpdateSubviews();
    }
  }
  last_fetched_messages_ = GET_TIME_IN_MILLIS;
}

bool ChatRoomViewController::ShouldFetchMessages() const {
  return !error_message_.has_value() &&
         last_fetched_messages_ + min_interval_between_fetches_millis <
             GET_TIME_IN_MILLIS;
}
