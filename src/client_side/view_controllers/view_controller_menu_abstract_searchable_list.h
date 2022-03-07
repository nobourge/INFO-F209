//
// Created by Anton Romanova on 02/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_ABSTRACT_SEARCHABLE_LIST_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_ABSTRACT_SEARCHABLE_LIST_H_

#include "../views/menu_views/views/label.h"
#include "../views/menu_views/views/text_field.h"
#include "view_controller_menu_abstract_list.h"

class AbstractSearchableListMenuViewController
    : public AbstractListMenuViewController,
      public TextFieldDelegate {
public:
  explicit AbstractSearchableListMenuViewController(
      const std::shared_ptr<AbstractMenuView> &view);

  [[nodiscard]] std::vector<std::shared_ptr<AbstractView>> GetBottomViews() const override;

  void TextChanged(TextField &sender, const std::string &old_text) override;

  void TextEditingFinished(TextField &sender) override;

  [[nodiscard]] bool ShouldDisplayViewAtIndex(unsigned int i) const override;

protected:
  void MenuViewWillAppear() override;

private:
  [[nodiscard]] std::string
  GetInnerTextOfViewAtIndex(unsigned i) const;

  static std::string &SanitizeString(std::string &str);
  std::shared_ptr<TextField> filter_field_{};
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_ABSTRACT_SEARCHABLE_LIST_H_
