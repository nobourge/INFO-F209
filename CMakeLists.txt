cmake_minimum_required(VERSION 3.11)
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
        src/common/models/board.cpp
        src/common/models/cell.cpp
        src/common/models/database.cpp
        src/common/models/Game.cpp
        src/common/models/ia.cpp
        src/common/models/input.cpp
        src/common/models/input.cpp
        src/common/models/Player.cpp
        src/common/models/position.cpp
        src/common/models/translator.cpp

        src/common/models/user/abstract_validator.cpp
        src/common/models/user/message.cpp
        src/common/models/user/password.cpp
        src/common/models/user/user.cpp
        src/common/models/user/username.cpp

        src/server_side/view_controllers/api/base_quoridor_api.cpp
        src/server_side/view_controllers/api/v1/v1_api.cpp
        src/common/models/user_server.cpp
        src/common/models/user_server.h
        src/server_side/views/views.cpp
        src/server_side/views/views.h
        src/server_side/utils.h
        )


target_include_directories(QuoridorServer PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(QuoridorServer PUBLIC ${SQLite3_INCLUDE_DIRS})

if (APPLE)
    target_link_libraries(QuoridorServer ${Boost_LIBRARIES} OpenSSL::SSL ${SQLite3_LIBRARIES})
else ()
    target_link_libraries(QuoridorServer ${Boost_LIBRARIES} OpenSSL::SSL ${SQLite3_LIBRARIES} uuid)
endif ()


#[[

#conan cmakelists:
cmake_minimum_required(VERSION 3.11)
project(Quoridor)

set(CMAKE_CXX_STANDARD 20)
set(CONAN_CMAKE_CXX_STANDARD 20)
set(CONAN_DISABLE_CHECK_COMPILER true)
message(STATUS "CONAN_DISABLE_CHECK_COMPILER")

set(CMAKE_THREAD_LIBS_INIT "-lpthread")

set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

# Download automatic conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES
        boost/1.73.0
        openssl/3.0.1
        crow/0.1
        #sqlite3/3.34.1
        #libcurl/7.80.0
        ncurses/6.3
        qt/6.2.4

        GENERATORS cmake_find_package)

#conan_cmake_autodetect(settings)

###conan install : Installs the requirements specified in a recipe (conanfile.py or conanfile.txt).
###conan_cmake_install is a wrapper for conan install
conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        #SETTINGS ${settings}
        )

#set(CMAKE_MODULE_PATH ~/Github/conan-test/cmake-build-debug)

add_subdirectory(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(QuoridorServer
        src/server_side/main.cpp
        src/common/models/board.cpp
        src/common/models/cell.cpp
        src/common/models/database.cpp
        src/common/models/Game.cpp
        src/common/models/ia.cpp
        src/common/models/input.cpp
        src/common/models/input.cpp
        src/common/models/Player.cpp
        src/common/models/position.cpp
        src/common/models/translator.cpp

        src/common/models/user/abstract_validator.cpp
        src/common/models/user/message.cpp
        src/common/models/user/password.cpp
        src/common/models/user/user.cpp
        src/common/models/user/username.cpp

        src/server_side/view_controllers/api/base_quoridor_api.cpp
        src/server_side/view_controllers/api/v1/v1_api.cpp
        src/common/models/user_server.cpp
        src/common/models/user_server.h
        src/server_side/views/views.cpp
        src/server_side/views/views.h
        src/server_side/utils.h
        )


target_include_directories(QuoridorServer PUBLIC ${CONAN_DIRS})

if (APPLE)
    target_link_libraries(QuoridorServer ${CONAN_LIBS})
else ()
    #target_link_libraries(QuoridorServer ${Boost_LIBRARIES} OpenSSL::SSL ${SQLite3_LIBRARIES} uuid)
    target_link_libraries(QuoridorServer ${CONAN_LIBS} uuid sqlite3)
endif ()
]]