#include "mainmenuview.h"
#include "ui_mainmenuview.h"

MainMenuView::MainMenuView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenuView)
{
    ui->setupUi(this);
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

void MainMenuView::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainMenuView::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainMenuView::on_pushButton_8_clicked()
{
    exit(0);
}


void MainMenuView::on_pushButton_11_clicked()
{
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

