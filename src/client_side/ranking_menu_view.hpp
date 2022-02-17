#include <iostream>
#include "view/MenuView.h"
#include <cstring>

using namespace std;

class RankingMenuView : public MenuView {
    string Ranking;
public:
    string getRanking() const ;
    void DisplayRanking();
};


