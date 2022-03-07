//
// Created by Anton Romanova on 02/03/2022.
//

#include "view_controller_menu_abstract_list.h"
#include "../views/menu_views/views/label.h"

AbstractListMenuViewController::AbstractListMenuViewController(
    const std::shared_ptr<AbstractMenuView> &view)
    : AbstractMenuViewController(view) {}

void AbstractListMenuViewController::ReloadSubviews() {
  std::vector<std::shared_ptr<AbstractView>> subviews = {};

  for (auto &view : GetHeaderViews()) {
    subviews.push_back(view);
  }

  if (ShouldDisplayList()) {
    for (int i = 0;
         i < GetNumItemsInList() && subviews.size() <= max_num_items_to_display;
         i++) {
      if (ShouldDisplayViewAtIndex(i)) {
        subviews.push_back(GetViewAtIndex(i));
      }
    }

    // if there are more items to display, replace the last view with a "..."
    if (subviews.size() > max_num_items_to_display) {
      subviews.at(subviews.size() - 1) =
          std::make_shared<Label>(GetMenuView().get(), "...");
    }
  }

  for (auto &view : GetBottomViews()) {
    subviews.push_back(view);
  }

  GetMenuView()->UpdateSubviews(subviews);
}

bool AbstractListMenuViewController::ShouldDisplayViewAtIndex(
    unsigned int i) const {
  return true;
}

std::vector<std::shared_ptr<AbstractView>>
AbstractListMenuViewController::GetHeaderViews() const {
  return {};
}

std::vector<std::shared_ptr<AbstractView>>
AbstractListMenuViewController::GetBottomViews() const {
  return {};
}
void AbstractListMenuViewController::MenuViewWillAppear() {
  AbstractMenuViewController::MenuViewWillAppear();
  ReloadSubviews();
}
