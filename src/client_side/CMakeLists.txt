set(HEADERS
        answer.h
        view/HelpMenuView.h
        view/MainMenuView.h
        main_menu.hpp
        client_main_controller.h
        abstract_controller.h
#        client_login_controller.h
#        client_login_model.hpp
        client_mvc_factory.h

)

set(SOURCES
        answer.cpp
        view/HelpMenuView.cpp
        view/MainMenuView.cpp
        main_menu.cpp
        main.cpp
        client_main_controller.cpp
        abstract_controller.cpp
#        client_login_controller.cpp
#        client_login_model.cpp
        client_mvc_factory.cpp

        )

add_executable(ClientSide ${HEADERS} ${SOURCES})
target_link_libraries(ClientSide ncurses)
