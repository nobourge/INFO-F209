cmake_minimum_required(VERSION 3.16)
project(Quoridor)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_THREAD_LIBS_INIT "-lpthread")

set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(SQLite3)

add_subdirectory(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

if (UNIX)
    find_package(Boost REQUIRED COMPONENTS system)
    find_package(Boost REQUIRED COMPONENTS regex)

    if (APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I /usr/local/lib/boost_1_78_0")
        file(GLOB OPENSSL_ROOT_DIR /opt/homebrew/Cellar/openssl@1.1/*)
        find_package(OpenSSL 1.0.2 REQUIRED)
    else ()
        find_package(OpenSSL 1.0.1 REQUIRED)
    endif ()

elseif (WIN32)
    find_package(OpenSSL 1.0.1 REQUIRED)
else ()
    message(FATAL_ERROR "unsupported platform")
endif ()


add_executable(QuoridorServer
        src/server_side/main.cpp
        src/server_side/models/board.cpp
        src/server_side/models/cell.cpp
        src/server_side/models/database.cpp
        src/server_side/models/Game.cpp
        src/server_side/models/ia.cpp
        src/server_side/models/input.cpp
        src/server_side/models/input.cpp
        src/server_side/models/Player.cpp
        src/server_side/models/position.cpp
        src/server_side/models/translator.cpp

        src/common/models/user/abstract_validator.cpp
        src/common/models/user/message.cpp
        src/common/models/user/password.cpp
        src/common/models/user/user.cpp
        src/common/models/user/username.cpp

        src/server_side/view_controllers/api/base_quoridor_api.cpp
        src/server_side/view_controllers/api/v1/v1_api.cpp
        src/server_side/models/server_side_user.cpp src/server_side/models/server_side_user.h)


target_include_directories(QuoridorServer PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(QuoridorServer PUBLIC ${SQLite3_INCLUDE_DIRS})
target_link_libraries(QuoridorServer ${Boost_LIBRARIES} OpenSSL::SSL ${SQLite3_LIBRARIES})
