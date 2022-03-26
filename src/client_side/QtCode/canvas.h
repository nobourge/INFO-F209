//
// Created by noe on 24.03.22.
//

#ifndef QUORIDOR_SRC_CLIENT_SIDE_QTCODE_CANVAS_H_
#define QUORIDOR_SRC_CLIENT_SIDE_QTCODE_CANVAS_H_


#include <QWidget>
///Qt-compatible widget representing the canvas on which the board is drawn repeatedly.
//:attribute board:
class Canvas:QWidget{
 public:
  Canvas(QWidget *parent=nullptr,
         int cells_rows_quantity=9);
  //float width = 4 * main_window_width / 5;
  float width = 400;
  //float height = 9 * main_window_height / 10;
  float height = 300;
  float cells_rows_quantity;
  float walls_rows_quantity = cells_rows_quantity-1;

  float cell_size;
  double wall_edge_min;
};



#endif //QUORIDOR_SRC_CLIENT_SIDE_QTCODE_CANVAS_H_
