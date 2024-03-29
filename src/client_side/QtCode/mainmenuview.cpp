#include "mainmenuview.h"
#include "../../../src/client_side/build/src/client_side/build-Test-Desktop_Qt_6_2_4_GCC_64bit-Debug/ui_mainmenuview.h"
#include "../../../src/client_side/models/api_wrapper.h"
#include "../../../src/client_side/models/user_client.h"
#include <QPlainTextEdit>
#include <QStringList>
#include <variant>

MainMenuView::MainMenuView(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainMenuView) {
  ui->setupUi(this);
  // ui->horizontalLayout_2->removeWidget(ui->horizontalLayout_2->itemAt(0)->widget());

  this->setStyleSheet("selection-color: green");

  ui->stackedWidget->setCurrentIndex(0);
  // hyperlien
  ui->label_Help->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
  ui->label_Help->setOpenExternalLinks(true);
  ui->label_Help->setTextFormat(Qt::RichText);
  ui->label_Help->setText("<a "
                          "href=\"https://www.gigamic.com/files/catalog/"
                          "products/rules/quoridor-classic-fr.pdf\">rules</a>");

  InitMessageFetcherThread();
}

MainMenuView::~MainMenuView() {
  StopFetchingMessages();
  message_fetcher_thread_.quit();

  delete ui;
  message_fetcher_thread_.wait();
}

/// play : from main to game
void MainMenuView::on_pushButton_clicked() {

  // get the username of opponent user
    if (ui->comboBox->currentText()==""){
        ui->label->setText(QString::fromStdString("No Game Selected"));
        return;
    }
  object_id_t game_id = std::get<0>(games_[ui->comboBox->currentIndex()]);
  auto game_or_err = ApiWrapper::GetShared()->GetGame(game_id);
  if (std::holds_alternative<ApiError>(game_or_err)) {
    ui->label->setText(QString::fromStdString(get<ApiError>(game_or_err).error_message));
  } else {
    auto game = std::get<Game>(game_or_err);
    auto current_user_or_error = ApiWrapper::GetShared()->GetCurrentUser();
    if (std::holds_alternative<LoginError>(current_user_or_error)) {
      ui->label->setText(QString::fromStdString(get<ApiError>(current_user_or_error).error_message));
    } else {
      auto user = std::get<UserClient>(current_user_or_error);
      auto other_player_id_iter =
          std::find_if(game.GetPlayers().begin(), game.GetPlayers().end(),
                       [&](auto &p) { return user.GetId() != p->GetUserId(); });
      if (other_player_id_iter == game.GetPlayers().end()) {
        // Todo gérer Ia
      }

      else {
        // On a trouvé un autre joueur !
        std::optional<object_id_t> other_player_id =
            (*other_player_id_iter)->GetUserId();
        if (!other_player_id.has_value()) {
          // Erreur inconnu
          return;
        }
        auto all_users_or_error = ApiWrapper::GetShared()->GetAllUsers();
        if (std::holds_alternative<ApiError>(all_users_or_error)) {
          ui->label->setText(QString::fromStdString(get<ApiError>(all_users_or_error).error_message));
          return;
        }

        auto all_users = std::get<std::vector<UserClient>>(all_users_or_error);

        auto other_user_iter =
            std::find_if(all_users.begin(), all_users.end(), [&](auto &user) {
              return user.GetId() == other_player_id;
            });

        if (other_user_iter == all_users.end()) {
          // todo erreur
          return;
        }
        selected_friend_ = std::move(*(other_user_iter));
        StartFetchingMessages();
      }
    }
  }

  ui->horizontalLayout_2->addWidget(
      new MenuBoardView(game_id));

  ui->stackedWidget->setCurrentIndex(8);
  this->showMaximized();
}

void MainMenuView::on_lineEdit_SearchFriendUsername_textChanged(
    const QString &arg1) {}

void MainMenuView::on_pushButton_BackAddFriend_clicked() {
  updateFriendsComboBoxView(ui->comboBox_ChooseFriend);
  ui->stackedWidget->setCurrentIndex(5);
}

