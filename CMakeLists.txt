cmake_minimum_required(VERSION 3.22.1)

project(yajp)


add_compile_options(-Wall -Wextra -Wpedantic -g)

file(GLOB YAJP_SRC
    ${PROJECT_SOURCE_DIR}/*.cpp)

include_directories(${PROJECT_SOURCE_DIR})


add_executable(${PROJECT_NAME} ${YAJP_SRC})

