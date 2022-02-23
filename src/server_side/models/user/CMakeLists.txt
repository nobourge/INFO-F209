project(lib_user)

set(lib_user_sources abstract_validator.cpp
                     password.cpp
                     user.cpp
                     username.cpp
                     )

add_library(lib_user ${lib_user_sources})
