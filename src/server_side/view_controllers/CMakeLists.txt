project(lib_viewcontroller)

set(lib_viewcontroller_source api/base_quoridor_api.cpp api/v1/v1_api.cpp)

add_library(${PROJECT_NAME} ${lib_viewcontroller_source})
