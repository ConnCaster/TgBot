cmake_minimum_required(VERSION 3.22)
project(TelegramBot)

set(CMAKE_CXX_STANDARD 20)

add_executable(TelegramBot main.cpp src/fs_operations.cpp)
target_include_directories(TelegramBot PUBLIC includes 3rd_party/tgbot_lib/include)
find_library(TG_BOT_LIB TgBot 3rd_party/tgbot_lib/lib)
target_link_libraries(TelegramBot ${TG_BOT_LIB})
