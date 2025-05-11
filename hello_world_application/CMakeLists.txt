cmake_minimum_required(VERSION 3.4)

project(hello_world_app)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_world_app hello_world.cpp)

target_include_directories(hello_world_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(hello_world_app formatter_ex)
