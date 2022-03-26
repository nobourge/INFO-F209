//
// Created by noe on 18.03.22.
//

#include "game.h"
#include "canvas.h"



int init_game(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QWidget window;

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
  window.setLayout(mainLayout);

  window.setWindowTitle(
      QApplication::translate("quoridor", "Quoridor"));
  window.showMaximized();
  return QApplication::exec();


}