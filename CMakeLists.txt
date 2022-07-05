cmake_minimum_required(VERSION 3.22)
project(TelegramBot)

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_MULTITHREADED ON)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)

if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()

add_executable(TelegramBot main.cpp src/fs_operations.cpp)
target_include_directories(TelegramBot PUBLIC includes 3rd_party/tgbot_lib/include)
find_library(TG_BOT_LIB TgBot 3rd_party/tgbot_lib/lib)
target_link_libraries(TelegramBot ${TG_BOT_LIB} ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES})
