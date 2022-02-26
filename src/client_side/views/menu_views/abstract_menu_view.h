#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEWS_ABSTRACT_MENU_VIEW_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEWS_ABSTRACT_MENU_VIEW_H_

#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
#include "views/button.h"
#include "../../view_controllers/abstract_view_controller.h"
#include "../../../common/constants.h"
#include "views/menu_button_item.h"

struct MenuViewDelegate;

class AbstractMenuView: public MenuButtonItemDelegate, public EventResponder {
public:
  explicit AbstractMenuView(const char *name);

  [[nodiscard]] const char *GetName() const;
  [[nodiscard]] const std::vector<std::shared_ptr<AbstractView>> & GetSubviews() const;
  [[nodiscard]] std::vector<std::shared_ptr<AbstractView>> & GetSubviews();

  virtual void Draw(WINDOW *window) const;

  void SetDelegate(MenuViewDelegate *delegate);

  void AddSubview(const std::shared_ptr<AbstractView> &view);

  void UpdateSubviews(const std::vector<std::shared_ptr<AbstractView>> &views);
  void PresentController(const std::optional<std::shared_ptr<AbstractViewController>> &next_view_controller) override;

 protected:
  std::unique_ptr<std::vector<std::shared_ptr<EventResponder>>> GetChildren() override;
  bool RespondToEvent(const int &character) override;

 protected:
  void MoveCursorUp();
  void MoveCursorDown();
  void Click();

  [[nodiscard]] int GetVerticalPadding() const;
  std::vector<std::shared_ptr<AbstractView>>::iterator GetIteratorOfHoveredSubview();
  [[nodiscard]] int GetVerticalGutterSize() const;


 private:

  void MoveCursor(bool up);

  void SetFirstButtonStateToHoverIfNoneAreHoveredUpon();

  const char* name;
  std::vector<std::shared_ptr<AbstractView>> subviews_;
  int vertical_gutter_size_ = BUTTONS_VERTICAL_GUTTER_SIZE;
  MenuViewDelegate *delegate_ = nullptr;
};

struct MenuViewDelegate {
  virtual void PresentViewController(std::optional<std::shared_ptr<AbstractViewController>> next_view_controller) = 0;
};


#endif //QUORIDOR_SRC_CLIENT_SIDE_VIEWS_ABSTRACT_MENU_VIEW_H_