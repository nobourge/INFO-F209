//
// Created by Anton Romanova on 02/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_ABSTRACT_LIST_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_ABSTRACT_LIST_H_

#include "view_controller_menu_abstract.h"

class AbstractListMenuViewController : public AbstractMenuViewController {
public:
  constexpr const static unsigned max_num_items_to_display = 3;

  [[nodiscard]] virtual unsigned GetMaxNumItemsToDisplay() const {
    return max_num_items_to_display;
  }

  explicit AbstractListMenuViewController(const std::shared_ptr<AbstractMenuView> &view);

  [[nodiscard]] virtual std::vector<std::shared_ptr<AbstractView>>
  GetHeaderViews() const;

  [[nodiscard]] virtual std::vector<std::shared_ptr<AbstractView>>
  GetBottomViews() const;

  [[nodiscard]] virtual bool ShouldDisplayViewAtIndex(unsigned i) const;

  [[nodiscard]] virtual unsigned GetNumItemsInList() const = 0;

  [[nodiscard]] virtual std::shared_ptr<AbstractView>
  GetViewAtIndex(unsigned i) const = 0;

  [[nodiscard]] virtual bool ShouldDisplayList() const { return true; }

protected:
  void MenuViewWillAppear() override;
  virtual void ReloadSubviews();
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_VIEW_CONTROLLER_MENU_ABSTRACT_LIST_H_
