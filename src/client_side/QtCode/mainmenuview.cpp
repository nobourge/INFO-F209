#include "mainmenuview.h"
#include "ui_mainmenuview.h"

MainMenuView::MainMenuView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenuView)
{
  ui->setupUi(this);

  this->setStyleSheet("selection-color: green");

  std::string theme = "dark_red";
  //std::string theme = "dark_grey";

  if(theme == "black")
  {
    //todo this->setStyleSheet("QInputDialog {background-color: white;}"
    this->setStyleSheet("background-color: black;"
                        "color: white;"
                        "border: red");
  }

  else if(theme == "dark_grey")
  {
    this->setStyleSheet("background-color: darkGrey;"
                        "font: Bold;"
    );
  }

  else if(theme == "dark_red")
  {
    this->setStyleSheet("background-color: darkRed;"
                        "font: Bold;"
    );
  }

  //todo if a field is mandatory:
  //field->setProperty("mandatoryField",true);
  //todo then here uncomment  next line:
  //*[mandatoryField="true"] {background_color: yellow};

  setFixedSize(size());
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

///?
///not close window
///not reduce window
void MainMenuView::on_pushButton_0_clicked()
{
  ui->stackedWidget->setCurrentIndex(5);
  this->setStyleSheet("background-color: blue");
}

///?
///not close window
///not reduce window
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

///from login back to welcome
void MainMenuView::on_pushButton_11_clicked()
{
  this->setStyleSheet("background-color: blue");

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


void MainMenuView::on_pushButton_3_clicked()
{
  ui->stackedWidget->setCurrentIndex(7);
}

