set(HEADERS
        answer.h
        view/HelpMenuView.h
        view/MainMenuView.h
        view/SelectionMenuView.h
        main_menu.hpp
)

set(SOURCES
        answer.cpp
        view/HelpMenuView.cpp
        view/MainMenuView.cpp
        view/SelectionMenuView.cpp
        main_menu.cpp
        main.cpp
        client_main_controller.cpp client_main_controller.h)

add_executable(ClientSide ${HEADERS} ${SOURCES})
target_link_libraries(ClientSide ncurses)
