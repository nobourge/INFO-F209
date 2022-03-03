//
// Created by Anton Romanova on 02/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_SEARCHABLE_LIST_MENU_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_SEARCHABLE_LIST_MENU_VIEW_CONTROLLER_H_

#include "../views/menu_views/views/label.h"
#include "../views/menu_views/views/text_field.h"
#include "abstract_list_menu_view_controller.h"

class AbstractSearchableListMenuViewController
    : public AbstractListMenuViewController,
      public TextFieldDelegate {
public:
  AbstractSearchableListMenuViewController(
      const std::shared_ptr<AbstractMenuView> &view);

  [[nodiscard]] std::vector<std::shared_ptr<AbstractView>> GetBottomViews() const override;

  void TextChanged(TextField &sender, const std::string &old_text) override;

  void TextEditingFinished(TextField &sender) override;

  bool ShouldDisplayViewAtIndex(unsigned int i) const override;

protected:
  void MenuViewWillAppear() override;

private:
  [[nodiscard]] std::string
  GetInnerTextOfViewAtIndex(unsigned i) const;

  static std::string &SanitizeString(std::string &str);
  std::shared_ptr<TextField> filter_field_{};
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_SEARCHABLE_LIST_MENU_VIEW_CONTROLLER_H_
