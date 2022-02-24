#include "abstract_menu_view.h"
#include "views/menu_button_item.h"

AbstractMenuView::AbstractMenuView(const char *name) : EventResponder({}), name(name), subviews_() {
  BecomeEventResponder();
}

const char *AbstractMenuView::GetName() const {
  return name;
}

int AbstractMenuView::GetVerticalPadding() const {
  return (LINES + 1 - GetSubviews().size() - (GetSubviews().size() - 1) * vertical_gutter_size_) / 2;
}

const std::vector<std::shared_ptr<AbstractView>> &AbstractMenuView::GetSubviews() const {
  return subviews_;
}

std::vector<std::shared_ptr<AbstractView>> &AbstractMenuView::GetSubviews() {
  return subviews_;
}

int AbstractMenuView::GetVerticalGutterSize() const {
  return vertical_gutter_size_;
}

void AbstractMenuView::Draw(WINDOW *window) const {
  initscr();
  wrefresh(window);
  wattr_on(window, MENU_NAME_EFFECT, nullptr);
  int center_y = COLS / 2;
  mvwprintw(window, 0, center_y - (strlen(GetName()) / 2), GetName());
  wattr_off(window, MENU_NAME_EFFECT, nullptr);

  for (int view_idx = 0; view_idx < GetSubviews().size(); ++view_idx) {
    const auto &view = GetSubviews().at(view_idx);

    wattr_on(window, view->GetNcursesEffectForCurrentState(), nullptr);

    mvwprintw(window,
              GetVerticalPadding()
                  + view_idx * (GetVerticalGutterSize() + 1), // + 1 for title -1 for extra gutter cancels out
              center_y - (view->GetInnerText().size() / 2),
              view->GetInnerText().c_str());
    wattr_off(window, view->GetNcursesEffectForCurrentState(), nullptr);
  }
}

void AbstractMenuView::MoveCursorDown() {
  MoveCursor(false);
}

void AbstractMenuView::MoveCursorUp() {
  MoveCursor(true);
}

void AbstractMenuView::MoveCursor(bool up) {
  auto current_view = GetIteratorOfHoveredSubview();
  (*current_view)->SetState(AbstractView::NORMAL);
  typedef std::vector<std::shared_ptr<AbstractView>>::iterator SubviewsIterator;

  std::function<SubviewsIterator(SubviewsIterator)> next_elem = [&](SubviewsIterator iter) {
    auto current_view_copy = iter;
    if (up) {
      if (iter == GetSubviews().begin()) {
        return --GetSubviews().end();
      } else {
        return --current_view_copy;
      }
    } else {
      if (iter == --GetSubviews().end()) {
        return GetSubviews().begin();
      } else {
        return ++current_view_copy;
      }
    }
  };

  // size + 1 because if we go through all the subviews and none are possible event responders,
  // we should fall back to the original view
  auto next_view = current_view;

  for (int i = 0; i < GetSubviews().size(); i++) {
    next_view = next_elem(next_view);
    if ((*next_view)->CanBecomeEventResponder()) {
      break;
    }
  }

  (*next_view)->SetState(AbstractView::HOVER);
}

std::vector<std::shared_ptr<AbstractView>>::iterator AbstractMenuView::GetIteratorOfHoveredSubview() {
  auto current_selected_idx =
      std::find_if(GetSubviews().begin(), GetSubviews().end(), [](const std::shared_ptr<AbstractView> &btn) {
        return btn->GetState() == AbstractView::HOVER;
      });

  // if none are selected
  if (current_selected_idx == GetSubviews().end()) {
    // TODO: This shouldn't happen. Should be logged
    current_selected_idx = GetSubviews().begin();
    // find the first "selectable" view
    for (int i = 0; i < GetSubviews().size(); i++) {
      if (!(*current_selected_idx)->CanBecomeEventResponder()) {
        current_selected_idx++;
      }
    }

    if (!(*current_selected_idx)->CanBecomeEventResponder()) {
      throw std::logic_error("At least one view should be selectable");
    }

    (*current_selected_idx)->SetState(AbstractView::HOVER);

  }
  return current_selected_idx;
}

void AbstractMenuView::SetFirstButtonStateToHoverIfNoneAreHoveredUpon() {
  GetIteratorOfHoveredSubview(); // this allows to hover over a button if none are in hover state
}

void AbstractMenuView::Click() {
  (*GetIteratorOfHoveredSubview())->SetState(AbstractView::SELECTED);
}

void AbstractMenuView::UpdateSubviews(const std::vector<std::shared_ptr<AbstractView>> &views = {}) {
  // set subviews_ to keys of buttons_handler_map
  subviews_ = views;
  SetFirstButtonStateToHoverIfNoneAreHoveredUpon();
}

void AbstractMenuView::PresentController(const std::optional<std::shared_ptr<AbstractViewController>> &next_view_controller) {
  // find index of clicked button
  if (delegate_) {
    delegate_->PresentViewController(next_view_controller);
  }
}

void AbstractMenuView::SetDelegate(MenuViewDelegate *delegate) {
  delegate_ = delegate;
}

bool AbstractMenuView::RespondToEvent(const int &character) {
  switch (character) {
    case KEY_UP:MoveCursorUp();
      return true;
    case KEY_DOWN:MoveCursorDown();
      return true;
    case '\n':Click();
      return true;
    default:return false;
  }
}

std::unique_ptr<std::vector<std::shared_ptr<EventResponder>>> AbstractMenuView::GetChildren() {
  auto output = std::make_unique<std::vector<std::shared_ptr<EventResponder>>>();
  for (auto &subview : subviews_) {
    output->push_back(subview);
  }
  return output;
}

void AbstractMenuView::AddSubview(const std::shared_ptr<AbstractView> &view) {
  subviews_.push_back(view);
  SetFirstButtonStateToHoverIfNoneAreHoveredUpon();
}
