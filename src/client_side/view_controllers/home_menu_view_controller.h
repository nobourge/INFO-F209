#include "../views/menu_views/home_menu_view.h"
#include "ncurses.h"
#include <string>

#ifndef QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_

class HomeMenuViewController : public AbstractViewController, public MenuViewDelegate {
 public:
  std::optional<std::shared_ptr<AbstractViewController>> Tick() override;
  HomeMenuViewController();

  void NextViewControllerSelected(std::optional<std::shared_ptr<AbstractViewController>> next_view_controller) override;

  void ParseMessage(const int &character) override;

 protected:
  [[nodiscard]] const HomeMenuView &GetHomeMenuView() const;

 private:
  // double optional. The first optional represents if the next_view_controller has been set.
  // The second represents whether the next_view_controller is actually a view controller or
  // the program has to exit
  std::optional<std::optional<std::shared_ptr<AbstractViewController>>> next_view_controller_ = {};

  HomeMenuView home_menu_view_;
};

//class ControllerLoginClient : public AbstractViewController {
// public:
//  std::shared_ptr<AbstractViewController> Tick();
//};

#endif //QUORIDOR_SRC_CLIENT_SIDE_CONTROLLER_H_
