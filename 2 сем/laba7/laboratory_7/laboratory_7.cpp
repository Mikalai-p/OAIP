#include "stack.h"
#include <iostream>

void showMenu() {
    setlocale(LC_ALL, "rus");
    std::cout << "Меню:\n";
    std::cout << "1. Добавить элемент (Push)\n";
    std::cout << "2. Удалить элемент (Pop)\n";
    std::cout << "3. Показать верхний элемент (Top)\n";
    std::cout << "4. Проверить, пуст ли стек (IsEmpty)\n";
    std::cout << "5. Очистить стек (Clear)\n";
    std::cout << "6. Сохранить стек в файл (Save)\n";
    std::cout << "7. Загрузить стек из файла (Load)\n";
    std::cout << "8. Проверить элементы в диапазоне (Check Range)\n";
    std::cout << "9. Выход\n";
}

int main() {
    setlocale(LC_ALL, "rus");
    Stack stack;
    int choice;

    do {
        showMenu();
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        try {
            switch (choice) {
            case 1: {
                double value;
                std::cout << "Введите значение: ";
                std::cin >> value;
                stack.push(value);
                break;
            }
            case 2: {
                std::cout << "Удалённое значение: " << stack.pop() << "\n";
                break;
            }
            case 3: {
                std::cout << "Верхний элемент: " << stack.top() << "\n";
                break;
            }
            case 4: {
                std::cout << (stack.isEmpty() ? "Стек пуст." : "Стек не пуст.") << "\n";
                break;
            }
            case 5: {
                stack.clear();
                std::cout << "Стек очищен.\n";
                break;
            }
            case 6: {
                std::string filename;
                std::cout << "Введите имя файла для сохранения: ";
                std::cin >> filename;
                stack.saveToFile(filename);
                std::cout << "Стек сохранён.\n";
                break;
            }
            case 7: {
                std::string filename;
                std::cout << "Введите имя файла для загрузки: ";
                std::cin >> filename;
                stack.loadFromFile(filename);
                std::cout << "Стек загружен.\n";
                break;
            }
            case 8: {
                double lower, upper;
                std::cout << "Введите нижнюю границу: ";
                std::cin >> lower;
                std::cout << "Введите верхнюю границу: ";
                std::cin >> upper;
                if (stack.hasElementInRange(lower, upper)) {
                    std::cout << "Есть элемент в диапазоне.\n";
                }
                else {
                    std::cout << "Элементов в диапазоне нет.\n";
                }
                break;
            }
            case 9:
                std::cout << "Выход...\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << "\n";
        }
    } while (choice != 9);

    return 0;
}
