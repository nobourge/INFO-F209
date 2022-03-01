//
// Created by Anton Romanova on 21/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_MENU_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_MENU_VIEW_CONTROLLER_H_

#include <memory>
#include "abstract_view_controller.h"
#include "../views/menu_views/abstract_menu_view.h"

class AbstractMenuViewController : public AbstractViewController, public MenuViewDelegate {
 public:
  explicit AbstractMenuViewController(const std::shared_ptr<AbstractMenuView> &);

  std::optional<std::shared_ptr<AbstractViewController>> Tick() override;
  void RespondToKeyboardEvent(const int &character) override;
  void PresentViewController(std::optional<std::shared_ptr<AbstractViewController>> next_view_controller) override;

 protected:
  [[nodiscard]] const std::shared_ptr<AbstractMenuView> &GetMenuView() const;

  virtual void MenuViewWillDisappear() {};

  virtual void MenuViewWillAppear() {}

 private:
  // double optional. The first optional represents if the next_view_controller has been set.
  // The second represents whether the next_view_controller is actually a view controller or
  // the program has to last_sqlite3_exit_code_
  std::optional<std::optional<std::shared_ptr<AbstractViewController>>> next_view_controller_ = {};

  std::shared_ptr<AbstractMenuView> menu_view_;
};


#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_MENU_VIEW_CONTROLLER_H_
