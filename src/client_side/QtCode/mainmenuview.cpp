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
  // ui->stackedWidget->addWidget(new MainMenuView());
  // QHBoxLayout* board_chat_layout = new QHBoxLayout();
  // board_chat_layout->addWidget(new MainMenuView());
  // ui->page_9->setLayout(board_chat_layout);
  ui->stackedWidget->addWidget(menuView);
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
  ui->label_6->setText("");
  ui->lineEdit->setText("");
  ui->lineEdit_2->setText("");
  ui->stackedWidget->setCurrentIndex(1);
}

///from welcome to register
void MainMenuView::on_pushButton_6_clicked() {
  ui->label_7->setText("");
  ui->lineEdit_4->setText("");
  ui->lineEdit_3->setText("");
  ui->stackedWidget->setCurrentIndex(2);
}

///Quit
void MainMenuView::on_pushButton_8_clicked() {
  exit(0);
}

///back : from login to welcome
void MainMenuView::on_pushButton_11_clicked() {
  //this->setStyleSheet("background-color: blue");

  ui->stackedWidget->setCurrentIndex(0);
}

void MainMenuView::on_pushButton_10_clicked() {
  auto login_res = ApiWrapper::Login(ui->lineEdit->text().toStdString(), ui->lineEdit_2->text().toStdString());

  if (holds_alternative<LoginError>(login_res)) {
    //  //Mettre ici le message d'erreur
    ui->label_6->setText("Error");
  } else {
    ApiWrapper::GetShared() = std::get<ApiWrapper>(login_res);
    ui->stackedWidget->setCurrentIndex(3);
  }
}

void MainMenuView::on_pushButton_12_clicked() {
  // we only need
  auto username = ui->lineEdit_3->text().toStdString();
  auto password = ui->lineEdit_4->text().toStdString();

  if (password != ui->lineEdit_5->text().toStdString()) {
    ui->label_7->setText("Password missmatch");
  } else {
    // passwords match
    auto api_wrapper = ApiWrapper::CreateAccount(username, password);

    if (holds_alternative<ApiError>(api_wrapper)) {
      ui->label_7->setText(QString::fromStdString(get<ApiError>(api_wrapper).error_message));
    } else {
      ui->stackedWidget->setCurrentIndex(3);
    }
  }
}

void MainMenuView::on_pushButton_13_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
}

void MainMenuView::on_pushButton_4_clicked() {
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
  ui->textEdit->setText(QString::fromStdString(rankings));
  ui->stackedWidget->setCurrentIndex(4);
}

void MainMenuView::on_pushButton_14_clicked() {
  ui->stackedWidget->setCurrentIndex(3);
}

void MainMenuView::on_pushButton_16_clicked() {
  ui->stackedWidget->setCurrentIndex(3);
}

void MainMenuView::on_pushButton_15_clicked() {
  selected_friend_ = friends_[ui->comboBox->currentIndex()];
  updateChatRoomMessagesListView();
  ui->stackedWidget->setCurrentIndex(6);
}

void MainMenuView::on_pushButton_2_clicked() {
  std::vector<string> friends;
  auto current_user = ApiWrapper::GetShared()->GetCurrentUser();

  if (std::holds_alternative<LoginError>(current_user)) {
    friends_ = {};
  } else {
    friends_ = std::move(std::get<UserClient>(current_user).GetFriends());
  }

  for (auto &user : friends_) {
    ui->comboBox->addItem(QString::fromStdString(user.GetUsername().GetValue()));
    friends.push_back(user.GetUsername().GetValue());
  }

  ui->stackedWidget->setCurrentIndex(5);
}

void MainMenuView::on_pushButton_18_clicked() {
  ui->stackedWidget->setCurrentIndex(5);
}

///message send
void MainMenuView::on_pushButton_17_clicked() {

  if (!selected_friend_.has_value()) {
    // TODO: Afficher message erreur que l'utilisateru pas selectionne
    return;
  }

  auto message_res = ApiWrapper::GetShared()->SendNewMessage(*selected_friend_, ui->lineEdit_6->text().toStdString());

  if (message_res.has_value()) {
    // TODO: erreur: message_res->error_message
    return;
  }

  updateChatRoomMessagesListView();
  ui->lineEdit_6->setText("");
}

///game message send
void MainMenuView::on_pushButton_53_clicked() {
/*
  auto api_wrapper = ApiWrapper::GetShared();

  if (api_wrapper.has_value()) {
    auto message_res = api_wrapper->SendNewMessage(user_to_chat_with_, ui->lineEdit_6->text().toStdString(););
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

void MainMenuView::on_pushButton_19_clicked() {
  ui->stackedWidget->setCurrentIndex(3);
}

///game back to main
void MainMenuView::on_pushButton_20_clicked() {
  //this->setFixedSize(901,599);
  //this->setFixedSize(90,59);
  //this->showMinimized();
  //this->showNormal();

  ui->stackedWidget->setCurrentIndex(3);
}

///theme grey
void MainMenuView::on_pushButton_21_clicked() {
  this->setStyleSheet("background-color: darkGrey;"
                      "font: Bold;"
  );
}

///theme red
void MainMenuView::on_pushButton_22_clicked() {
  this->setStyleSheet("background-color: darkRed;"
                      "font: Bold;"
  );
}

void MainMenuView::on_pushButton_23_clicked() {
  this->setStyleSheet("background-color: white;"
  );
}

void MainMenuView::on_pushButton_3_clicked() {
  ui->stackedWidget->setCurrentIndex(7);
}

void MainMenuView::on_pushButton_24_clicked() {
  ui->stackedWidget->setCurrentIndex(9);

}

void MainMenuView::on_lineEdit_7_textChanged(const QString &arg1) {
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
  ui->textEdit_3->setText(QString::fromStdString(friends_usernames));
}

void MainMenuView::on_pushButton_25_clicked() {
  ui->stackedWidget->setCurrentIndex(5);

}

///play shortcut
void MainMenuView::on_pushButton_27_clicked() {
  ui->stackedWidget->setCurrentIndex(9);
}

void MainMenuView::on_pushButton_26_clicked()
//TODO ne fonctionne pas
{
  auto user_to_add_username_str =
      ui->lineEdit_7->text().toStdString(); //username written by the user_to_add_username_str

  std::unique_ptr<UserClient> user_to_add;

  try {
    user_to_add = std::make_unique<UserClient>(Username{user_to_add_username_str});
  } catch (const std::exception &err) {
    ui->label_8->setText(err.what()); return;
  }
  std::vector<UserClient> users_;

  auto err = ApiWrapper::GetShared()->AddFriend(*user_to_add);

  if (err.has_value())
    ui->label_8->setText(QString::fromStdString(err->error_message));
  else
    ui->label_8->setText(QString::fromStdString("Friend added successfully"));
}


void MainMenuView::updateChatRoomMessagesListView() {
  ui->textEdit_2->clear();
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
      ui->textEdit_2->append(QString::fromStdString(mess_bubble));
    }
  }
}






