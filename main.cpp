#include "fs_operations.h"
#include <tgbot/tgbot.h>
#include <chrono>
#include <random>

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

    bot.getEvents().onCommand("hasbik", [&bot](TgBot::Message::Ptr message) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, 120);
        std::cout << dist(mt) << std::endl;
        std::string sticker_path = "/home/user/dir/programming/C++/TgBot/media/hasbullaking/webp/hasbik_" + std::to_string(dist(mt)) + ".webp";
        std::cout << sticker_path << std::endl;
        bot.getApi().sendSticker(message->chat->id, TgBot::InputFile::fromFile(sticker_path, "image/webp"));
    });

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