#include <iostream>
#include <stack>
#include "view_controllers/abstract_view_controller.h"
#include "view_controllers/home_menu_view_controller.h"

int main() {
  std::stack<std::shared_ptr<AbstractViewController>> view_controllers{};
  view_controllers.push(std::make_shared<HomeMenuViewController>());
  while (!view_controllers.empty()) {
    auto new_view_controller = view_controllers.top()->Tick();

    if (new_view_controller.has_value())
      view_controllers.push(*new_view_controller);
    else
      view_controllers.pop();

  }
  return 0;
}
