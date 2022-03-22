#include "mainmenuview.h"
#include "ui_mainmenuview.h"
#include "../models/api_wrapper.h"

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

//Login button
void MainMenuView::on_pushButton_10_clicked()
{
  auto login_res = ApiWrapper::Login(ui->lineEdit->text().toStdString(), ui->lineEdit_2->text().toStdString());

    //if (holds_alternative<LoginError>(login_res)) {
    //  //Mettre ici le message d'erreur
    //}
    //else {
    ApiWrapper::GetShared() = std::get<ApiWrapper>(login_res);
    ui->stackedWidget->setCurrentIndex(3);
    //}

}


void MainMenuView::on_pushButton_12_clicked()
{
  // we only need
    auto username = ui->lineEdit_3->text().toStdString();
    auto password = ui->lineEdit_4->text().toStdString();

    if (password != ui->lineEdit_5->text().toStdString()) {
      // error_message_ = "Password mismatch";
    } else {
      // passwords match
      auto api_wrapper = ApiWrapper::CreateAccount(username, password);

      // if (holds_alternative<ApiError>(api_wrapper)) {
      //   // error occurred
      //   error_message_ = get<ApiError>(api_wrapper).error_message;
      // } else {
        ui->stackedWidget->setCurrentIndex(3);
      //}
    }
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
  ui->stackedWidget->setCurrentIndex(5);
}


void MainMenuView::on_pushButton_18_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}

///message send
void MainMenuView::on_pushButton_17_clicked()
{
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

