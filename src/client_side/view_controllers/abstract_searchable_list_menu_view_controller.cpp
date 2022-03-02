//
// Created by Anton Romanova on 02/03/2022.
//

#include "abstract_searchable_list_menu_view_controller.h"

bool AbstractSearchableListMenuViewController::ShouldDisplayViewAtIndex(
    unsigned int i) const {
  bool ret;
  std::string filter = filter_field_->GetUserEnteredText();
  if (!filter.empty()) {
    auto inner_text = GetInnerTextOfViewAtIndex(i);
    ret = SanitizeString(inner_text).find(SanitizeString(filter)) !=
          std::string::npos;
  } else {
    ret = true;
  }
  return ret;
}

AbstractSearchableListMenuViewController::
    AbstractSearchableListMenuViewController(
    const std::shared_ptr<AbstractMenuView> &view)
    : AbstractMenuViewController(view) {
  filter_field_ = std::make_shared<TextField>(GetMenuView().get(), "", this);
  filter_field_->SetPlaceholder("Filter:");
}

void AbstractSearchableListMenuViewController::ReloadSubviews() {
  std::vector<std::shared_ptr<AbstractView>> subviews = {};

  {
    auto header_view = GetHeaderView();
    if (header_view.has_value()) {
      subviews.push_back(*header_view);
    }
  }

  if (DisplayList()) {
    for (int i = 0; i < GetNumViewsToSearch() &&
                    subviews.size() <= max_num_items_to_display;
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

    subviews.push_back(filter_field_);
  }

  subviews.push_back(std::make_shared<MenuButtonItem>(
      GetMenuView().get(), "Back",
      std::optional<std::shared_ptr<AbstractViewController>>(),
      GetMenuView().get()));

  GetMenuView()->UpdateSubviews(subviews);
}

std::string &
AbstractSearchableListMenuViewController::SanitizeString(std::string &str) {
  for (char &c : str) {
    c = tolower(c);
  }
  return str;
}

void AbstractSearchableListMenuViewController::TextChanged(TextField &sender,
                                                 const std::string &old_text) {
  if (&sender == filter_field_.get()) {
    ReloadSubviews();
  }
}
void AbstractSearchableListMenuViewController::TextEditingFinished(TextField &sender) {}
std::string AbstractSearchableListMenuViewController::GetInnerTextOfViewAtIndex(
    unsigned int i) const {
  return GetViewAtIndex(i)->GetInnerText();
}

void AbstractSearchableListMenuViewController::MenuViewWillAppear() {
  AbstractMenuViewController::MenuViewWillAppear();
  ReloadSubviews();
}
