cmake_minimum_required(VERSION 3.5)

project(user_lib LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES abstract_validator.cpp
            message.cpp
            password.cpp
            user.cpp
            username.cpp)

add_library(${PROJECT_NAME} ${SOURCES})