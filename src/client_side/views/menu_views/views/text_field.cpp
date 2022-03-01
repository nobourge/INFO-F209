//
// Created by Anton Romanova on 23/02/2022.
//

#include "text_field.h"

bool TextField::RespondToEvent(const int &character) {
  bool responded_to_event = true;
  if (IsCharAccepted(character)) {
    // user types a character
    std::string c;
    c += static_cast<char>(character);

    SetInnerText(IsEmpty() ? c : GetUserEnteredText() + c);
  } else if (character == BACKSPACE_CHAR && !GetInnerText().empty()) {
    // user deletes a character

    if (!IsEmpty()) {
      if (GetInnerText().size() > 1) {
        SetInnerText(GetInnerText().substr(0, GetInnerText().size() - 1));
      } else if (GetInnerText().size() == 1){
        SetInnerText("");
        is_showing_placeholder_ = true;
      }
    } else {
      responded_to_event = false;
    }
  }else if (character == '\n') {
    // user clicks enter
    SetState(HOVER);
  } else {
    responded_to_event = false;
  }
  return responded_to_event;
}

bool TextField::IsCharAccepted(const int &character) {
  static const std::vector<int> valid_chars = VALID_SPECIAL_CHARS;
  return (isalnum(character)) ||
         std::find(valid_chars.begin(), valid_chars.end(), character) !=
             valid_chars.end();
}

TextField::TextField(const std::optional<EventResponder *> &parent,
                     const std::string &default_text,
                     const std::optional<TextFieldDelegate *> &delegate)
    : AbstractView(parent, default_text), delegate_(delegate) {}

void TextField::SetInnerText(const std::string &inner_text) {
  auto old_text = GetUserEnteredText();
  is_showing_placeholder_ = inner_text.empty();
  AbstractView::SetInnerText(inner_text);
  if (delegate_.has_value()) {
    (*delegate_)->TextChanged(*this, old_text);
  }
}

void TextField::HasBeenUnselected() {
  AbstractView::HasBeenUnselected();
  if (delegate_.has_value()) {
    (*delegate_)->TextEditingFinished(*this);
  }
}

bool TextField::IsEmpty() const {
  if (!is_showing_placeholder_ && AbstractView::GetInnerText().size() == 0) {
    is_showing_placeholder_ = true;
  }
  return is_showing_placeholder_;
}

const std::string &TextField::GetPlaceholder() const { return placeholder_; }

std::string TextField::GetUserEnteredText() const {
  if (IsEmpty()) {
    return "";
  } else {
    return GetDisplayMode() == PASSWORD ? AbstractView::GetInnerText()
                                        : GetInnerText();
  }
}

const std::string &TextField::GetInnerText() const {
  if (IsEmpty()) {
    return GetPlaceholder();
  } else {
    switch (GetDisplayMode()) {
    case NORMAL:
      return AbstractView::GetInnerText();
    case PASSWORD:
      temp_password_hidden_chars_buffer = std::string(AbstractView::GetInnerText().size(), '*');
      return temp_password_hidden_chars_buffer;
    }
  }
}

void TextField::SetPlaceholder(const std::string &placeholder) {
  placeholder_ = placeholder;
}

TextField::TextFieldDisplayMode TextField::GetDisplayMode() const {
  return display_mode_;
}

void TextField::SetDisplayMode(TextField::TextFieldDisplayMode display_mode) {
  display_mode_ = display_mode;
}
