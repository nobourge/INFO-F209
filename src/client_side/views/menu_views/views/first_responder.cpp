//
// Created by Anton Romanova on 22/02/2022.
//

#include "first_responder.h"

EventResponder::EventResponder(const std::optional<EventResponder *> &next) : next_(next) {}

bool EventResponder::IsEventResponder() const {
  return is_first_responder_;
}

void EventResponder::BecomeEventResponder() {
  if (CanBecomeEventResponder()) {
    is_first_responder_ = true;
  }
}

void EventResponder::ResignEventResponderStatus() {
  is_first_responder_ = false;
}

bool EventResponder::RespondToKeyboardEventIfFirstResponder(const int &character) {
  if (IsEventResponder()) {
    if (RespondToEvent(character)) {
      return true;
    } else {
      return next_.has_value() && (*next_)->RespondToEvent(character);
    }
  };
  return false;
}

bool EventResponder::PropagateEvent(const int &character) {
  auto children = GetChildren();
  for (auto &child : *children)
    if (child->PropagateEvent(character))
      return true;
  return RespondToKeyboardEventIfFirstResponder(character);
}

bool EventResponder::CanBecomeEventResponder() {
  return true;
}

