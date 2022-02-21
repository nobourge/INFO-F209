#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
#include "../view_elements/button.h"
#include "../../view_controllers/abstract_view_controller.h"
#include "../../../common/constants.h"

struct MenuViewDelegate;
typedef std::vector<std::tuple<std::string, std::optional<std::shared_ptr<AbstractViewController>>>> ButtonHandlersDict;

class AbstractMenuView: public ButtonDelegate{
public:
  AbstractMenuView(const char *name);

  [[nodiscard]] const char *GetName() const;
  [[nodiscard]] const std::vector<Button> &GetButtons() const;
  [[nodiscard]] std::vector<Button> &GetButtons();

  virtual void Draw(WINDOW *window) const;

  void SetDelegate(MenuViewDelegate *delegate);

  void MoveCursorUp();
  void MoveCursorDown();
  void Click();

  void UpdateButtons(const std::optional<ButtonHandlersDict> &buttons_handlers);
  void ButtonClicked(const Button &sender) override;


  virtual const ButtonHandlersDict &GetSubmenus() = 0;

 protected:
  [[nodiscard]] int GetVerticalPadding() const;
  std::vector<Button *>::iterator GetIteratorOfHoveredButton();
  [[nodiscard]] int GetVerticalGutterSize() const;


 private:
  void SetFirstButtonStateToHover();

  const char* name;
  std::vector<Button> buttons_;
  ButtonHandlersDict submenus_;
  int vertical_gutter_size_ = BUTTONS_VERTICAL_GUTTER_SIZE;
  MenuViewDelegate *delegate_ = nullptr;
};

struct MenuViewDelegate {
  virtual void NextViewControllerSelected(std::optional<std::shared_ptr<AbstractViewController>> next_view_controller) = 0;
};