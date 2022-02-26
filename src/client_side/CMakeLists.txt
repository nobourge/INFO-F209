if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I /usr/local/lib/boost_1_78_0")
else ()
    target_include_directories(QuoridorServer PUBLIC ${Boost_INCLUDE_DIRS})
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcurl")


set(HEADERS
        view_controllers/menu_view_controller.h
        view_controllers/home_menu_view_controller.h
        view_controllers/ranking_view_controller.h
        view_controllers/abstract_view_controller.h
        view_controllers/login_view_controller.h
        view_controllers/selection_menu_view_controller.h
        views/menu_views/help_menu_view.h
        views/menu_views/selection_menu_view.h
        views/menu_views/home_menu_view.h
        views/menu_views/ranking_menu_view.h
        client_mvc_factory.h
        ../common/constants.h
        )

set(SOURCES
        main.cpp
        view_controllers/home_menu_view_controller.cpp
        view_controllers/abstract_view_controller.cpp
        view_controllers/ranking_view_controller.cpp
        view_controllers/menu_view_controller.cpp
        view_controllers/selection_menu_view_controller.cpp
        view_controllers/login_view_controller.cpp
        views/menu_views/help_menu_view.cpp
        views/menu_views/home_menu_view.cpp
        views/menu_views/ranking_menu_view.cpp
        views/menu_views/abstract_menu_view.cpp
        views/menu_views/login_menu_view.cpp
        views/menu_views/login_menu_view.h
        views/menu_views/selection_menu_view.cpp
        views/menu_views/views/button.cpp
        views/menu_views/views/button.h
        views/menu_views/views/abstract_view.cpp
        views/menu_views/views/abstract_view.h
        views/menu_views/views/first_responder.cpp
        views/menu_views/views/first_responder.h
        views/menu_views/views/label.cpp
        views/menu_views/views/label.h
        views/menu_views/views/menu_button_item.cpp
        views/menu_views/views/menu_button_item.h
        view_controllers/help_view_controller.cpp
        view_controllers/help_view_controller.h
        views/menu_views/views/text_field.cpp
        views/menu_views/views/text_field.h
        models/ranking.cpp models/ranking.h)

add_executable(ClientSide ${HEADERS} ${SOURCES})
target_link_libraries(ClientSide ncurses)
