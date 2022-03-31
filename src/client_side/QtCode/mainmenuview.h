#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include "../models/user_client.h"
#include "menu_board_view.h"
#include "message_fetcher.h"
#include <QComboBox>
#include <QMainWindow>
#include <QtCore/qthread.h>
#include <QTimer>

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

  void on_pushButton_PlayShortcutWelcome_clicked();

  ///Themes
  void on_pushButton_GrayTheme_clicked();
  void on_pushButton_RedTheme_clicked();
  void on_pushButton_WhiteTheme_clicked();

  ///MainMenuView
  void on_pushButton_QuitWelcome_clicked();
  void on_pushButton_PlayMainMenu_clicked();
  void on_pushButton_LoginWelcome_clicked();
  void on_pushButton_RegisterWelcome_clicked();
  void on_pushButton_RankingMainMenu_clicked();

  ///RegisterView
  void on_pushButton_Register_clicked();
  void on_pushButton_BackRegister_clicked();

  ///AddFriendView
  void on_pushButton_AddFriend_clicked();
  void on_pushButton_BackAddFriend_clicked();
  void on_pushButton_AddAddFriend_clicked();
  void on_lineEdit_SearchFriendUsername_textChanged(const QString &arg1);

  ///FriendListView
  void on_pushButton_Chat_clicked();
  void on_pushButton_BackChooseFriend_clicked();

  ///GameView
  void on_pushButton_game_chat_send_clicked();
  void on_pushButton_game_quit_clicked();

  ///RankingView
  void on_pushButton_BackRanking_clicked();

  ///ChatRoomView
  void on_pushButton_SendButtonChat_clicked();
  void on_pushButton_BackChat_clicked();

  ///HelpView
  void on_pushButton_BackHelp_clicked();

  ///LoginView
  void on_pushButton_EnterLogin_clicked();
  void on_pushButton_BackLogin_clicked();

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
  bool should_fetch_messages_ = false;
  QThread message_fetcher_thread_;

  std::vector<std::tuple<uint32_t, std::string>> games_ = {};
  void on_lineEdit_InputNewMessage_returnPressed();
  void send_message(string message);
  void on_lineEdit_15_returnPressed();
  void keyPressEvent(QKeyEvent *event);
};

#endif // MAINMENUVIEW_H
