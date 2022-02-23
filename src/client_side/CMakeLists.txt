set(HEADERS
#        answer.h
        views/menu_views/help_menu_view.h
        views/menu_views/home_menu_view.h
#        views/main_menu.hpp
        view_controllers/home_menu_view_controller.h
        view_controllers/abstract_view_controller.h
#        client_login_controller.h
#        client_login_model.hpp
        client_mvc_factory.h
        ../common/constants.h
)

set(SOURCES
        views/menu_views/help_menu_view.cpp
        views/menu_views/home_menu_view.cpp
        views/menu_views/abstract_menu_view.cpp
        main.cpp
        view_controllers/home_menu_view_controller.cpp
        view_controllers/abstract_view_controller.cpp
#        client_login_controller.cpp
#        client_login_model.cpp
#        client_mvc_factory.cpp

        views/menu_views/login_menu_view.cpp
        views/menu_views/login_menu_view.h
        views/menu_views/views/button.cpp
        views/menu_views/views/button.h
        view_controllers/menu_view_controller.cpp
        view_controllers/menu_view_controller.h
        views/menu_views/views/abstract_view.cpp views/menu_views/views/abstract_view.h views/menu_views/views/first_responder.cpp views/menu_views/views/first_responder.h views/menu_views/views/label.cpp views/menu_views/views/label.h views/menu_views/views/menu_button_item.cpp views/menu_views/views/menu_button_item.h view_controllers/help_view_controller.cpp view_controllers/help_view_controller.h views/menu_views/views/text_field.cpp views/menu_views/views/text_field.h)

add_executable(ClientSide ${HEADERS} ${SOURCES})
target_link_libraries(ClientSide ncurses)
