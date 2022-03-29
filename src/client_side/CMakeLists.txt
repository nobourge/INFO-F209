#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.5)

project(ClientSide)

set(CMAKE_THREAD_LIBS_INIT "-lpthread")

set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(SQLite3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

set(SOURCES
        main.cpp
        models/api_wrapper.cpp
        models/requests.cpp
        models/user_client.cpp

        view_controllers/view_controller_abstract.cpp
        view_controllers/view_controller_chat_room.cpp
        view_controllers/view_controller_create_account.cpp
        view_controllers/view_controller_find_friend.cpp
        view_controllers/view_controller_friend_list.cpp
        view_controllers/view_controller_game.cpp
        view_controllers/view_controller_help.cpp
        view_controllers/view_controller_home_menu.cpp
        view_controllers/view_controller_login.cpp
        view_controllers/view_controller_menu_abstract_authed.cpp
        view_controllers/view_controller_menu_abstract_list.cpp
        view_controllers/view_controller_menu_abstract_searchable_list.cpp
        view_controllers/view_controller_menu_abstract.cpp
        view_controllers/view_controller_menu_join_game.cpp
        view_controllers/view_controller_menu_join_or_create_game.cpp
        view_controllers/view_controller_menu_new_game.cpp
        view_controllers/view_controller_ranking.cpp
        view_controllers/view_controller_welcome.cpp

        views/menu_views/abstract_menu_view.cpp
        views/menu_views/chat_room_menu_view.cpp
        views/menu_views/create_account_menu_view.cpp
        views/menu_views/find_new_friend_menu_view.cpp
        views/menu_views/friend_list_menu_view.cpp
        views/menu_views/game_view.cpp
        views/menu_views/help_menu_view.cpp
        views/menu_views/home_menu_view.cpp
        views/menu_views/join_game_menu_view.cpp
        views/menu_views/join_or_create_game_menu_view.cpp
        views/menu_views/login_menu_view.cpp
        views/menu_views/new_game_menu_view.cpp
        views/menu_views/ranking_menu_view.cpp
        views/menu_views/start_menu_view.cpp

        views/menu_views/views/abstract_view.cpp
        views/menu_views/views/button.cpp
        views/menu_views/views/first_responder.cpp
        views/menu_views/views/label.cpp
        views/menu_views/views/menu_button_item.cpp
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

        )


#if(UNIX)
set(CMAKE_PREFIX_PATH "~/Qt/6.2.4/gcc_64/lib/cmake")
#endif ()
find_package(Qt6 CONFIG REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(QtCode)

target_link_directories(${PROJECT_NAME} PUBLIC QtCode/)
target_link_libraries(${PROJECT_NAME} menus_lib)
target_include_directories(${PROJECT_NAME} PUBLIC ${SQLite3_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SQLite3_LIBRARIES} Qt6::Core)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} ncurses curl pthread Qt6::Widgets)
else ()
    target_link_libraries(${PROJECT_NAME} ncurses curl pthread Qt6::Widgets uuid)
endif ()


