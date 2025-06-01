#include <fstream>
#include <cstdlib>
#include "formatter_ex.h"

int main() {
    const char* log_path = std::getenv("LOG_PATH");
    if (!log_path) {
        std::cerr << "LOG_PATH not set!" << std::endl;
        return 1;
    }

    std::ofstream log_file(log_path, std::ios::app);
    if (!log_file.is_open()) {
        std::cerr << "Failed to open log file!" << std::endl;
        return 1;
    }

    formatter(log_file, "hello, world!");
    log_file.close();
    return 0;
}
