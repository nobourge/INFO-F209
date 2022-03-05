#include <iostream>
#include <cstring>
#include <vector>
#include "abstract_menu_view.h"
#include "views/button.h"



class HomeMenuView : public AbstractMenuView {
 public:
  static constexpr char menu_name_[] = "Home";
  HomeMenuView();
  bool ShouldDisplayDefaultBackButton() const override;
};