cmake_minimum_required(VERSION 3.21)
project(Quoridor)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenSSL REQUIRED)

add_executable(QuoridorClient src/client_side/main.cpp)
add_executable(QuoridorServer src/server_side/main.cpp src/server_side/models/board.cpp src/server_side/models/board.h src/server_side/models/cell.cpp src/server_side/models/cell.h src/server_side/models/wall.cpp src/server_side/models/wall.h src/server_side/models/position.cpp src/server_side/models/position.h src/server_side/models/Pawn.h src/server_side/models/Pawn.cpp src/server_side/models/Player.h src/server_side/models/Player.cpp src/server_side/models/Game.h src/server_side/models/Game.cpp src/server_side/views/api/quoridor_api.cpp src/server_side/views/api/quoridor_api.h)


target_include_directories(QuoridorServer PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(QuoridorServer ${Boost_LIBRARIES} OpenSSL::SSL)
target_include_directories(QuoridorClient PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(QuoridorClient ${Boost_LIBRARIES} OpenSSL::SSL)


set(CMAKE_BINARY_DIR ${PROJECT_BINARY_DIR}/cmake-bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)