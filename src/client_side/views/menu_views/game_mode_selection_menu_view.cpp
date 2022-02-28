#include "game_mode_selection_menu_view.h"
#include "views/label.h"

GameModeSelectionMenuView::GameModeSelectionMenuView() : AbstractMenuView(menu_name_) {
    UpdateSubviews({
        std::make_shared<MenuButtonItem>(this,"Against the IA", std::optional<std::shared_ptr<AbstractViewController>>{}, this),
        std::make_shared<MenuButtonItem>(this,"Walls ?", std::optional<std::shared_ptr<AbstractViewController>>{}, this),
        std::make_shared<MenuButtonItem>(this, "Back", std::optional<std::shared_ptr<AbstractViewController>>{}, this)
    });
    // scores = model.LoadScores();
    // std::vector<std::shared_ptr<AbstractView>> v = {}
    // for (score : scores) {
    //     v.push_back(std::make_shared<Label>(this, score.text));
    // }
}