cmake_minimum_required(VERSION 3.21)
project(Quoridor)

set(CMAKE_CXX_STANDARD 20)

add_executable(QuoridorServer src/server_side/main.cpp)
add_executable(QuoridorClient src/client_side/main.cpp)

set(CMAKE_BINARY_DIR ${PROJECT_BINARY_DIR}/cmake-bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
