//
// Created by Anton Romanova on 25/02/2022.
//

#ifndef QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_MESSAGE_H_
#define QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_MESSAGE_H_

#include <string>
#include "user.h"
#include "../../../common/utils.h"
#include "../../../common/constants.h"

class Message : public DatabaseCompatible<Message> {
 public:
  static std::shared_ptr<Message> SendMessage(const std::shared_ptr<User> &sender,
                                              const std::shared_ptr<User> &receiver,
                                              const std::string &content) {
    return std::shared_ptr<Message>(new Message(GetMaxId() + 1, sender->GetId(), receiver->GetId(), content));
  }

  void SaveToDB() override {
  }

  Message &InitFromDB(object_id_t id) override {
    return *this;
  }

 protected:
  static uint32_t GetMaxId() {
    return 0;
  }

  Message(object_id_t message_id, object_id_t sender_id, object_id_t receiver_id, const std::string &content)
      : message_id(message_id),
        sender_id(sender_id),
        receiver_id(receiver_id),
        timestamp_(GET_UNIX_TIMESTAMP),
        content_(content) {}

 private:
  object_id_t message_id;

  object_id_t sender_id;
  object_id_t receiver_id;

  int64_t timestamp_;
  std::string content_;
};

#endif //QUORIDOR_SRC_SERVER_SIDE_MODELS_USER_MESSAGE_H_
