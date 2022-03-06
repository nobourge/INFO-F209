//
// Created by Anton Romanova on 23/02/2022.
//

#include "menu_button_item.h"

MenuButtonItem::MenuButtonItem(const std::optional<EventResponder *> &parent,
                               const std::string &title,
                               const std::optional<std::shared_ptr<AbstractViewController>> &controller_to_present_on_click,
                               const std::optional<MenuButtonItemDelegate *> &delegate)
    : Button(parent, title, CreateClickEventDispatcherFunction()),
      controller_to_present_on_click_(controller_to_present_on_click),
      delegate_(delegate) {}



std::function<void()> MenuButtonItem::CreateClickEventDispatcherFunction() {
  return [&]() {
    if (delegate_.has_value()) {
      (*delegate_)->PresentController(controller_to_present_on_click_, *this);
    }
  };
}
