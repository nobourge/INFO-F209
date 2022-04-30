//
// Created by Anton Romanova on 25/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_MESSAGE_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_MESSAGE_H_

#include "../database.h"
#include "../../constants.h"
#include "../../utils.h"
#include "user.h"
#include <string>

class Message : public Serializable {
public:
  crow::json::wvalue Serialize() override;

  static std::optional<Message> FromJson(const crow::json::rvalue &json);

  Message(object_id_t message_id, object_id_t sender_id,
          object_id_t receiver_id, const std::string &content)
      : message_id(message_id), sender_id(sender_id), receiver_id(receiver_id),
        timestamp_(GET_UNIX_TIMESTAMP), content_(content) {}

  Message(object_id_t message_id, object_id_t sender_id,
          object_id_t receiver_id, int64_t timestamp,
          const std::string &content)
      : message_id(message_id), sender_id(sender_id), receiver_id(receiver_id),
        timestamp_(timestamp), content_(content) {}

  Message(const std::vector<std::string> &db_row_string_vector)
      : message_id(stoul(db_row_string_vector.at(0))),
        sender_id(stoul(db_row_string_vector.at(1))),
        receiver_id(stoul(db_row_string_vector.at(2))),
        timestamp_(stol(db_row_string_vector.at(3))),
        content_(db_row_string_vector.at(4)) {}

  const std::string &GetContent() const { return content_; }

  object_id_t GetSenderId() const { return sender_id; }

  int64_t GetTimestamp() const { return timestamp_; }

  bool operator==(const Message &rhs) const;
  bool operator!=(const Message &rhs) const;

private:
  object_id_t message_id;

  object_id_t sender_id;
  object_id_t receiver_id;

  int64_t timestamp_;
  std::string content_;
};

#endif // QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_MESSAGE_H_
