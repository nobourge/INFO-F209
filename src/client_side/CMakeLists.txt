set(HEADERS
        view/MainMenuView.h
        view/MenuView.h
        main_menu.hpp
        client_main_controller.h
        abstract_controller.h
        client_mvc_factory.h
        enum_factory.h
        ../common/constants.h
)

set(SOURCES
        view/MainMenuView.cpp
        view/MenuView.cpp
        main_menu.cpp
        main.cpp
        client_main_controller.cpp
        abstract_controller.cpp
        client_mvc_factory.cpp

        )

add_executable(ClientSide ${HEADERS} ${SOURCES})
target_link_libraries(ClientSide ncurses)
