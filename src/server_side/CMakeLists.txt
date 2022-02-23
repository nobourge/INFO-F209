cmake_minimum_required(VERSION 3.21)
project(Quoridor)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_THREAD_LIBS_INIT "-lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

add_subdirectory(view_controllers/)
add_subdirectory(models/)
add_subdirectory(models/user/)


if (UNIX)
    find_package(Boost REQUIRED COMPONENTS system)

    if (APPLE)
        file(GLOB OPENSSL_ROOT_DIR /opt/homebrew/Cellar/openssl@1.1/*)
        find_package(OpenSSL 1.0.2 REQUIRED)
    else ()
        find_package(OpenSSL 1.0.1 REQUIRED)
    endif ()
elseif (WIN32)
		#https://www.boost.org/doc/libs/1_49_0/more/getting_started/windows.html
		#https://slproweb.com/products/Win32OpenSSL.html

		#    set(Boost_DEBUG 1)
		#    set(Boost_COMPILER -gcc49)
		#set(Boost_INCLUDE_DIR c:/mingw/include/)
		#set(Boost_LIBRARY_DIR c:/mingw/lib/)
		#find_package(Boost COMPONENTS system filesystem REQUIRED)
		#include_directories(${Boost_INCLUDE_DIR})
		#    find_package(Boost REQUIRED COMPONENTS system)

				find_package(OpenSSL 1.0.1 REQUIRED)
		else ()
		    message(FATAL_ERROR "unsupported platform")
endif ()

add_executable(QuoridorServer main.cpp)

find_package(SQLite3)

target_include_directories(QuoridorServer PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(QuoridorServer PUBLIC ${SQLite3_INCLUDE_DIRS})
target_link_libraries(QuoridorServer ${Boost_LIBRARIES} OpenSSL::SSL
											lib_viewcontroller
											lib_models
											lib_user
											${SQLite3_LIBRARIES})
