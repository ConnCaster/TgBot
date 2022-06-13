#ifndef TGBOT_FS_OPERATIONS_H
#define TGBOT_FS_OPERATIONS_H

#include <iostream>
#include <filesystem>
#include <fstream>

namespace bot::fs_operations{

    std::string get_token(const std::filesystem::path& path);

}

#endif //TGBOT_FS_OPERATIONS_H
