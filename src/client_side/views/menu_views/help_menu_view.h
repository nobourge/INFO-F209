#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_HELP_MENU_VIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_HELP_MENU_VIEW_H_

#include <iostream>
#include <cstring>
#include <vector>
#include "abstract_menu_view.h"
#include "views/text_field.h"

class HelpMenuView : public AbstractMenuView, public TextFieldDelegate {
 public:
  void TextChanged(TextField &sender, const std::string &old_text) override;
  void TextEditingFinished(TextField &sender) override;
  HelpMenuView();
 private:
  constexpr static const char menu_name_[] = "Help Menu";
};

#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEWS_HELP_MENU_VIEW_H_