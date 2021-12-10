cmake_minimum_required(VERSION 3.20)
project(Quoridor)

set(CMAKE_CXX_STANDARD 20)

add_executable(Quoridor
        main.cpp
        common/game_logic/constants.h
        server-side/platform/user.h
        server-side/game_logic/board.h
        server-side/game_logic/game.h
        server-side/game_logic/piece.h
        server-side/game_logic/player.h
        )
