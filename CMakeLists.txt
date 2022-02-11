cmake_minimum_required(VERSION 3.21)
project(Quoridor)

set(CMAKE_CXX_STANDARD 20)

add_executable(QuoridorServer src/server_side/main.cpp)
add_executable(QuoridorClient src/client_side/main.cpp src/server_side/models/board.cpp src/server_side/models/board.h src/server_side/models/cell.cpp src/server_side/models/cell.h src/server_side/models/wall.cpp src/server_side/models/wall.h src/server_side/models/position.cpp src/server_side/models/position.h)

set(CMAKE_BINARY_DIR ${PROJECT_BINARY_DIR}/cmake-bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
