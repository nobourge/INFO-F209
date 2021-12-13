cmake_minimum_required(VERSION 3.20)
project(Quoridor)

set(CMAKE_CXX_STANDARD 20)

add_executable(Quoridor
        main.cpp

        common/game_logic/constants.h
        common/game_logic/board.h
        common/game_logic/board_position.h
        common/game_logic/game.h
        common/game_logic/piece.h
        common/game_logic/player.h

        server-side/platform/user.h

        server-side/api_controller/v1/game.h
        server-side/api_controller/v1/user.h
        server-side/platform/username.h
        server-side/platform/abstract_validator.h
        server-side/platform/validators/username_validator.h
        server-side/platform/validators/password_validator.h
        client-side/views/saved_game_joiner.h client-side/views/friend_list_view.h client-side/views/main_menu_view.h client-side/views/disconnect_menu_view.h client-side/views/game_configurator_menu_view.h common/game_logic/game_mode.h)
