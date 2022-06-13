#include "fs_operations.h"
#include <tgbot/tgbot.h>
#include <chrono>

int main(){

    auto token = bot::fs_operations::get_token(std::filesystem::path("../TOKEN.TG"));
    if (token.empty()) {
        std::cerr << "[ERROR] token reading error";
        return 1;
    }
    std::cout << "[TOKEN]\t" << token << std::endl;
    TgBot::Bot bot(token);

    bot.getEvents().onCommand("hello", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi! " + message->chat->username);
    });

    bot.getEvents().onCommand("date", [&bot](TgBot::Message::Ptr message) {
        auto time_now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string time{ctime(&time_now)};
        bot.getApi().sendMessage(message->chat->id, time);
    });

//    bot.getEvents().onCommand("sticker", [&bot](TgBot::Message::Ptr message) {
//        auto time_now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
//        std::string time{ctime(&time_now)};
//        bot.getApi().;
//    });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }

    return 0;
}