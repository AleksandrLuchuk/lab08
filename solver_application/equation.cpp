#include <fstream>
#include <cstdlib>
#include <iostream> // Добавлено
#include "formatter_ex.h"
#include "solver.h"

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

    float a, b, c;
    std::cout << "Введите коэффициенты a, b, c: "; // Отладочный вывод
    std::cin >> a >> b >> c;

    if(std::cin.fail()) {
        formatter(log_file, "Ошибка: неверный формат коэффициентов");
        std::cerr << "Ошибка чтения коэффициентов!" << std::endl;
        return 1;
    }
    
    formatter(log_file, "Уравнение: " + std::to_string(a) + "x² + " + 
                        std::to_string(b) + "x + " + std::to_string(c) + " = 0");

    float x1 = 0, x2 = 0;

    try {
        solve(a, b, c, x1, x2);
        formatter(log_file, "x1 = " + std::to_string(x1));
        formatter(log_file, "x2 = " + std::to_string(x2));
    } catch (const std::logic_error& ex) {
        formatter(log_file, ex.what());
    }

    log_file.close();
    return 0;
}
