#include "solver.h"
#include <cmath>
#include <stdexcept>
#include <iostream> // Добавлено

void solve(float a, float b, float c, float& x1, float& x2)
{
    if (a == 0) {
        throw std::logic_error{"error: a cannot be zero"};
    }

    float d = (b * b) - (4 * a * c);
    std::cout << "Дискриминант: " << d << std::endl; // Отладочный вывод

    if (d < 0)
    {
        throw std::logic_error{"error: discriminant < 0"};
    }

    x1 = (-b - sqrtf(d)) / (2 * a);
    x2 = (-b + sqrtf(d)) / (2 * a);

    std::cout << "Вычисленные корни: x1=" << x1 << ", x2=" << x2 << std::endl;
}
