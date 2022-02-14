set(HEADERS
        Answer.h
        HelpMenuView.h
        MainMenuView.h
)

set(SOURCES
        Answer.cpp
        HelpMenuView.cpp
        MainMenuView.cpp
        main.cpp
)

add_executable(ClientSide ${HEADERS} ${SOURCES})
target_link_libraries(ClientSide ncurses)
