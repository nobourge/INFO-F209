//
// Created by Anton Romanova on 02/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_SEARCHABLE_LIST_MENU_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_SEARCHABLE_LIST_MENU_VIEW_CONTROLLER_H_

#include "../views/menu_views/views/label.h"
#include "../views/menu_views/views/text_field.h"
#include "abstract_menu_view_controller.h"

class AbstractSearchableListMenuViewController
    : public AbstractMenuViewController,
      public TextFieldDelegate {

  constexpr const static unsigned max_num_items_to_display = 3;

public:
  AbstractSearchableListMenuViewController(
      const std::shared_ptr<AbstractMenuView> &view);

  [[nodiscard]] virtual unsigned GetNumViewsToSearch() const = 0;
  [[nodiscard]] virtual std::shared_ptr<AbstractView>
  GetViewAtIndex(unsigned i) const = 0;
  virtual std::optional<std::shared_ptr<AbstractView>> GetHeaderView() const  { return {}; } //TODO nodiscard?
  virtual bool DisplayList() const { return true; } //TODO nodiscard?

  [[nodiscard]] bool ShouldDisplayViewAtIndex(unsigned i) const;

  void TextChanged(TextField &sender, const std::string &old_text) override;
  void TextEditingFinished(TextField &sender) override;

protected:
  void MenuViewWillAppear() override;

protected:
  virtual void ReloadSubviews();

private:
  [[nodiscard]] std::string
  GetInnerTextOfViewAtIndex(unsigned i) const;

  static std::string &SanitizeString(std::string &str);
  std::shared_ptr<TextField> filter_field_{};
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_SEARCHABLE_LIST_MENU_VIEW_CONTROLLER_H_
