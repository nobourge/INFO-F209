//
// Created by Anton Romanova on 22/02/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_FIRST_RESPONDER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_FIRST_RESPONDER_H_

#include <memory>
#include <optional>
#include <vector>

/// An EventResponder allows a basic chain of responsibility based event handling management.
/// An example of this being useful might be a selected view that handles arrow keys its own way (like a game view)
/// and this view is inside a menu that also uses arrow keys to select the right button.

class EventResponder {
 public:
  explicit EventResponder(const std::optional<EventResponder *> &next);
  [[nodiscard]] bool IsEventResponder() const;
  bool RespondToKeyboardEventIfFirstResponder(const int &character);
  bool PropagateEvent(const int &character);
  virtual bool CanBecomeEventResponder();

 protected:
  virtual std::unique_ptr<std::vector<std::shared_ptr<EventResponder>>> GetChildren() = 0;
  void BecomeEventResponder();
  void ResignEventResponderStatus();
  virtual bool RespondToEvent(const int &character) = 0;


 private:
  std::optional<EventResponder *> next_;
  bool is_first_responder_ = false;
};

#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEWS_MENU_VIEWS_VIEWS_FIRST_RESPONDER_H_
