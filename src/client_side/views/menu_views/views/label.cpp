//
// Created by Anton Romanova on 22/02/2022.
//

#include "label.h"
bool Label::CanBecomeEventResponder() {
  return false;
}

bool Label::RespondToEvent(const int &character) {
  return false;
}

Label::Label(const std::optional<EventResponder *> &parent, const std::string &inner_text) : AbstractView(parent,
                                                                                                          inner_text) {}
