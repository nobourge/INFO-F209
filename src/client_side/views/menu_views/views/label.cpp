//
// Created by Anton Romanova on 22/02/2022.
//

#include "label.h"
bool Label::CanBecomeEventResponder() {
  return false;
}

bool Label::RespondToEvent(const int &character) {
  return false;
}

Label::Label(const std::optional<EventResponder *> &parent, const std::string &inner_text) : AbstractView(parent,

                                                                                                          inner_text) {}
unsigned int Label::GetNcursesEffectForCurrentState() const {
  switch (GetDisplayMode()) {
  case NORMAL:
    return AbstractView::GetNcursesEffectForCurrentState();
  case BOLD:
    return A_BOLD;
  case UNDERLINE:
    return A_UNDERLINE;
  case REVERSED:
    return A_REVERSE;
  }
}

Label::LabelDisplayMode Label::GetDisplayMode() const { return display_mode_; }


void Label::SetDisplayMode(Label::LabelDisplayMode display_mode) {
  display_mode_ = display_mode;
}
