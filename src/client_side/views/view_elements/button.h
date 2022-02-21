//
// Created by Anton Romanova on 18/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_BUTTON_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_BUTTON_H_

#include <string>
#include <optional>


class ButtonDelegate;

class Button {
 public:
  enum State {
    NORMAL, HOVER, SELECTED
  };

  Button(const std::string &title, const std::optional<ButtonDelegate *> &delegate = {});

  [[nodiscard]] const std::string &GetTitle() const;
  void SetTitle(const std::string &title);

  [[nodiscard]] State GetState() const;
  void SetState(State state);
  void Click();

  void SetDelegate(const std::optional<ButtonDelegate *> &delegate);

 private:
  // TODO: Migrate to smart pointers!
  //       We might end up with a dangling pointer here if this
  //       button doesn't have the same lifecycle as its delegate;

  std::optional<ButtonDelegate *> delegate_;
  std::string title_;
  State state_ = NORMAL;
};


struct ButtonDelegate {
  virtual void ButtonClicked(const Button &sender) = 0;
};


#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEWS_BUTTON_H_
