//
// Created by Anton Romanova on 02/03/2022.
//

#include "view_controller_menu_abstract_searchable_list.h"



AbstractSearchableListMenuViewController::
    AbstractSearchableListMenuViewController(
    const std::shared_ptr<AbstractMenuView> &view)
    : AbstractListMenuViewController(view) {
  filter_field_ = std::make_shared<TextField>(GetMenuView().get(), "", this);
  filter_field_->SetPlaceholder("Search: ");
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

std::vector<std::shared_ptr<AbstractView>>
AbstractSearchableListMenuViewController::GetBottomViews() const {
  auto bottom_views = AbstractListMenuViewController::GetBottomViews();
  bottom_views.push_back(filter_field_);
  return bottom_views;
}

void AbstractSearchableListMenuViewController::MenuViewWillAppear() {
  filter_field_->SetInnerText("");
  AbstractListMenuViewController::MenuViewWillAppear();
  ReloadSubviews();
}

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
