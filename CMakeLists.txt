cmake_minimum_required(VERSION 3.22)
project(TgBot)

set(CMAKE_CXX_STANDARD 20)

add_executable(TgBot main.cpp src/fs_operations.cpp)
target_include_directories(TgBot PUBLIC includes)
target_link_libraries(TgBot PUBLIC -lstdc++fs)