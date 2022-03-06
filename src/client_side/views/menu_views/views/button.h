//
// Created by Anton Romanova on 18/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_BUTTON_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_BUTTON_H_

#include <string>
#include <optional>
#include <functional>

#include "abstract_view.h"


class Button : public AbstractView {
 public:

  Button(const std::optional<EventResponder *> &parent,
         const std::string &title,
         const std::function<void()> &click_handler = {});


//  void SetDelegate(const std::optional<ButtonDelegate *> &delegate);

 protected:
  void HasBeenSelected() override;
  bool RespondToEvent(const int &character) override;
  virtual void HandleClick();

 private:
  std::function<void()> click_handler_;
//  std::optional<ButtonDelegate *> delegate_;
};

#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEWS_BUTTON_H_
