cmake_minimum_required(VERSION 3.5)

project(menus_lib LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "~/Qt/6.2.4/gcc_64/lib/cmake")
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(SOURCES board_scene.cpp
            main.cpp
            mainmenuview.ui
            mainmenuview.cpp
            mainmenuview.h
            )

add_library(${PROJECT_NAME} ${SOURCES})

add_subdirectory(game)

target_include_directories(${PROJECT_NAME} PUBLIC game/)
target_link_directories(${PROJECT_NAME} PUBLIC game/)
target_link_libraries(${PROJECT_NAME} game_menu_lib)
target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets)
