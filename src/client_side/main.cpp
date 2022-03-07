#include <stack>
#include "view_controllers/view_controller_abstract.h"
#include "view_controllers/view_controller_home_menu.h"
#include "view_controllers/view_controller_welcome.h"

int main() {
  std::stack<std::shared_ptr<AbstractViewController>> view_controllers{};
  view_controllers.push(std::make_shared<StartViewController>());
  while (!view_controllers.empty()) {
    auto new_view_controller = view_controllers.top()->Tick();

    if (new_view_controller.has_value())
      view_controllers.push(*new_view_controller);
    else
      view_controllers.pop();

  }
  return 0;
}
