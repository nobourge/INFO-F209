//
// Created by Anton Romanova on 21/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_MENU_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_MENU_VIEW_CONTROLLER_H_

#include "../views/menu_views/abstract_menu_view.h"
#include "abstract_view_controller.h"
#include <memory>

class AbstractMenuViewController : public AbstractViewController,
                                   public MenuViewDelegate {
public:
  explicit AbstractMenuViewController(
      const std::shared_ptr<AbstractMenuView> &);

  virtual std::optional<std::shared_ptr<AbstractViewController>>
  Tick() override;
  void RespondToKeyboardEvent(const int &character) override;
  void
  PresentViewController(std::optional<std::shared_ptr<AbstractViewController>>
                            next_view_controller) override;

  virtual void Draw(WINDOW *window);

protected:
  [[nodiscard]] const std::shared_ptr<AbstractMenuView> &GetMenuView() const;

  virtual void MenuViewWillDisappear() { is_on_screen_ = false; };

  virtual void MenuViewWillAppear() { is_on_screen_ = true; }
  std::optional<std::optional<std::shared_ptr<AbstractViewController>>>
      next_view_controller_ = {};

private:
  // double optional. The first optional represents if the next_view_controller
  // has been set. The second represents whether the next_view_controller is
  // actually a view controller or the program has to last_sqlite3_exit_code_

  std::shared_ptr<AbstractMenuView> menu_view_;
  bool is_on_screen_ = false;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_ABSTRACT_MENU_VIEW_CONTROLLER_H_
