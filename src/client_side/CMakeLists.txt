

if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I /usr/local/lib/boost_1_78_0")
endif ()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")


set(HEADERS
        models/api_wrapper.h
        models/requests.h

        view_controllers/abstract_menu_view_controller.h
        view_controllers/home_menu_view_controller.h
        view_controllers/ranking_view_controller.h
        view_controllers/abstract_view_controller.h
        view_controllers/abstract_list_menu_view_controller.h
        view_controllers/abstract_searchable_list_menu_view_controller.h
        view_controllers/login_view_controller.h
        view_controllers/create_account_view_controller.h
        view_controllers/start_view_controller.h
        view_controllers/new_game_menu_view_controller.h
        view_controllers/chat_room_view_controller.h
        view_controllers/game_view_controller.h
        view_controllers/help_view_controller.h

        views/menu_views/chat_room_menu_view.h
        views/menu_views/game_view.h
        views/menu_views/help_menu_view.h
        views/menu_views/new_game_menu_view.h
        views/menu_views/home_menu_view.h
        views/menu_views/ranking_menu_view.h
        views/menu_views/create_account_menu_view.h
        views/menu_views/login_menu_view.h
        views/menu_views/start_menu_view.h
        
        views/menu_views/views/button.h
        views/menu_views/views/abstract_view.h
        views/menu_views/views/first_responder.h
        views/menu_views/views/label.h
        views/menu_views/views/menu_button_item.h
        views/menu_views/views/text_field.h


        ../common/models/database.h

        ../common/constants.h
        ../common/models/user/user.h
        ../common/models/user/message.h
        ../common/models/user/username.h
        ../common/models/user/abstract_validator.h
        ../common/models/board.h
        ../common/models/cell.h
        ../common/models/database.h
        ../common/models/database_compatible.h
        ../common/models/Game.h
        ../common/models/ia.h
        ../common/models/input.h
        ../common/models/Player.h
        ../common/models/position.h
        ../common/models/serializable.h
        ../common/models/translator.h
        )

set(SOURCES
        main.cpp

        models/user_client.cpp
        models/user_client.h
        models/api_wrapper.cpp
        models/requests.cpp

        view_controllers/abstract_view_controller.cpp
        view_controllers/abstract_searchable_list_menu_view_controller.cpp
        view_controllers/abstract_searchable_list_menu_view_controller.h
        view_controllers/abstract_list_menu_view_controller.cpp
        view_controllers/abstract_list_menu_view_controller.h
        view_controllers/abstract_menu_view_controller.cpp
        view_controllers/abstract_list_menu_view_controller.cpp
        view_controllers/abstract_searchable_list_menu_view_controller.cpp
        view_controllers/abstract_authed_menu_view_controller.cpp
        view_controllers/abstract_authed_menu_view_controller.h

        view_controllers/ranking_view_controller.cpp
        view_controllers/home_menu_view_controller.cpp
        view_controllers/new_game_menu_view_controller.cpp
        view_controllers/login_view_controller.cpp
        view_controllers/help_view_controller.cpp
        view_controllers/create_account_view_controller.cpp
        view_controllers/chat_room_view_controller.cpp
        view_controllers/start_view_controller.cpp
        view_controllers/game_view_controller.cpp
        view_controllers/friend_list_view_controller.cpp
        view_controllers/friend_list_view_controller.h
        view_controllers/find_friend_view_controller.cpp
        view_controllers/find_friend_view_controller.h


        views/menu_views/find_new_friend_menu_view.cpp
        views/menu_views/friend_list_menu_view.cpp
        views/menu_views/friend_list_menu_view.h
        views/menu_views/game_view.cpp
        views/menu_views/find_new_friend_menu_view.h
        views/menu_views/chat_room_menu_view.cpp
        views/menu_views/start_menu_view.cpp
        views/menu_views/create_account_menu_view.cpp
        views/menu_views/new_game_menu_view.cpp
        views/menu_views/abstract_menu_view.cpp
        views/menu_views/ranking_menu_view.cpp
        views/menu_views/login_menu_view.cpp
        views/menu_views/help_menu_view.cpp
        views/menu_views/home_menu_view.cpp

        views/menu_views/views/abstract_view.cpp
        views/menu_views/views/button.cpp
        views/menu_views/views/label.cpp
        views/menu_views/views/menu_button_item.cpp
        views/menu_views/views/first_responder.cpp
        views/menu_views/views/text_field.cpp


        ../common/models/database.cpp
        ../common/models/user/user.cpp
        ../common/models/user/message.cpp
        ../common/models/user/username.cpp
        ../common/models/user/abstract_validator.cpp
        ../common/models/board.cpp
        ../common/models/cell.cpp
        ../common/models/database.cpp
        ../common/models/Game.cpp
        ../common/models/ia.cpp
        ../common/models/input.cpp
        ../common/models/Player.cpp
        ../common/models/position.cpp
        ../common/models/translator.cpp
        view_controllers/join_or_create_game_menu_view_controller.cpp view_controllers/join_or_create_game_menu_view_controller.h views/menu_views/join_or_create_game_menu_view.cpp views/menu_views/join_or_create_game_menu_view.h view_controllers/join_game_menu_view_controller.cpp view_controllers/join_game_menu_view_controller.h views/menu_views/join_game_menu_view.cpp views/menu_views/join_game_menu_view.h)



add_executable(ClientSide ${HEADERS} ${SOURCES})
target_link_libraries(ClientSide ncurses curl pthread)

target_include_directories(ClientSide PUBLIC ${SQLite3_INCLUDE_DIRS})
target_link_libraries(ClientSide ${SQLite3_LIBRARIES})