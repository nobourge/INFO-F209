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

  TextField(const std::optional<EventResponder *> &parent,
            const std::string &default_text,
            const std::optional<TextFieldDelegate *> &delegate);

  static bool IsCharAccepted(const int &character);

 protected:
  void SetInnerText(const std::string &inner_text) override;
  bool RespondToEvent(const int &character) override;
  void HasBeenUnselected() override;

 private:
  std::optional<TextFieldDelegate *> delegate_;
};

struct TextFieldDelegate {
  virtual void TextChanged(const std::string &new_text) = 0;
  virtual void TextEditingFinished() = 0;
};

#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_TEXT_FIELD_H_
