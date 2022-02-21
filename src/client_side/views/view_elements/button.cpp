//
// Created by Anton Romanova on 18/02/2022.
//

#include "button.h"

const std::string &Button::GetTitle() const {
  return title_;
}

void Button::SetTitle(const std::string &title) {
  title_ = title;
}

Button::State Button::GetState() const {
  return state_;
}

void Button::SetState(Button::State state) {
  auto old_state = state_;
  state_ = state;
  if (old_state != state && state == SELECTED) {
    if (delegate_.has_value()) {
      (*delegate_)->ButtonClicked(*this);
    }
  }
}

Button::Button(const std::string &title, const std::optional<ButtonDelegate *> &delegate) :
    title_(title), delegate_(delegate) {}

void Button::SetDelegate(const std::optional<ButtonDelegate *> &delegate) {
  delegate_ = delegate;
}

void Button::Click() {
  SetState(SELECTED);
}
