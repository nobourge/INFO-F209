//
// Created by Anton Romanova on 23/02/2022.
//

#include "text_field.h"

bool TextField::RespondToEvent(const int &character) {
  if (IsCharAccepted(character)) {
    SetInnerText(GetInnerText() + static_cast<char>(character));
    return true;
  } else if (character == KEY_BACKSPACE && !GetInnerText().empty()) {
    SetInnerText(GetInnerText().substr(0, GetInnerText().size() - 1));
  }
  return false;
}

bool TextField::IsCharAccepted(const int &character) {
  static const std::vector<int> valid_chars = USERNAME_VALID_SPECIAL_CHARS;
  return (isalnum(character)) || std::find(valid_chars.begin(), valid_chars.end(), character) != valid_chars.end();
}

TextField::TextField(const std::optional<EventResponder *> &parent,
                     const std::string &default_text,
                     const std::optional<TextFieldDelegate *> &delegate) : AbstractView(parent, default_text), delegate_(delegate) {
}

void TextField::SetInnerText(const std::string &inner_text) {
  AbstractView::SetInnerText(inner_text);
  if (delegate_.has_value()) {
    (*delegate_)->TextChanged(inner_text);
  }
}

void TextField::HasBeenUnselected() {
  AbstractView::HasBeenUnselected();
  if (delegate_.has_value()) {
    (*delegate_)->TextEditingFinished();
  }
}
