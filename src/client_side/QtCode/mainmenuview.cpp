#include "mainmenuview.h"
#include "game.h"
#include "board_scene.h"
#include "../../../src/client_side/build-Test-Desktop_Qt_6_2_4_GCC_64bit-Debug/ui_mainmenuview.h"
#include <QComboBox>
#include <QStringList>
#include <QPlainTextEdit>
#include <variant>
#include "../../../src/client_side/models/user_client.h"
#include "../../../src/client_side/models/api_wrapper.h"

MainMenuView::MainMenuView(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainMenuView) {
  ui->setupUi(this);


  this->setStyleSheet("selection-color: green");

  ui->stackedWidget->setCurrentIndex(0);
  ui->stackedWidget->addWidget(menuView);
  cout<<ui->stackedWidget->count()<<endl;
}

MainMenuView::~MainMenuView()
{
  delete ui;
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

///play : from main to game
void MainMenuView::on_pushButton_clicked() {
  ui->stackedWidget->setCurrentIndex(8);
}

///from home_menu back to login
void MainMenuView::on_pushButton_5_clicked() {

  ui->stackedWidget->setCurrentIndex(1);
}

///from welcome to login
void MainMenuView::on_pushButton_9_clicked() {

}

///from welcome to register
void MainMenuView::on_pushButton_6_clicked() {

}

///Quit
void MainMenuView::on_pushButton_8_clicked() {
}

///back : from login to welcome
void MainMenuView::on_pushButton_11_clicked() {
  //this->setStyleSheet("background-color: blue");}
}
void MainMenuView::on_pushButton_10_clicked() {}

void MainMenuView::on_pushButton_12_clicked() {
  // we only need

}

void MainMenuView::on_pushButton_13_clicked() {}

void MainMenuView::on_pushButton_4_clicked() {

  ui->stackedWidget->setCurrentIndex(4);
}

void MainMenuView::on_pushButton_14_clicked() {}

void MainMenuView::on_pushButton_16_clicked() {
}

void MainMenuView::on_pushButton_15_clicked() {

}

void MainMenuView::on_pushButton_2_clicked() {
  updateFriendsComboBoxView();
}

void MainMenuView::on_pushButton_18_clicked() {}

///message send
void MainMenuView::on_pushButton_17_clicked() {}

///game message send
void MainMenuView::on_pushButton_53_clicked() {

}

void MainMenuView::on_pushButton_19_clicked() {}

///game back to main
void MainMenuView::on_pushButton_20_clicked() {
  
}

///theme grey
void MainMenuView::on_pushButton_21_clicked() {

}

///theme red
void MainMenuView::on_pushButton_22_clicked() {

}

void MainMenuView::on_pushButton_23_clicked() {

}

void MainMenuView::on_pushButton_3_clicked() {
  ui->stackedWidget->setCurrentIndex(7);
}

void MainMenuView::on_pushButton_24_clicked() {

}

void MainMenuView::on_lineEdit_7_textChanged(const QString &arg1) {

}

void MainMenuView::on_pushButton_25_clicked() {
  ui->stackedWidget->setCurrentIndex(5);

}


void MainMenuView::on_lineEdit_SearchFriendUsername_textChanged(const QString &arg1) {
  auto user_fetch_result = ApiWrapper::GetAllUsers();

  std::vector<UserClient> users_;

  if (std::holds_alternative<ApiError>(user_fetch_result)) {
    users_ = {};
  } else {
    users_ = std::move(std::get<std::vector<UserClient>>(user_fetch_result));
  }
  string friends_usernames;
  for (auto &user : users_) {
    friends_usernames += user.GetUsername().GetValue() + "\n";
  }
  ui->textEdit_DisplayFriendsAddFriend->setText(QString::fromStdString(friends_usernames));
}


void MainMenuView::on_pushButton_BackAddFriend_clicked()
{

    ui->stackedWidget->setCurrentIndex(5);

}


void MainMenuView::on_pushButton_AddFriend_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainMenuView::on_pushButton_Chat_clicked()
{
    selected_friend_ = friends_[ui->comboBox_ChooseFriend->currentIndex()];
    updateChatRoomMessagesListView();
    ui->stackedWidget->setCurrentIndex(6);
}


void MainMenuView::on_pushButton_BackChooseFriend_clicked()
{
    updateFriendsComboBoxView();
    ui->stackedWidget->setCurrentIndex(3);
}


void MainMenuView::on_pushButton_Register_clicked()
{
    auto username = ui->lineEdit_PseudoRegistration->text().toStdString();
    auto password = ui->lineEdit_PasswordRegistration->text().toStdString();

      if (password != ui->lineEdit_PasswordVerificationRegistration->text().toStdString()) {
        ui->label_RegistrationDone->setText("Password missmatch");
      } else {
        // passwords match
        auto api_wrapper = ApiWrapper::CreateAccount(username, password);

        if (holds_alternative<ApiError>(api_wrapper)) {
          ui->label_RegistrationDone->setText(QString::fromStdString(get<ApiError>(api_wrapper).error_message));
        } else {
          ui->stackedWidget->setCurrentIndex(3);
        }
      }
}


void MainMenuView::on_pushButton_game_chat_send_clicked()
{
    /*
      auto api_wrapper = ApiWrapper::GetShared();

      if (api_wrapper.has_value()) {
        auto message_res = api_wrapper->SendNewMessage(user_to_chat_with_, ui->lineEdit_InputNewMessage->text().toStdString(););
        if (message_res.has_value()) {
          error_message_ = message_res->error_message;
        }
      } else {
        error_message_ = "Not signed in";
      }
    */
      game_chattext = game_chattext + "\n" + ui->lineEdit_15->text().toStdString();
      ui->textEdit_7->setText(QString::fromStdString(game_chattext));
      ui->lineEdit_15->setText("");

}


void MainMenuView::on_pushButton_game_quit_clicked()
{
    //this->setFixedSize(901,599);
      //this->setFixedSize(90,59);
      //this->showMinimized();
      //this->showNormal();

      ui->stackedWidget->setCurrentIndex(3);
}


void MainMenuView::on_pushButton_QuitWelcome_clicked()
{
    exit(0);

}


void MainMenuView::on_pushButton_LoginWelcome_clicked()
{
    ui->label_LoginDone->clear();
    ui->lineEdit_PseudoLogin->clear();
    ui->lineEdit_PasswordLogin->clear();
    ui->stackedWidget->setCurrentIndex(1);
    updateFriendsComboBoxView();
    updateChatRoomMessagesListView();
    updateRankingView();
}


void MainMenuView::on_pushButton_RegisterWelcome_clicked()
{
    ui->label_RegistrationDone->clear();
    ui->lineEdit_PseudoRegistration->clear();
    ui->lineEdit_PasswordRegistration->clear();
    ui->lineEdit_PasswordVerificationRegistration->clear();
    ui->stackedWidget->setCurrentIndex(2);
}


void MainMenuView::on_pushButton_PlayShortcutWelcome_clicked()
{
  ui->stackedWidget->setCurrentIndex(10);
    // auto *mainLayout = new QHBoxLayout();

    // auto *Layout_chat = new QVBoxLayout();

    // auto *queryLayout = new QHBoxLayout();

    // auto *queryLabel = new QLabel(
    //     QApplication::translate("quoridor", "New message:"));
    // auto *queryEdit = new QLineEdit();
    // auto *resultView = new QTableView();

    // queryLayout->addWidget(queryLabel);
    // queryLayout->addWidget(queryEdit);

    // Layout_chat->addWidget(resultView);
    // Layout_chat->addLayout(queryLayout);



    // QWidget canvas;
  
    // auto *Layout_board = new QVBoxLayout();

    // auto *resultView2 = new QTableView();
    // Layout_board->addWidget(resultView2);

    // mainLayout->addLayout(Layout_chat, 1);

    // mainLayout->addLayout(Layout_board, 2);
    // ui->stackedWidget->setCurrentIndex(8);
    // this->showMaximized();

    // auto *board_scene = new BoardScene();
    // this->ui->graphicsView->setScene(board_scene);

}


void MainMenuView::on_pushButton_GrayTheme_clicked()
{
    this->setStyleSheet("background-color: darkGrey;"
                        "font: Bold;"
    );
}


void MainMenuView::on_pushButton_RedTheme_clicked()
{
    this->setStyleSheet("background-color: darkRed;"
                        "font: Bold;"
    );
}


void MainMenuView::on_pushButton_WhiteTheme_clicked()
{
    this->setStyleSheet("background-color: white;"
    );
}


void MainMenuView::on_pushButton_AddAddFriend_clicked()
{
    auto user_to_add_username_str =
        ui->lineEdit_SearchFriendUsername->text().toStdString(); //username written by the user_to_add_username_str

    std::unique_ptr<UserClient> user_to_add;

    try {
      user_to_add = std::make_unique<UserClient>(Username{user_to_add_username_str});
    } catch (const std::exception &err) {
      ui->label_FriendAdded->setText(err.what()); return;
    }
    std::vector<UserClient> users_;

    auto err = ApiWrapper::GetShared()->AddFriend(*user_to_add);

    if (err.has_value())
      ui->label_FriendAdded->setText(QString::fromStdString(err->error_message));
    else
      ui->label_FriendAdded->setText(QString::fromStdString("Friend added successfully"));
}


void MainMenuView::on_pushButton_BackHelp_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainMenuView::on_pushButton_SendButtonChat_clicked()
{
    if (!selected_friend_.has_value()) {
      // TODO: Afficher message erreur que l'utilisateru pas selectionne
      return;
    }

    auto message_res = ApiWrapper::GetShared()->SendNewMessage(*selected_friend_, ui->lineEdit_InputNewMessage->text().toStdString());

    if (message_res.has_value()) {
      // TODO: erreur: message_res->error_message
      return;
    }

    updateChatRoomMessagesListView();
    ui->lineEdit_InputNewMessage->setText("");
}


void MainMenuView::on_pushButton_BackChat_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainMenuView::on_pushButton_BackRanking_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    updateRankingView();

}


