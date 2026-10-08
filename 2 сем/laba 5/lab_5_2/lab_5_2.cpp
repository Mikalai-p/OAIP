#include <iostream>
#include <string>
#include <vector>
#include "gorozhanin.h"

int main() {
    setlocale(LC_ALL, "rus");
    std::string filename = "gorozhanin.txt";
    std::vector<GorozhaninData> database;

    int choice;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Ввести данные о горожанине\n";
        std::cout << "2. Записать данные в файл\n";
        std::cout << "3. Прочитать данные из файла\n";
        std::cout << "4. Вывести данные на экран\n";
        std::cout << "5. Поиск по ФИО\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера ввода

        switch (choice) {
        case 1: {
            GorozhaninData gorozhanin = inputGorozhanin();
            database.push_back(gorozhanin);
            break;
        }
        case 2: {
            if (database.empty()) {
                std::cout << "Нет данных для записи в файл.\n";
            }
            else {
                for (const auto& gorozhanin : database) {
                    writeGorozhaninToFile(gorozhanin, filename);
                }
                std::cout << "Данные успешно записаны в файл " << filename << std::endl;
            }
            break;
        }
        case 3: {
            database = readGorozhaninFromFile(filename);
            std::cout << "Данные успешно прочитаны из файла " << filename << std::endl;
            break;
        }
        case 4: {
            if (database.empty()) {
                std::cout << "Нет данных для вывода на экран.\n";
            }
            else {
                std::cout << "Данные о горожанах:\n";
                for (const auto& gorozhanin : database) {
                    printGorozhanin(gorozhanin);
                    std::cout << std::endl;
                }
            }
            break;
        }
        case 5: {
            std::string searchFIO;
            std::cout << "Введите ФИО для поиска: ";
            std::getline(std::cin, searchFIO);
            std::vector<GorozhaninData> searchResults = searchGorozhaninByFIO(database, searchFIO);
            if (searchResults.empty()) {
                std::cout << "Ничего не найдено.\n";
            }
            else {
                std::cout << "Результаты поиска:\n";
                for (const auto& gorozhanin : searchResults) {
                    printGorozhanin(gorozhanin);
                    std::cout << std::endl;
                }
            }
            break;
        }
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}