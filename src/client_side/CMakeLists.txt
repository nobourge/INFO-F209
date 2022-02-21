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

)

set(SOURCES
#        answer.cpp
        views/menu_views/help_menu_view.cpp
        views/menu_views/home_menu_view.cpp
        views/main_menu.cpp
        views/menu_views/abstract_menu_view.cpp
        main.cpp
        view_controllers/home_menu_view_controller.cpp
        view_controllers/abstract_view_controller.cpp
#        client_login_controller.cpp
#        client_login_model.cpp
        client_mvc_factory.cpp

        views/menu_views/login_menu_view.cpp views/menu_views/login_menu_view.h views/view_elements/button.cpp views/view_elements/button.h)

add_executable(ClientSide ${HEADERS} ${SOURCES})
target_link_libraries(ClientSide ncurses)
