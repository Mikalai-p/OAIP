#include <iomanip>
#include <iostream>
#include <string>

int main() {
    // Установка локали
    setlocale(LC_ALL, "Rus");

    // Чтение строки
    std::string input;
    std::cout << "Введите строку: ";
    getline(std::cin, input);

    // Вывод строки с использованием манипуляторов
    for (size_t i = 0; i < input.length(); ++i) {
        std::cout << std::setw(7) << std::setfill('*') << std::left << input[i];
    }
    std::cout << "\n";

    return 0;
}
