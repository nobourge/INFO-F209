#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include "../models/user_client.h"
#include "menu_board_view.h"
#include "message_fetcher.h"
#include <QComboBox>
#include <QMainWindow>
#include <QtCore/qthread.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainMenuView;
}
QT_END_NAMESPACE

class MainMenuView : public QMainWindow {
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

  void on_pushButton_53_clicked();

  void on_pushButton_26_clicked();

  void on_lineEdit_SearchFriendUsername_textChanged(const QString &arg1);

  void on_pushButton_BackAddFriend_clicked();

  void on_pushButton_AddFriend_clicked();

  void on_pushButton_Chat_clicked();

  void on_pushButton_BackChooseFriend_clicked();

  void on_pushButton_Register_clicked();

  void on_pushButton_game_chat_send_clicked();

  void on_pushButton_game_quit_clicked();

  void on_pushButton_QuitWelcome_clicked();

  void on_pushButton_LoginWelcome_clicked();

  void on_pushButton_RegisterWelcome_clicked();

  void on_pushButton_PlayShortcutWelcome_clicked();

  void on_pushButton_GrayTheme_clicked();

  void on_pushButton_RedTheme_clicked();

  void on_pushButton_WhiteTheme_clicked();

  void on_pushButton_AddAddFriend_clicked();

  void on_pushButton_BackHelp_clicked();

  void on_pushButton_SendButtonChat_clicked();

  void on_pushButton_BackChat_clicked();

  void on_pushButton_BackRanking_clicked();

  void on_pushButton_EnterLogin_clicked();

  void on_pushButton_BackLogin_clicked();

  void on_pushButton_BackRegister_clicked();

  void on_pushButton_RankingMainMenu_clicked();

  void on_pushButton_BackMainMenu_clicked();

  void on_pushButton_HelpMainMenu_clicked();

  void on_pushButton_FriendListMainMenu_clicked();

  // void on_pushButton_PlayMainMenu_clicked();
  /// Update functions
  void updateChatRoomMessagesListView();
  void updateChatRoomMessagesListView(const string &room);

  void updateFriendsComboBoxView(QComboBox *combobox);
  void updateRankingView();
  void updateChatRoom();
  ////

  void on_pushButton_PlayMainMenu_clicked();

  void on_pushButton_BackToMenuFromJoin_clicked();

  void on_pushButton_ToInviteFriend_clicked();

  void on_pushButton_InviteToGame_clicked();

  void on_pushButton_BackToJoinMenu_clicked();

  void on_lineEditNameOfGame_cursorPositionChanged(int arg1, int arg2);

public slots:
  void UpdateMessageViews(const std::vector<Message> &messages,
                          const UserClient &other_user);

signals:
  void
  __StartFetchingMessages(const UserClient &other_user,
                          const std::function<bool()> should_continue_fetching);

private:
  void StartFetchingMessages();

  void StopFetchingMessages() { should_fetch_messages_ = false; }

  void InitMessageFetcherThread();

  Ui::MainMenuView *ui;
  std::vector<UserClient> friends_ = {};

  std::optional<UserClient> selected_friend_ = {};
  std::string chattext;
  bool should_fetch_messages_ = false;
  QThread message_fetcher_thread_;

  std::vector<std::tuple<uint32_t, std::string>> games_ = {};
};

#endif // MAINMENUVIEW_H
