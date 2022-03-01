//
// Created by Anton Romanova on 23/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_MENU_BUTTON_ITEM_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_MENU_BUTTON_ITEM_H_

#include "../../../view_controllers/abstract_view_controller.h"
#include "button.h"

struct MenuButtonItemDelegate;

class MenuButtonItem : public Button {
public:
  MenuButtonItem(const std::optional<EventResponder *> &parent,
                 const std::string &title,
                 const std::optional<std::shared_ptr<AbstractViewController>>
                     &controller_to_present_on_click,
                 const std::optional<MenuButtonItemDelegate *> &delegate = {});

  void SetDelegate(const std::optional<MenuButtonItemDelegate *> &delegate);

private:
  std::function<void()> CreateClickEventDispatcherFunction();
  std::optional<std::shared_ptr<AbstractViewController>>
      controller_to_present_on_click_;
  std::optional<MenuButtonItemDelegate *> delegate_ = {};
};

struct MenuButtonItemDelegate {
  virtual void PresentController(
      const std::optional<std::shared_ptr<AbstractViewController>> &destination, MenuButtonItem &sender) = 0;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_MENU_BUTTON_ITEM_H_
