#include "fs_operations.h"

namespace bot::fs_operations {

    std::string get_token(const std::filesystem::path &path) {
        std::ifstream token_stream(path);
        std::string token_tg{};
        if (token_stream.is_open())
            token_stream >> token_tg;
        return token_tg;
    }
}