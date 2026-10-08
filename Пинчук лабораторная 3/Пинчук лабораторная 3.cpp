#include <iostream> 
#include <cmath>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    setlocale(LC_ALL, "Rus");
    constexpr int precision = 6; // Количество знаков после запятой
    constexpr int width = 10; // Ширина поля для вывода чисел

    double a = 1.5, x = -1.8, z = 15e-9, w, d;

    std::cout << std::fixed << std::setprecision(precision) << std::showpoint;

    std::cout << "Введите значение переменной x: ";
    std::cin >> x;

    w = tan(1.0) * (1 + x) + z - exp(a);
    d = 9 * sqrt(2 - 3 * x) + abs(a + 1);

    std::cout << std::setw(width) << "w =" << std::setw(width) << w << std::endl;
    std::cout << std::setw(width) << "d =" << std::setw(width) << d << std::endl;

    return 0;
}
