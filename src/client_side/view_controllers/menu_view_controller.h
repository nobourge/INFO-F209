//
// Created by Anton Romanova on 21/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_MENU_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_MENU_VIEW_CONTROLLER_H_

#include "abstract_view_controller.h"
#include "../views/menu_views/abstract_menu_view.h"

class MenuViewController : public AbstractViewController, public MenuViewDelegate {
 public:
  explicit MenuViewController(AbstractMenuView *);

  std::optional<std::shared_ptr<AbstractViewController>> Tick() override;

  void NextViewControllerSelected(std::optional<std::shared_ptr<AbstractViewController>> next_view_controller) override;

  void ParseMessage(const int &character) override;

 protected:
  [[nodiscard]] const MenuViewController &GetMenuView() const;

 private:
  // double optional. The first optional represents if the next_view_controller has been set.
  // The second represents whether the next_view_controller is actually a view controller or
  // the program has to exit
  std::optional<std::optional<std::shared_ptr<AbstractViewController>>> next_view_controller_ = {};

  AbstractMenuView *home_menu_view_;
};


#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_MENU_VIEW_CONTROLLER_H_
