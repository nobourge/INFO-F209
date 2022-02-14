cmake_minimum_required(VERSION 3.21)
project(Quoridor)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

if (UNIX)
    if(APPLE)
        # Prefer a homebrew version of OpenSSL over the one in /usr/lib
        file(GLOB OPENSSL_ROOT_DIR /opt/homebrew/Cellar/openssl@1.1/*)
        # Prefer the latest (make the latest one first)
        list(REVERSE OPENSSL_ROOT_DIR)

        find_package(OpenSSL 1.0.2 REQUIRED)
        set(OPENSSL_VERSION "1.0.2s")
    else()
        find_package(OpenSSL 1.0.1 REQUIRED)
        set(OPENSSL_VERSION "1.0.1")
    endif()

else()
    message(FATAL_ERROR "unsupported platform")
endif()


find_package(cpprestsdk REQUIRED)

add_executable(QuoridorClient src/client_side/main.cpp)

add_executable(QuoridorServer src/server_side/main.cpp src/server_side/models/board.cpp src/server_side/models/board.h src/server_side/models/cell.cpp src/server_side/models/cell.h src/server_side/models/wall.cpp src/server_side/models/wall.h src/server_side/models/position.cpp src/server_side/models/position.h src/server_side/models/Pawn.h src/server_side/models/Pawn.cpp src/server_side/models/Player.h src/server_side/models/Player.cpp src/server_side/models/Game.h src/server_side/models/Game.cpp)

set(CMAKE_BINARY_DIR ${PROJECT_BINARY_DIR}/cmake-bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
