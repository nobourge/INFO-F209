#include "mainmenuview.h"
#include "../../../src/client_side/build-Test-Qt_6_2_3_for_macOS-Debug/ui_mainmenuview.h"
#include <QComboBox>
#include <QStringList>
#include <QPlainTextEdit>
#include "../../../src/client_side/models/user_client.h"
#include "../../../src/client_side/models/api_wrapper.h"

MainMenuView::MainMenuView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenuView)
{
  ui->setupUi(this);


  this->setStyleSheet("selection-color: green");
/*
  if(theme == "black")
  {
    //todo this->setStyleSheet("QInputDialog {background-color: white;}"
    this->setStyleSheet("background-color: black;"
                        "color: white;"
                        "border: red");
  }
*/
  //todo if a field is mandatory:
  //field->setProperty("mandatoryField",true);
  //todo then here uncomment  next line:
  //*[mandatoryField="true"] {background_color: yellow};

  //setFixedSize(size());
  ui->stackedWidget->setCurrentIndex(0);
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
void MainMenuView::on_pushButton_clicked()
{
  ui->stackedWidget->setCurrentIndex(8);
}

///?
void MainMenuView::on_pushButton_1_clicked()
{
  this->setStyleSheet("background-color: blue");
}

///from home_menu back to login
void MainMenuView::on_pushButton_5_clicked()
{

  ui->stackedWidget->setCurrentIndex(1);
}


///from welcome to login
void MainMenuView::on_pushButton_9_clicked()
{

  ui->stackedWidget->setCurrentIndex(1);
}

///from welcome to register
void MainMenuView::on_pushButton_6_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}

///Quit
void MainMenuView::on_pushButton_8_clicked()
{
  exit(0);
}

///back : from login to welcome
void MainMenuView::on_pushButton_11_clicked()
{
  //this->setStyleSheet("background-color: blue");

  ui->stackedWidget->setCurrentIndex(0);
}


void MainMenuView::on_pushButton_10_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}


void MainMenuView::on_pushButton_12_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}


void MainMenuView::on_pushButton_13_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}


void MainMenuView::on_pushButton_4_clicked()
{
  ui->stackedWidget->setCurrentIndex(4);
}


void MainMenuView::on_pushButton_7_clicked()
{
  Rankingtext=Rankingtext+"\n test";
  ui->textEdit->setText(QString::fromStdString( Rankingtext));
}


void MainMenuView::on_pushButton_14_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}


void MainMenuView::on_pushButton_16_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}


void MainMenuView::on_pushButton_15_clicked()
{
  ui->stackedWidget->setCurrentIndex(6);
}


void MainMenuView::on_pushButton_2_clicked()
{
//  auto user_fetch_result = ApiWrapper::GetAllUsers();
//  if (std::holds_alternative<ApiError>(user_fetch_result)) {
//    //TODO add user
//
//  } else {
//    std::vector<UserClient> users_;
//    users_ = std::move(std::get<std::vector<UserClient>>(user_fetch_result));
//  }
  ui->comboBox->addItem("a"); //exemple pour rajouter un element
  ui->comboBox->addItem("b"); //exemple pour rajouter un element
  ui->comboBox->addItem("c"); //exemple pour rajouter un element

  ui->stackedWidget->setCurrentIndex(5);
}


void MainMenuView::on_pushButton_18_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}

///message send
void MainMenuView::on_pushButton_17_clicked()
{
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
  chattext=chattext+"\n"+ui->lineEdit_6->text().toStdString();
  ui->textEdit_2->setText(QString::fromStdString( chattext));
  ui->lineEdit_6->setText("");
}

void MainMenuView::on_pushButton_19_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}

///game back to main
void MainMenuView::on_pushButton_20_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}

///theme grey
void MainMenuView::on_pushButton_21_clicked()
{
  this->setStyleSheet("background-color: darkGrey;"
                      "font: Bold;"
  );
}

///theme red
void MainMenuView::on_pushButton_22_clicked()
{
  this->setStyleSheet("background-color: darkRed;"
                      "font: Bold;"
  );
}

void MainMenuView::on_pushButton_23_clicked()
{
  this->setStyleSheet("background-color: white;"
  );
}


void MainMenuView::on_pushButton_3_clicked()
{
  ui->stackedWidget->setCurrentIndex(7);
}


void MainMenuView::on_pushButton_24_clicked()
{
  ui->stackedWidget->setCurrentIndex(9);

}


void MainMenuView::on_lineEdit_7_textChanged(const QString &arg1)
{
  auto user_fetch_result = ApiWrapper::GetAllUsers();

  std::vector<UserClient> users_;

  if (std::holds_alternative<ApiError>(user_fetch_result)) {
    users_ = {};
  } else {
    users_ = std::move(std::get<std::vector<UserClient>>(user_fetch_result));
  }
  string friends_usernames;
  for (auto &user:users_) {
    friends_usernames += user.GetUsername().GetValue() +"\n";
  }
  ui->textEdit_3->setText(QString::fromStdString( friends_usernames));
}


void MainMenuView::on_pushButton_25_clicked()
{
  ui->stackedWidget->setCurrentIndex(5);

}