void MainMenuView::on_pushButton_EnterLogin_clicked()
{
    auto login_res = ApiWrapper::Login(ui->lineEdit_PseudoLogin->text().toStdString(), ui->lineEdit_PasswordLogin->text().toStdString());

    if (holds_alternative<LoginError>(login_res)) {
      //  //Mettre ici le message d'erreur
      ui->label_LoginDone->setText("Error");
    } else {
      ApiWrapper::GetShared() = std::get<ApiWrapper>(login_res);
      ui->stackedWidget->setCurrentIndex(3);
    }
}


void MainMenuView::on_pushButton_BackLogin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainMenuView::on_pushButton_BackRegister_clicked()
{
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
void MainMenuView::on_pushButton_BackMainMenu_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);

}


void MainMenuView::on_pushButton_HelpMainMenu_clicked()
{
  ui->stackedWidget->setCurrentIndex(7);

}



void MainMenuView::on_pushButton_RankingMainMenu_clicked()
{
  ui->stackedWidget->setCurrentIndex(4);

}



void MainMenuView::on_pushButton_FriendListMainMenu_clicked()
{
  updateFriendsComboBoxView();
  ui->stackedWidget->setCurrentIndex(5);

}

void MainMenuView::on_pushButton_26_clicked()
//TODO ne fonctionne pas
{
  ui->stackedWidget->setCurrentIndex(8);

}