void MainMenuView::on_pushButton_AddFriend_clicked() {
  auto user_fetch_result =
      ApiWrapper::GetShared()->GetAllUsersExceptCurrentUser();
  auto current_user = ApiWrapper::GetShared()->GetCurrentUser();

  std::vector<UserClient> users_;
  std::vector<string> friends;

  if (std::holds_alternative<ApiError>(user_fetch_result)) {
    users_ = {};
  } else {
    users_ = std::move(std::get<std::vector<UserClient>>(user_fetch_result));
  }
  string friends_usernames;
  for (auto &user : users_) {
    friends_usernames += user.GetUsername().GetValue() + "\n";
  }
  ui->textEdit_DisplayFriendsAddFriend->setText(
      QString::fromStdString(friends_usernames));

  ui->stackedWidget->setCurrentIndex(9);
}

void MainMenuView::on_pushButton_Chat_clicked() {
  selected_friend_ = friends_[ui->comboBox_ChooseFriend->currentIndex()];
  StartFetchingMessages();
  ui->stackedWidget->setCurrentIndex(6);
}

void MainMenuView::on_pushButton_BackChooseFriend_clicked() {
  updateFriendsComboBoxView(ui->comboBox_ChooseFriend);
  ui->stackedWidget->setCurrentIndex(3);
}

void MainMenuView::on_pushButton_Register_clicked() {
  auto username = ui->lineEdit_PseudoRegistration->text().toStdString();
  auto password = ui->lineEdit_PasswordRegistration->text().toStdString();

  if (password !=
      ui->lineEdit_PasswordVerificationRegistration->text().toStdString()) {
    ui->label_RegistrationDone->setText("Password mismatch");
  } else {
    // passwords match
    auto api_wrapper = ApiWrapper::CreateAccount(username, password);

    if (holds_alternative<ApiError>(api_wrapper)) {
      ui->label_RegistrationDone->setText(
          QString::fromStdString(get<ApiError>(api_wrapper).error_message));
    } else {
      ui->stackedWidget->setCurrentIndex(3);
    }
  }
}

void MainMenuView::on_pushButton_game_quit_clicked() {
  StopFetchingMessages();
  ui->horizontalLayout_2->itemAt(0)->widget()->deleteLater();
  ui->stackedWidget->setCurrentIndex(3);
}

void MainMenuView::on_pushButton_QuitWelcome_clicked() { exit(0); }

void MainMenuView::on_pushButton_LoginWelcome_clicked() {
  ui->label_LoginDone->clear();
  ui->lineEdit_PseudoLogin->clear();
  ui->lineEdit_PasswordLogin->clear();
  ui->stackedWidget->setCurrentIndex(1);
  updateFriendsComboBoxView(ui->comboBox_ChooseFriend);
  updateRankingView();
}

void MainMenuView::on_pushButton_RegisterWelcome_clicked() {
  ui->label_RegistrationDone->clear();
  ui->lineEdit_PseudoRegistration->clear();
  ui->lineEdit_PasswordRegistration->clear();
  ui->lineEdit_PasswordVerificationRegistration->clear();
  ui->stackedWidget->setCurrentIndex(2);
}

void MainMenuView::on_pushButton_PlayShortcutWelcome_clicked() {
  ui->stackedWidget->setCurrentIndex(10);
}

void MainMenuView::on_pushButton_GrayTheme_clicked() {
  this->setStyleSheet("background-color: darkGrey;"
                      "font: Bold;");
}

void MainMenuView::on_pushButton_RedTheme_clicked() {
  this->setStyleSheet("background-color: darkRed;"
                      "font: Bold;");
}

void MainMenuView::on_pushButton_WhiteTheme_clicked() {
  this->setStyleSheet("background-color: white;");
}

void MainMenuView::on_pushButton_AddAddFriend_clicked() {
  auto user_to_add_username_str =
      ui->lineEdit_SearchFriendUsername->text()
          .toStdString(); // username written by the user_to_add_username_str

  std::unique_ptr<UserClient> user_to_add;

  try {
    user_to_add =
        std::make_unique<UserClient>(Username{user_to_add_username_str});
  } catch (const std::exception &err) {
    ui->label_FriendAdded->setStyleSheet("QLabel{color: rgb(193, 33, 5);}");
    ui->label_FriendAdded->setText(err.what());
    ui->label_FriendAdded->show();
    QTimer::singleShot(3000, ui->label_FriendAdded, &QLabel::hide);
    return;
  }
  std::vector<UserClient> users_;

  auto err = ApiWrapper::GetShared()->AddFriend(*user_to_add);

  if (err.has_value()){
    ui->label_FriendAdded->setStyleSheet("QLabel{color: rgb(193, 33, 5);}");
    ui->label_FriendAdded->setText(QString::fromStdString(err->error_message));
    ui->label_FriendAdded->show();
    QTimer::singleShot(3000, ui->label_FriendAdded, &QLabel::hide);
  }
  else{
    ui->label_FriendAdded->setStyleSheet("QLabel{color: rgb(97, 216, 54);}");
    ui->label_FriendAdded->setText(QString::fromStdString("Friend added successfully !"));
    ui->label_FriendAdded->show();
    QTimer::singleShot(3000, ui->label_FriendAdded, &QLabel::hide);
  }
}

