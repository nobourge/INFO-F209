//
// Created by Anton Romanova on 18/02/2022.
//

#include "button.h"

Button::Button(const std::optional<EventResponder *> &parent,
               const std::string &title,
               const std::function<void()> &click_handler) : AbstractView(parent, title),
                                                             click_handler_(click_handler) {}

void Button::Click() {
  AbstractView::SetState(AbstractView::SELECTED);
}

bool Button::RespondToEvent(const int &character) {
  if (character == '\n') {
    HasBeenSelected();
    return true;
  }
  return false;
}

void Button::HasBeenSelected() {
  AbstractView::HasBeenSelected();
  HandleClick();

  UnselectIfPossible();
}

void Button::HandleClick() {
  click_handler_();
}



