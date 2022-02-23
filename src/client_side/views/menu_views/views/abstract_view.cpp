//
// Created by Anton Romanova on 22/02/2022.
//

#include "abstract_view.h"

const std::string &AbstractView::GetInnerText() const {
  return inner_text_;
}

void AbstractView::SetInnerText(const std::string &inner_text) {
  inner_text_ = inner_text;
}

AbstractView::State AbstractView::GetState() const {
  return state_;
}

void AbstractView::SetState(AbstractView::State new_state) {
  auto old_state = state_;
  state_ = new_state;
  if (old_state != new_state) {
    if (new_state == SELECTED) {
      HasBeenSelected();
    }
    if (old_state == SELECTED) {
      HasBeenUnselected();
    }
  }
}

unsigned int AbstractView::GetNcursesEffectForCurrentState() const {
  switch (GetState()) {
    case NORMAL   : return A_NORMAL;
    case HOVER    : return VIEW_HOVER_EFFECT;
    case SELECTED : return VIEW_SELECTED_EFFECT;
  }
}

void AbstractView::HasBeenSelected() {
  BecomeEventResponder();
}

void AbstractView::HasBeenUnselected() {
  ResignEventResponderStatus();
}

AbstractView::AbstractView(const std::optional<EventResponder *> &parent, const std::string &inner_text) :
    EventResponder(parent), inner_text_(inner_text), state_(State::NORMAL) {}

void AbstractView::UnselectIfPossible() {
  if (GetState() == SELECTED) {
    SetState(HOVER);
  }
}

std::unique_ptr<std::vector<std::shared_ptr<EventResponder>>> AbstractView::GetChildren() {
  return std::make_unique<std::vector<std::shared_ptr<EventResponder>>>();
}
