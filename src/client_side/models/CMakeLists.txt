#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.5)

project(ClientSide)

set(SOURCES
        main.cpp

        models/api_wrapper.cpp
        models/requests.cpp
        models/user_client.cpp

        )


#if(UNIX)
set(CMAKE_PREFIX_PATH "~/Qt/6.2.4/gcc_64/lib/cmake")
#endif ()
find_package(Qt6 CONFIG REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(QtCode)
add_subdirectory(../common/models ${CMAKE_CURRENT_BINARY_DIR}/quoridor_game_lib)

target_link_directories(${PROJECT_NAME} PUBLIC QtCode/)
target_link_directories(${PROJECT_NAME} PUBLIC ../common/models/)
target_link_libraries(${PROJECT_NAME} menus_lib)
target_link_libraries(${PROJECT_NAME} quoridor_lib)
target_link_libraries(${PROJECT_NAME} Qt6::Core)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} ncurses curl pthread Qt6::Widgets)
else ()
    target_link_libraries(${PROJECT_NAME} ncurses curl pthread Qt6::Widgets uuid)
endif ()