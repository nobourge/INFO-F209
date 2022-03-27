#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include <QMainWindow>
#include "../models/user_client.h"
#include "menu_board_view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenuView; }
QT_END_NAMESPACE

class MainMenuView : public QMainWindow
{
 Q_OBJECT

 public:
  MainMenuView(QWidget *parent = nullptr);
  ~MainMenuView();

 private slots:

  void on_pushButton_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_9_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_11_clicked();

  void on_pushButton_10_clicked();

  void on_pushButton_12_clicked();

  void on_pushButton_13_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_14_clicked();

  void on_pushButton_16_clicked();

  void on_pushButton_15_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_18_clicked();

  void on_pushButton_17_clicked();

  void on_pushButton_19_clicked();
  void on_pushButton_20_clicked();
  void on_pushButton_21_clicked();
  void on_pushButton_22_clicked();
  void on_pushButton_23_clicked();
  void on_pushButton_24_clicked();
  void on_pushButton_3_clicked();
  void on_lineEdit_7_textChanged(const QString &arg1);

  void on_pushButton_25_clicked();
  void on_pushButton_27_clicked();

  void on_pushButton_53_clicked();



  void on_pushButton_26_clicked();

  void updateChatRoomMessagesListView();

private:
  Ui::MainMenuView *ui;
  std::vector<UserClient> friends_ = {};
  std::optional<UserClient> selected_friend_ = {};
  //std::string chattext="";
  std::string chattext;
  std::string game_chattext;
  //std::string Rankingtext="";
  std::string Rankingtext;
  MenuBoardView *menuView = new MenuBoardView();
};
#endif // MAINMENUVIEW_H
