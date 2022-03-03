//
// Created by Anton Romanova on 25/02/2022.
//

#include "message.h"

std::unique_ptr<crow::json::wvalue> Message::Serialize() {
  auto output = std::make_unique<crow::json::wvalue>();

  (*output)["id"] = message_id;
  (*output)["sender_id"] = sender_id;
  (*output)["receiver_id"] = receiver_id;
  (*output)["timestamp"] = timestamp_;
  (*output)["content"] = content_;

  return output;
}

std::optional<Message> Message::FromJson(const crow::json::rvalue &json) {
  try {
    return Message(json["id"].i(), json["sender_id"].i(),
                   json["receiver_id"].i(), json["timestamp"].i(),
                   json["content"].s());
  } catch (...) {
    return {};
  }
}

bool Message::operator==(const Message &rhs) const {
  return message_id == rhs.message_id && sender_id == rhs.sender_id &&
         receiver_id == rhs.receiver_id && timestamp_ == rhs.timestamp_ &&
         content_ == rhs.content_;
}

bool Message::operator!=(const Message &rhs) const { return !(rhs == *this); }