void MainMenuView::on_pushButton_BackHelp_clicked() {

  ui->stackedWidget->setCurrentIndex(3);
}

void MainMenuView::on_pushButton_SendButtonChat_clicked() {
  send_message(ui->lineEdit_InputNewMessage->text().toStdString());
  ui->lineEdit_InputNewMessage->setText("");
}

void MainMenuView::on_pushButton_game_chat_send_clicked() {
  send_message(ui->lineEdit_15->text().toStdString());
  ui->lineEdit_15->setText("");
}


void MainMenuView::send_message(string message){
  if (!selected_friend_.has_value()) {
// TODO: Afficher message erreur que l'utilisateru pas selectionne
    return;
  }

  auto message_res = ApiWrapper::GetShared()->SendNewMessage(
      *selected_friend_, message);

  if (message_res.has_value()) {
// TODO: erreur: message_res->error_message
    return;
  }
}

void MainMenuView::on_lineEdit_InputNewMessage_returnPressed()
{
    this->setStyleSheet("background-color: white;");

  send_message(ui->lineEdit_InputNewMessage->text().toStdString());
  ui->lineEdit_InputNewMessage->setText("");
}

//void lineEdit_InputNewMessage::keyPressEvent(QKeyEvent *event)
void MainMenuView::keyPressEvent(QKeyEvent *event)
{
  if(event->key() == Qt::Key_Enter)
  {
    this->setStyleSheet("background-color: white;");
  }
}
void MainMenuView::on_lineEdit_15_returnPressed()
{
  send_message(ui->lineEdit_15->text().toStdString());
  ui->lineEdit_15->setText("");
}

void MainMenuView::on_pushButton_BackChat_clicked() {
  StopFetchingMessages();
  ui->stackedWidget->setCurrentIndex(5);
}

void MainMenuView::on_pushButton_BackRanking_clicked() {
  updateRankingView();
  ui->stackedWidget->setCurrentIndex(3);
}

void MainMenuView::updateChatRoom() {
  auto conv_req_res =
      ApiWrapper::GetShared()->GetConversationWithUser(*selected_friend_);
  auto curr_user_req_res = ApiWrapper::GetShared()->GetCurrentUser();

  auto curr_user = std::get<UserClient>(curr_user_req_res);

  while (true) {
    auto messages = std::get<std::vector<Message>>(conv_req_res);
    for (const auto &mess : messages) {
      bool is_this_user_sender = mess.GetSenderId() == curr_user.GetId();
      std::string mess_bubble = is_this_user_sender
                                    ? "Me: "
                                    : curr_user.GetUsername().GetValue() + ": ";
      mess_bubble += mess.GetContent();
      ui->textEdit_Conversation->append(QString::fromStdString(mess_bubble));
    }
  }
}

void MainMenuView::on_pushButton_EnterLogin_clicked() {
  auto login_res =
      ApiWrapper::Login(ui->lineEdit_PseudoLogin->text().toStdString(),
                        ui->lineEdit_PasswordLogin->text().toStdString());

  if (holds_alternative<LoginError>(login_res)) {

    ui->label_LoginDone->setText(
        QString::fromStdString(std::get<LoginError>(login_res).error_message));
    ui->label_LoginDone->show();
    QTimer::singleShot(3000, ui->label_LoginDone, &QWidget::hide);
  } else {
    ApiWrapper::GetShared() = std::get<ApiWrapper>(login_res);
    ui->stackedWidget->setCurrentIndex(3);
  }
}

void MainMenuView::on_pushButton_BackLogin_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
}

void MainMenuView::on_pushButton_BackRegister_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
}

// 0 choose login
// 1 login
// 2 register
// 3 Main
// 4 Ranking
// 5 FriendList
// 6 Chat Room
// 7 Help
// 8 Game
void MainMenuView::on_pushButton_BackMainMenu_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
}

