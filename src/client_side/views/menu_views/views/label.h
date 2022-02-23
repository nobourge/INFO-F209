//
// Created by Anton Romanova on 22/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_LABEL_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_LABEL_H_

#include "abstract_view.h"

class Label : public AbstractView {
 public:
  Label(const std::optional<EventResponder *> &parent, const std::string &inner_text);
  bool CanBecomeEventResponder() override;

 protected:
  bool RespondToEvent(const int &character) override;
};

#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_LABEL_H_
