cmake_minimum_required(VERSION 3.21)
project(Quoridor)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

if (UNIX)
    if(APPLE)
        file(GLOB OPENSSL_ROOT_DIR /opt/homebrew/Cellar/openssl@1.1/*)
        find_package(OpenSSL 1.0.2 REQUIRED)
    else()
        find_package(OpenSSL 1.0.1 REQUIRED)
    endif()
else()
    message(FATAL_ERROR "unsupported platform")
endif()

find_package(Boost REQUIRED COMPONENTS system)

add_executable(QuoridorClient src/client_side/main.cpp src/server_side/view_controllers/api/constants.h)
add_executable(QuoridorServer src/server_side/main.cpp src/server_side/models/board.cpp src/server_side/models/board.h src/server_side/models/cell.cpp src/server_side/models/cell.h src/server_side/models/wall.cpp src/server_side/models/wall.h src/server_side/models/position.cpp src/server_side/models/position.h src/server_side/models/Pawn.h src/server_side/models/Pawn.cpp src/server_side/models/Player.h src/server_side/models/Player.cpp src/server_side/models/Game.h src/server_side/models/Game.cpp src/server_side/view_controllers/api/base_quoridor_api.cpp src/server_side/view_controllers/api/base_quoridor_api.h src/server_side/view_controllers/api/v1/v1_api.cpp src/server_side/view_controllers/api/v1/v1_api.h src/server_side/view_controllers/api/base_api_module.cpp src/server_side/view_controllers/api/base_api_module.h src/server_side/view_controllers/api/v1/user.cpp src/server_side/view_controllers/api/v1/user.h)


target_include_directories(QuoridorServer PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(QuoridorServer ${Boost_LIBRARIES} OpenSSL::SSL)
target_include_directories(QuoridorClient PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(QuoridorClient ${Boost_LIBRARIES} OpenSSL::SSL)