void MainMenuView::on_pushButton_HelpMainMenu_clicked() {
  ui->stackedWidget->setCurrentIndex(7);
}

void MainMenuView::on_pushButton_RankingMainMenu_clicked() {
  updateRankingView();
  ui->stackedWidget->setCurrentIndex(4);
}

void MainMenuView::on_pushButton_FriendListMainMenu_clicked() {
  updateFriendsComboBoxView(ui->comboBox_ChooseFriend);
  ui->stackedWidget->setCurrentIndex(5);
}


/////Functions
void MainMenuView::updateChatRoomMessagesListView() {
  ui->textEdit_Conversation->clear();
  if (!selected_friend_.has_value()) {
    // TODO: Afficher message d'erreur (l'ami n'a pas ete selectionne)
    return;
  }
  // TODO: Effacer message erreur

  auto conv_req_res =
      ApiWrapper::GetShared()->GetConversationWithUser(*selected_friend_);
  auto curr_user_req_res = ApiWrapper::GetShared()->GetCurrentUser();

  if (std::holds_alternative<LoginError>(curr_user_req_res)) {
    // TODO:: Afficher errur login
    return;
  }

  auto curr_user = std::get<UserClient>(curr_user_req_res);

  if (std::holds_alternative<ApiError>(conv_req_res)) {
    // TODO: Afficher l'erreur
    auto err = std::get<ApiError>(conv_req_res);
    // ui->label_error->setText(QString::fromStdString(err.error_message));
    return;
  } else {
    auto messages = std::get<std::vector<Message>>(conv_req_res);
    for (const auto &mess : messages) {
      bool is_this_user_sender = mess.GetSenderId() == curr_user.GetId();
      std::string mess_bubble =
          is_this_user_sender
              ? curr_user.GetUsername().GetValue() + " : "
              : selected_friend_->GetUsername().GetValue() + " : ";
      mess_bubble += mess.GetContent();
      ui->textEdit_Conversation->append(QString::fromStdString(mess_bubble));
    }
  }
}

void MainMenuView::updateChatRoomMessagesListView(const std::string &room) {
  if (room == "chat") {
    ui->textEdit_Conversation->clear();
  } else if (room == "game") {
    ui->lineEdit_15->setText("");
  }

  if (!selected_friend_.has_value()) {
    // TODO: Afficher message d'erreur (l'ami n'a pas ete selectionne)
    return;
  }
  // TODO: Effacer message erreur

  auto conv_req_res =
      ApiWrapper::GetShared()->GetConversationWithUser(*selected_friend_);
  auto curr_user_req_res = ApiWrapper::GetShared()->GetCurrentUser();

  if (std::holds_alternative<LoginError>(curr_user_req_res)) {
    // TODO:: Afficher errur login
    return;
  }

  auto curr_user = std::get<UserClient>(curr_user_req_res);

  if (std::holds_alternative<ApiError>(conv_req_res)) {
    // TODO: Afficher l'erreur
    auto err = std::get<ApiError>(conv_req_res);
    std::cout << err.error_message << std::endl;
    return;
  } else {
    auto messages = std::get<std::vector<Message>>(conv_req_res);
    for (const auto &mess : messages) {
      bool is_this_user_sender = mess.GetSenderId() == curr_user.GetId();
      std::string mess_bubble =
          is_this_user_sender
              ? "Me: "
              : selected_friend_->GetUsername().GetValue() + ": ";
      mess_bubble += mess.GetContent();

      if (room == "chat") {
        ui->textEdit_Conversation->append(QString::fromStdString(mess_bubble));
      } else if (room == "game") {
        ui->textEdit_7->append(QString::fromStdString(mess_bubble));
      }
    }
  }
}

void MainMenuView::updateFriendsComboBoxView(QComboBox *combobox) {

  combobox->clear();
  std::vector<string> friends;
  auto current_user = ApiWrapper::GetShared()->GetCurrentUser();

  if (std::holds_alternative<LoginError>(current_user)) {
    friends_ = {};
  } else {
    friends_ = std::move(std::get<UserClient>(current_user).GetFriends());
  }

  for (auto &user : friends_) {
    combobox->addItem(QString::fromStdString(user.GetUsername().GetValue()));
    friends.push_back(user.GetUsername().GetValue());
  }
  if (friends.empty())
    ui->pushButton_Chat->hide();
  else
    ui->pushButton_Chat->show();
}

