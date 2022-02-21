#include "abstract_menu_view.h"
#include "../../../common/constants.h"

AbstractMenuView::AbstractMenuView(const char *name) : name(name), submenus_() {}

const char *AbstractMenuView::GetName() const {
  return name;
}

int AbstractMenuView::GetVerticalPadding() const {
  return (LINES + 1 - GetButtons().size() - (GetButtons().size() - 1) * vertical_gutter_size_) / 2;
}

const std::vector<Button> &AbstractMenuView::GetButtons() const {
  return buttons_;
}

std::vector<Button> &AbstractMenuView::GetButtons() {
  return buttons_;
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

  for (int button_idx = 0; button_idx < GetButtons().size(); ++button_idx) {
    const auto &button = GetButtons().at(button_idx);

    if (button.GetState() == Button::HOVER) {
      wattr_on(window, MENU_SUBMENU_BUTTONS_EFFECT, nullptr);
    }

    mvwprintw(window,
              GetVerticalPadding()
                  + button_idx * (GetVerticalGutterSize() + 1), // + 1 for title -1 for extra gutter cancels out
              center_y - (button.GetTitle().size() / 2),
              button.GetTitle().c_str());
    wattr_off(window, MENU_SUBMENU_BUTTONS_EFFECT, nullptr);
  }
}

void AbstractMenuView::MoveCursorDown() {
  auto current_btn = GetIteratorOfHoveredButton();
  current_btn->SetState(Button::NORMAL);
  auto prev_btn = (current_btn == GetButtons().begin()) ? --GetButtons().end() : --current_btn;
  prev_btn->SetState(Button::HOVER);
}

void AbstractMenuView::MoveCursorUp() {
  auto current_btn = GetIteratorOfHoveredButton();
  current_btn->SetState(Button::NORMAL);
  auto next_btn = (current_btn == (--GetButtons().end())) ? GetButtons().begin() : ++current_btn;
  next_btn->SetState(Button::HOVER);
}

std::vector<Button>::iterator AbstractMenuView::GetIteratorOfHoveredButton() {
  auto current_selected_idx = std::find_if(GetButtons().begin(), GetButtons().end(), [](const Button &btn) {
    return btn.GetState() == Button::HOVER;
  });
  if (current_selected_idx == GetButtons().end()) {
    // TODO: This shouldn't happen. Should be logged
    current_selected_idx = GetButtons().begin();
    current_selected_idx->SetState(Button::HOVER);
  }
  return current_selected_idx;
}

void AbstractMenuView::SetFirstButtonStateToHover() {
  for (auto &btn : buttons_) {
    btn.SetState(Button::NORMAL);
  }
  if (!buttons_.empty()) {
    buttons_[0].SetState(Button::HOVER);
  }
}

void AbstractMenuView::Click() {
  GetIteratorOfHoveredButton()->Click();
}

void AbstractMenuView::UpdateButtons(const std::optional<ButtonHandlersDict> &buttons_handlers = {}) {
  if (buttons_handlers->empty()) {
    submenus_ = GetSubmenus();
  } else {
    submenus_ = buttons_handlers.value();
  }

  // set buttons_ to keys of buttons_handler_map
  buttons_.clear();
  buttons_.reserve(submenus_.size());
  for (auto &submenu : submenus_) {
    buttons_.emplace_back(std::get<0>(submenu));
    buttons_[buttons_.size() - 1].SetDelegate(this);
  }

  SetFirstButtonStateToHover();
}

void AbstractMenuView::ButtonClicked(const Button &sender) {
  // find index of clicked button

  const auto clicked_btn_submenu = std::find_if(submenus_.begin(), submenus_.end(), [&sender](const auto &pair) {
    return std::get<0>(pair) == sender.GetTitle();
  });

  if (delegate_) {
    delegate_->NextViewControllerSelected(std::get<1>(*clicked_btn_submenu));
  }
}

void AbstractMenuView::SetDelegate(MenuViewDelegate *delegate) {
  delegate_ = delegate;
}

