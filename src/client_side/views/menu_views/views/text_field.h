//
// Created by Anton Romanova on 23/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_TEXT_FIELD_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_TEXT_FIELD_H_

#include "abstract_view.h"
#include <string>

struct TextFieldDelegate;

class TextField : public AbstractView {
public:

  enum TextFieldDisplayMode {
    NORMAL, PASSWORD
  };

  TextField(const std::optional<EventResponder *> &parent,
            const std::string &default_text,
            const std::optional<TextFieldDelegate *> &delegate);

  static bool IsCharAccepted(const int &character);

  [[nodiscard]] const std::string &GetInnerText() const override;

  void SetInnerText(const std::string &inner_text) override;

  [[nodiscard]] bool IsEmpty() const;
  [[nodiscard]] const std::string &GetPlaceholder() const;
  void SetPlaceholder(const std::string &placeholder);
  [[nodiscard]] std::string GetUserEnteredText() const;
  TextFieldDisplayMode GetDisplayMode() const;
  void SetDisplayMode(TextFieldDisplayMode display_mode);


protected:
  bool RespondToEvent(const int &character) override;
  void HasBeenUnselected() override;

private:
  mutable bool is_showing_placeholder_ = false;
  mutable std::string temp_password_hidden_chars_buffer;

  TextFieldDisplayMode display_mode_ = NORMAL;
  std::string placeholder_;
  std::optional<TextFieldDelegate *> delegate_;
};

struct TextFieldDelegate {
  virtual void TextChanged(TextField &sender, const std::string &old_text) = 0;
  virtual void TextEditingFinished(TextField &sender) = 0;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_TEXT_FIELD_H_
