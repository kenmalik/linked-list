cmake_minimum_required(VERSION 3.10)
project(Linked_List)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(CREATE_LINK
    "${PROJECT_BINARY_DIR}/compile_commands.json"
    "${PROJECT_SOURCE_DIR}/compile_commands.json"
    SYMBOLIC)

add_executable(Main src/main.cpp)

target_include_directories(Main PRIVATE include)

