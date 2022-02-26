//
// Created by Anton Romanova on 22/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_LABEL_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_LABEL_H_

#include "abstract_view.h"

class Label : public AbstractView {
public:
  enum LabelDisplayMode {
    NORMAL, BOLD, UNDERLINE, REVERSED };

  Label(const std::optional<EventResponder *> &parent, const std::string &inner_text);
  bool CanBecomeEventResponder() override;

  [[nodiscard]] unsigned int GetNcursesEffectForCurrentState() const override;

  LabelDisplayMode GetDisplayMode() const;
  void SetDisplayMode(LabelDisplayMode display_mode);

protected:
  bool RespondToEvent(const int &character) override;
private:
  LabelDisplayMode display_mode_ = NORMAL;
};

#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_LABEL_H_
