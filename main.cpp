#include "fs_operations.h"


int main(){

    auto token = bot::fs_operations::get_token(std::filesystem::path("../TOKEN.TG"));
    if (token.empty()) {
        std::cerr << "[ERROR] token reading error";
        return 1;
    }
    std::cout << "[TOKEN]\t" << token;
    return 0;
}