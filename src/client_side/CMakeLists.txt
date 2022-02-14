set(HEADERS
        Answer.h
        view/HelpMenuView.h
        view/MainMenuView.h
        view/SelectionMenuView.h
        MainMenu.hpp
)

set(SOURCES
        Answer.cpp
        view/HelpMenuView.cpp
        view/MainMenuView.cpp
        view/SelectionMenuView.cpp
        MainMenu.cpp
        main.cpp
        Controller.cpp Controller.h)

add_executable(ClientSide ${HEADERS} ${SOURCES})
target_link_libraries(ClientSide ncurses)