void MainMenuView::updateRankingView() {
  std::vector<UserClient> users_;
  try {
    users_ = ApiWrapper::GetUsersRanked(MAX_NUM_USERS_RANKING_DEFAULT);
  } catch (const std::runtime_error &) {
    users_.clear();
  }
  std::string rankings;
  for (auto &user : users_) {
    std::string label = user.GetUsername().GetValue();
    label += " : ";
    label += std::to_string(user.GetScore());
    label += " pts";
    rankings += label + "\n";
  }
  ui->textEdit_RankingDisplay->setText(QString::fromStdString(rankings));
}

void MainMenuView::on_pushButton_PlayMainMenu_clicked() {
  ui->stackedWidget->setCurrentIndex(10);
  std::variant<std::vector<std::tuple<uint32_t, std::string>>, ApiError> res =
      ApiWrapper::GetShared()->GetGameRoomNames();
  ui->comboBox->clear();
  if (holds_alternative<ApiError>(res)) {
    games_ = {};
  } else {
    games_ = std::move(
        std::get<std::vector<std::tuple<uint32_t, std::string>>>(res));
    for (auto &game : games_) {
      ui->comboBox->addItem(QString::fromStdString(std::get<1>(game)));
    }
  }
}

void MainMenuView::on_pushButton_BackToMenuFromJoin_clicked() {
  ui->stackedWidget->setCurrentIndex(3);
}

void MainMenuView::on_pushButton_ToInviteFriend_clicked() {
  updateFriendsComboBoxView(ui->comboBox_InviteBox);
  ui->stackedWidget->setCurrentIndex(11);
}

void MainMenuView::on_pushButton_InviteToGame_clicked() {
  if (ui->lineEdit->text().toStdString() != "" &&
      ui->comboBox_InviteBox->currentText().toStdString() != "") {
    auto err = ApiWrapper::GetShared()->CreateGame(
        ui->lineEdit->text().toStdString(),
        ui->comboBox_InviteBox->currentText().toStdString());
    ui->stackedWidget->setCurrentIndex(10);
  }
  std::variant<std::vector<std::tuple<uint32_t, std::string>>, ApiError> res =
      ApiWrapper::GetShared()->GetGameRoomNames();
  ui->comboBox->clear();
  if (holds_alternative<ApiError>(res)) {
    games_ = {};
  } else {
    games_ = std::move(
        std::get<std::vector<std::tuple<uint32_t, std::string>>>(res));
    for (auto &game : games_) {
      ui->comboBox->addItem(QString::fromStdString(std::get<1>(game)));
    }
  }
}

void MainMenuView::on_pushButton_BackToJoinMenu_clicked() {
  ui->stackedWidget->setCurrentIndex(10);
}

void MainMenuView::on_lineEditNameOfGame_cursorPositionChanged(int arg1,
                                                               int arg2) {}
void MainMenuView::UpdateMessageViews(const std::vector<Message> &messages,
                                      const UserClient &other_user) {
  ui->textEdit_Conversation->setText("");
  ui->textEdit_7->setText("");
  for (const auto &mess : messages) {
    bool is_this_user_sender = mess.GetSenderId() != other_user.GetId();
    std::string mess_bubble = is_this_user_sender
                                  ? "Me: "
                                  : other_user.GetUsername().GetValue() + ": ";
    mess_bubble += mess.GetContent();

    ui->textEdit_Conversation->append(QString::fromStdString(mess_bubble));
    ui->textEdit_7->append(QString::fromStdString(mess_bubble));
  }
}

void MainMenuView::InitMessageFetcherThread() {
  auto fetcher = new MessageFetcher();
  fetcher->moveToThread(&message_fetcher_thread_);
  connect(&message_fetcher_thread_, &QThread::finished, fetcher,
          &QObject::deleteLater);
  connect(this, &MainMenuView::__StartFetchingMessages, fetcher,
          &MessageFetcher::StartFetching);
  connect(fetcher, &MessageFetcher::messagesFetched, this,
          &MainMenuView::UpdateMessageViews);
  message_fetcher_thread_.start();
}

void MainMenuView::StartFetchingMessages() {
  if (!selected_friend_.has_value()) {
    return;
  }
  should_fetch_messages_ = true;
  __StartFetchingMessages(*selected_friend_,
                          [&]() { return should_fetch_messages_; });
}
