//
// Created by noe on 24.03.22.
//

#include "canvas.h"


// Constructor of the class `Canvas` :param board: instance of
//the class `Board` that shall be represented :param parent:
//the parent Qt widget
Canvas::Canvas(QWidget *parent, int cells_rows_quantity)
///display_board,
/// main_window_width,
//             main_window_height,
//             parent=None)
{

  this->setFixedSize(QSize(this->width, this->height));
  this->cell_size = floor(this->height / (cells_rows_quantity));
  this->wall_edge_min = floor(this->height / (this->walls_rows_quantity));
  //this->display_grid = display_board.grid;
}
/*
class Canvas(QWidget):
"""
Qt-compatible widget representing the canvas on which the board
    is drawn repeatedly.
:attribute board:
"""

def __init__(self, display_board, N, main_window_width,
             main_window_height,
             parent=None):
"""
Constructor of the class `Canvas` :param board: instance of
the class `Board` that shall be represented :param parent:
the parent Qt widget
"""
super().__init__(parent=parent, flags=Qt.WindowFlags())

self.reset(display_board, N, main_window_width,
    main_window_height)

def reset(self, display_board, N, main_window_width,
          main_window_height):
self.N = N
self.width = 4 * main_window_width / 5
self.height = 9 * main_window_height / 10
self.setFixedSize(QSize(self.width, self.height))
self.cell_size = self.height // (self.N)
self.display_grid = display_board.grid

self.update()

def pos2rowcol(self, x, y):
"""
Transform a (x, y) position on the canvas into a cell number.
:param x: x position on the canvas
:param y: y position on the canvas
:return: tuple (row_id, col_idx)
"""
row =int(y / self.cell_size)
col =int(x / self.cell_size)
return row, col

    def paintEvent(self, event=None):
"""
Callback of the Update event on the canvas.
:param event: ignored
"""
qp = QPainter()
qp.begin(self)
self.draw(qp)
qp.end()

def draw(self, qp):
"""
Draw the board onto the canvas.
:param qp: instance of class `QPainter`
"""
self.draw_grid_debug(qp)
# associated color to each possible value of the board cells:
# empty is drawn *white*, arrow is drawn black, player 1 is
# drawn *yellow*,
# player 2 is drawn *red*
colors = [Qt.darkGreen, Qt.darkRed, Qt.white, Qt.black,
Qt.green,
Qt.red,
Qt.cyan]
qp.setPen(Qt.black)
for row in range(self.N):
# First draw the rectangle of the current row
y = 0 + row * self.cell_size
x = 0
# (x, y) represents the middle of the left cell of
# considered row
"""
qp.drawRect(
    x - cell_size // 2 + 5,
y - cell_size // 2 + 5,
self.N * cell_size - 10,
cell_size - 10
)"""
# Then draw each circle within that row
for col in range(self.N):
qp.setBrush(
    colors[self.display_grid.at(Pos2D(row, col))])
qp.drawEllipse(
    x,  # - self.cell_size / 2,
y,  # - self.cell_size / 2,
8 * self.cell_size / 9,
8 * self.cell_size / 9
)
x += self.cell_size

    def draw_grid_debug(self, qp):
"""
Draw debug lines on the canvas. Only used when adapting the size of the cells/rows.
:param qp: instance of class `QPainter`
"""
if not GRID_DEBUG:
return

qp.setPen(Qt.red)
x = 0
for i in range(self.N):
x += self.cell_size
    qp.drawLine(x, 0, x, self.height)
y = 0
for i in range(self.N):
y += self.cell_size
    qp.drawLine(0, y, self.width, y)
    */
