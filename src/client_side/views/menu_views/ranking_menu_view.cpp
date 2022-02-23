#include "ranking_menu_view.h"
#include "views/label.h"


RankingMenuView::RankingMenuView() : AbstractMenuView(menu_name_) {
    UpdateSubviews({
        std::make_shared<Label>(this,"Ismaël : 0"),
        std::make_shared<Label>(this,"Nabil : -6"),
        std::make_shared<MenuButtonItem>(this, "Quit", std::optional<std::shared_ptr<AbstractViewController>>{}, this)
    });
    // scores = model.LoadScores();
    // std::vector<std::shared_ptr<AbstractView>> v = {}
    // for (score : scores) {
    //     v.push_back(std::make_shared<Label>(this, score.text));
    // }
}