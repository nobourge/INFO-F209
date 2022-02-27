

if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I /usr/local/lib/boost_1_78_0")
endif ()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")


set(HEADERS
        view_controllers/menu_view_controller.h
        view_controllers/home_menu_view_controller.h
        view_controllers/ranking_view_controller.h
        view_controllers/abstract_view_controller.h
        view_controllers/login_view_controller.h
        view_controllers/create_account_view_controller.h
        view_controllers/start_view_controller.h
        view_controllers/selection_menu_view_controller.h
        view_controllers/chat_room_view_controller.h
        views/menu_views/chat_room_menu_view.h
        views/menu_views/help_menu_view.h
        views/menu_views/selection_menu_view.h
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
        view_controllers/help_view_controller.h
        views/menu_views/views/text_field.h
        models/ranking.h
        models/api_wrapper.h
        models/requests.h
        client_mvc_factory.h

        ../server_side/models/database.h

        ../common/constants.h
        ../common/models/user/user.h
        ../common/models/user/username.h
        ../common/models/serializable.h
        ../common/models/user/abstract_validator.h
        )

set(SOURCES
        main.cpp
        view_controllers/home_menu_view_controller.cpp
        view_controllers/abstract_view_controller.cpp
        view_controllers/ranking_view_controller.cpp
        view_controllers/menu_view_controller.cpp
        view_controllers/selection_menu_view_controller.cpp
        view_controllers/login_view_controller.cpp
        view_controllers/help_view_controller.cpp
        view_controllers/create_account_view_controller.cpp
        view_controllers/chat_room_view_controller.cpp
        view_controllers/start_view_controller.cpp



        views/menu_views/chat_room_menu_view.cpp
        views/menu_views/start_menu_view.cpp
        views/menu_views/views/menu_button_item.cpp
        views/menu_views/views/first_responder.cpp
        views/menu_views/create_account_menu_view.cpp
        views/menu_views/views/abstract_view.cpp
        views/menu_views/selection_menu_view.cpp
        views/menu_views/abstract_menu_view.cpp
        views/menu_views/ranking_menu_view.cpp
        views/menu_views/views/text_field.cpp
        views/menu_views/login_menu_view.cpp
        views/menu_views/help_menu_view.cpp
        views/menu_views/home_menu_view.cpp
        views/menu_views/views/button.cpp
        views/menu_views/views/label.cpp

        models/ranking.cpp
        models/api_wrapper.cpp
        models/requests.cpp

        ../server_side/models/database.cpp

        ../common/models/user/user.cpp
        ../common/models/user/username.cpp
        ../common/models/user/abstract_validator.cpp
        )



add_executable(ClientSide ${HEADERS} ${SOURCES})
target_link_libraries(ClientSide ncurses curl pthread)

target_include_directories(ClientSide PUBLIC ${SQLite3_INCLUDE_DIRS})
target_link_libraries(ClientSide ${SQLite3_LIBRARIES})