/////Functions


void MainMenuView::updateChatRoomMessagesListView() {
  ui->textEdit_Conversation->clear();
  if (!selected_friend_.has_value()) {
    // TODO: Afficher message d'erreur (l'ami n'a pas ete selectionne)
    std::cout << "No friend selected" << std::endl;
    return;
  }
  // TODO: Effacer message erreur

  auto conv_req_res = ApiWrapper::GetShared()->GetConversationWithUser(*selected_friend_);
  auto curr_user_req_res = ApiWrapper::GetShared()->GetCurrentUser();

  if (std::holds_alternative<LoginError>(curr_user_req_res)) {
    // TODO:: Afficher errur login
    std::cout << std::get<LoginError>(curr_user_req_res).error_message << std::endl;
    return;
  }

  auto curr_user = std::get<UserClient>(curr_user_req_res);

  if (std::holds_alternative<ApiError>(conv_req_res)) {
    // TODO: Afficher l'erreur
    auto err = std::get<ApiError>(conv_req_res);
    // ui->label_error->setText(QString::fromStdString(err.error_message));
    std::cout << err.error_message << std::endl;
    return;
  } else {
    std::cout << "Messages for " << curr_user.GetUsername().GetValue() << " and " << selected_friend_->GetUsername().GetValue() << std::endl;
    auto messages = std::get<std::vector<Message>>(conv_req_res);
    for (const auto &mess : messages) {
      std::cout << mess.GetContent() << std::endl;
      bool is_this_user_sender = mess.GetSenderId() == curr_user.GetId();
      std::string mess_bubble = is_this_user_sender ? "Me: " : "Friend: ";
      mess_bubble += mess.GetContent();
      ui->textEdit_Conversation->append(QString::fromStdString(mess_bubble));
    }
  }
}




void MainMenuView::updateFriendsComboBoxView() {
  ui->comboBox_ChooseFriend->clear();

  std::vector<string> friends;
  auto current_user = ApiWrapper::GetShared()->GetCurrentUser();

  if (std::holds_alternative<LoginError>(current_user)) {
    friends_ = {};
  } else {
    friends_ = std::move(std::get<UserClient>(current_user).GetFriends());
  }

  for (auto &user : friends_) {
    ui->comboBox_ChooseFriend->addItem(QString::fromStdString(user.GetUsername().GetValue()));
    friends.push_back(user.GetUsername().GetValue());
  }
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
