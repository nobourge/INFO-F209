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



///from home_menu back to login
void MainMenuView::on_pushButton_5_clicked()
{

  ui->stackedWidget->setCurrentIndex(1);
}


///from welcome to login
void MainMenuView::on_pushButton_9_clicked()
{
  ui->label_6->setText("");
  ui->lineEdit->setText("");
  ui->lineEdit_2->setText("");
  ui->stackedWidget->setCurrentIndex(1);
}

///from welcome to register
void MainMenuView::on_pushButton_6_clicked()
{
  ui->label_7->setText("");
  ui->lineEdit_4->setText("");
  ui->lineEdit_3->setText("");
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
  auto login_res = ApiWrapper::Login(ui->lineEdit->text().toStdString(), ui->lineEdit_2->text().toStdString());

    if (holds_alternative<LoginError>(login_res)) {
    //  //Mettre ici le message d'erreur
        ui->label_6->setText("Error");
    }
    else {
    ApiWrapper::GetShared() = std::get<ApiWrapper>(login_res);
    ui->stackedWidget->setCurrentIndex(3);
    }
}


void MainMenuView::on_pushButton_12_clicked()
{
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


void MainMenuView::on_pushButton_13_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}


void MainMenuView::on_pushButton_4_clicked()
{
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
      rankings += label+"\n";
      }
    ui->textEdit->setText(QString::fromStdString(rankings));
  ui->stackedWidget->setCurrentIndex(4);
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

///game message send
void MainMenuView::on_pushButton_53_clicked()
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
  game_chattext = game_chattext + "\n" + ui->lineEdit_15->text().toStdString();
  ui->textEdit_7->setText(QString::fromStdString( game_chattext));
  ui->lineEdit_15->setText("");


}

void MainMenuView::on_pushButton_19_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}

///game back to main
void MainMenuView::on_pushButton_20_clicked()
{
  //this->setFixedSize(901,599);
  //this->setFixedSize(90,59);
  //this->showMinimized();
  //this->showNormal();

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

///play shortcut
void MainMenuView::on_pushButton_27_clicked()
{
  auto *mainLayout = new QHBoxLayout();

  auto *Layout_chat = new QVBoxLayout();

  auto *queryLayout = new QHBoxLayout();

  auto *queryLabel = new QLabel(
      QApplication::translate("quoridor", "New message:"));
  auto *queryEdit = new QLineEdit();
  auto *resultView = new QTableView();

  queryLayout->addWidget(queryLabel);
  queryLayout->addWidget(queryEdit);

  Layout_chat->addWidget(resultView);
  Layout_chat->addLayout(queryLayout);



  //QWidget canvas = Canvas();
  QWidget canvas;
  //canvas = Canvas::Canvas();

  /*
        self.hbox = QHBoxLayout()

        self.canvas = Canvas(self.board, self.N, self.width,
                             self.height,
                             parent=self.central_widget)

        self.canvas.mousePressEvent = self.handle_click_event

        self.hbox.addWidget(self.canvas, alignment=Qt.AlignCenter)

        self.load_board_button.clicked.connect(
            self.load_board)
        self.add_player_1button.clicked.connect(
            self.add_player_1)
        self.add_player_2button.clicked.connect(
            self.add_player_2)
        self.add_arrow_button.clicked.connect(
            self.add_arrow)

        self.main_hbox.addLayout(self.hbox)
        */

  auto *Layout_board = new QVBoxLayout();

  auto *resultView2 = new QTableView();
  /*
  QWidget *frame;
  //frame->setGeometry(x, y, width, height);
  frame->setStyleSheet("background-image: url(:/img/board.jpg)");
  */
  Layout_board->addWidget(resultView2);

  mainLayout->addLayout(Layout_chat,1);

  mainLayout->addLayout(Layout_board,2);
  ui->stackedWidget->setCurrentIndex(8);
  this->showMaximized();

  auto *board_scene = new MenuBoardScene();
  this->ui->graphicsView->setScene(board_scene);



  /*

  QSize size = qApp->screens()[0]->size();
  ///this->ui->setFixedSize(size.width(),size.height());

  this->setFixedSize(size.width(),size.height());

  this->ui->page_9->setFixedSize(size.width(),size.height());
  ///mainLayout->se

  //this->show();
  //this->ui->page_9->showMaximized();

  //window.showMaximized();
  ui->page_9->setStyleSheet("background-color: darkRed;"
                      "font: Bold;"
  );
   */

}

