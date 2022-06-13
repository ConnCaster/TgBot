#include "fs_operations.h"
#include <tgbot/tgbot.h>

int main(){

    auto token = bot::fs_operations::get_token(std::filesystem::path("../TOKEN.TG"));
    if (token.empty()) {
        std::cerr << "[ERROR] token reading error";
        return 1;
    }
    std::cout << "[TOKEN]\t" << token;
//    TgBot::Bot bot(token);
    return 0;
}