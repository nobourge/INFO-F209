//
// Created by guest on 01/03/2022.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_VIEW_CONTROLLER_H_
#define QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_VIEW_CONTROLLER_H_

#include "../../common/models/Game.h"
#include "../models/api_wrapper.h"
#include "../views/menu_views/views/label.h"
#include "../views/menu_views/views/text_field.h"
#include "abstract_authed_menu_view_controller.h"

class GameViewController : public AbstractAuthedMenuViewController,
                           public TextFieldDelegate {
public:
static constexpr const long long millis_timout_for_new_fetch = 1000;

  GameViewController(object_id_t game_id);

  void TextChanged(TextField &sender, const std::string &old_text) override;

  void TextEditingFinished(TextField &sender) override;

  void FetchBoardReprAndUpdateSubviews();

  bool ShouldFetchBoard() {
    return last_fetched_board_ + millis_timout_for_new_fetch < GET_TIME_IN_MILLIS;
  }

  void UpdateSubviews();

  void Draw(WINDOW *window) override;

protected:
  void MenuViewWillAppear() override;

private:
  object_id_t game_id_;
  uint64_t last_fetched_board_{};
  std::vector<std::string> board_repr_lines_;
  std::shared_ptr<TextField> move_field_;
  std::optional<std::string> error_message_;
  std::optional<std::string> non_disruptive_error_message_;
};
#endif // QUORIDOR_SRC_CLIENT_SIDE_VIEW_CONTROLLERS_GAME_VIEW_CONTROLLER_H_
