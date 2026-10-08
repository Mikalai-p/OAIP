#include "gorozhanin.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <cctype>
#include <regex>

// Валидация для ФИО (фамилия, имя, отчество)
bool isValidFIO(const std::string& fio, std::string& errorMessage) {
    std::regex pattern(R"(^([A-Za-z]+(-[A-Za-z]+){0,1})\s+([A-Za-z]+(-[A-Za-z]+){0,1})\s+([A-Za-z]+)$)");
    std::smatch match;

    if (!std::regex_match(fio, match, pattern)) {
        errorMessage = "Некорректный формат ФИО.  Фамилия и имя: максимум два слова через дефис (только буквы). Отчество: одно слово (только буквы). Дефис в конце слова недопустим.";
        return false;
    }

    return true;
}

bool isLeapYear(int year) {
    // Високосный год делится на 4, но не делится на 100,
    // или делится на 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDay(int day, int month, int year) {
    if (month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // Индексы начинаются с 1
    if (isLeapYear(year)) {
        daysInMonth[2] = 29; // Февраль в високосный год
    }

    return day <= daysInMonth[month];
}

// Валидация для даты рождения (ДДММГГГГ)
bool isValidBirthday(const std::string& birthday, std::string& errorMessage) {
    std::regex pattern(R"(^\d{2}\d{2}\d{4}$)");

    if (!std::regex_match(birthday, pattern)) {
        errorMessage = "Некорректный формат даты рождения. Используйте формат ДДММГГГГ (только цифры).";
        return false;
    }

    // Преобразование строки в числа
    int day, month, year;
    try {
        day = std::stoi(birthday.substr(0, 2)); // Извлекаем день
        month = std::stoi(birthday.substr(2, 2)); // Извлекаем месяц
        year = std::stoi(birthday.substr(4, 4)); // Извлекаем год
    }
    catch (const std::invalid_argument& e) {
        errorMessage = "Ошибка преобразования даты рождения.";
        return false;
    }
    catch (const std::out_of_range& e) {
        errorMessage = "Слишком большая дата рождения.";
        return false;
    }

    if (!isValidDay(day, month, year)) {
        errorMessage = "Некорректная дата рождения.";
        return false;
    }

    return true;
}

// Валидация для адреса (город улица номер дома)
bool isValidAddress(const std::string& address, std::string& errorMessage) {
    std::regex pattern(R"(^([A-Za-z]+(-[A-Za-z]+){0,2})\s+([A-Za-z]+(-[A-Za-z]+){0,2})\s+(\d+(-\d+)?)$)");
    std::smatch match;

    if (!std::regex_match(address, match, pattern)) {
        errorMessage = "Некорректный формат адреса.  Город и улица: максимум три слова через дефис (только буквы). Номер дома: только цифры (возможна запись в формате нн-кк). Дефис в конце слова в городе и улице недопустим.";
        return false;
    }

    return true;
}

// Функция для ввода данных о горожанине (с проверкой и перевводом)
GorozhaninData inputGorozhanin() {
    GorozhaninData gorozhanin;
    std::string errorMessage;

    gorozhanin.data.person.fio = "";
    gorozhanin.data.person.birthday = "";
    gorozhanin.data.person.address = "";
    gorozhanin.data.person.gender = ' ';

    do {
        std::cout << "Введите ФИО: ";
        std::getline(std::cin >> std::ws, gorozhanin.data.person.fio);
        if (!isValidFIO(gorozhanin.data.person.fio, errorMessage)) {
            std::cout << errorMessage << std::endl;
        }
    } while (!isValidFIO(gorozhanin.data.person.fio, errorMessage));

    do {
        std::cout << "Введите дату рождения (ДДММГГГГ): ";
        std::getline(std::cin >> std::ws, gorozhanin.data.person.birthday);
        if (!isValidBirthday(gorozhanin.data.person.birthday, errorMessage)) {
            std::cout << errorMessage << std::endl;
        }
    } while (!isValidBirthday(gorozhanin.data.person.birthday, errorMessage));

    do {
        std::cout << "Введите адрес (город улица номер дома): ";
        std::getline(std::cin >> std::ws, gorozhanin.data.person.address);
        if (!isValidAddress(gorozhanin.data.person.address, errorMessage)) {
            std::cout << errorMessage << std::endl;
        }
    } while (!isValidAddress(gorozhanin.data.person.address, errorMessage));

    char gender;
    do {
        std::cout << "Введите пол (m/f): ";
        std::cin >> gender;
        gender = std::tolower(gender);
        if (gender != 'm' && gender != 'f') {
            std::cout << "Некорректный пол. Введите 'm' или 'f'.\n";
        }
    } while (gender != 'm' && gender != 'f');
    gorozhanin.data.person.gender = gender;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера

    return gorozhanin;
}

// Функция для записи данных о горожанине в файл
void writeGorozhaninToFile(const GorozhaninData& gorozhanin, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Открываем файл для добавления в конец
    if (file.is_open()) {
        file << gorozhanin.data.person.fio << std::endl;
        file << gorozhanin.data.person.birthday << std::endl;
        file << gorozhanin.data.person.address << std::endl;
        file << gorozhanin.data.person.gender << std::endl;

        file.close();
    }
    else {
        std::cerr << "Не удалось открыть файл для записи: " << filename << std::endl;
    }
}

// Функция для чтения данных о горожанине из файла
std::vector<GorozhaninData> readGorozhaninFromFile(const std::string& filename) {
    std::vector<GorozhaninData> data;
    std::ifstream file(filename);
    if (file.is_open()) {
        while (file.peek() != EOF) {
            GorozhaninData gorozhanin;

            std::getline(file >> std::ws, gorozhanin.data.person.fio);
            if (file.eof()) break;
            std::getline(file >> std::ws, gorozhanin.data.person.birthday);
            if (file.eof()) break;
            std::getline(file >> std::ws, gorozhanin.data.person.address);
            if (file.eof()) break;
            file >> gorozhanin.data.person.gender;
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (file.eof()) break;

            data.push_back(gorozhanin);
        }
        file.close();
    }
    else {
        std::cerr << "Не удалось открыть файл для чтения: " << filename << std::endl;
    }
    return data;
}

// Функция для вывода данных о горожанине на экран
void printGorozhanin(const GorozhaninData& gorozhanin) {
    std::cout << "ФИО: " << gorozhanin.data.person.fio << std::endl;
    std::cout << "Дата рождения: " << gorozhanin.data.person.birthday << std::endl;
    std::cout << "Адрес: " << gorozhanin.data.person.address << std::endl;
    std::cout << "Пол: " << gorozhanin.data.person.gender << std::endl;
}

// Функция для поиска горожан по ФИО
std::vector<GorozhaninData> searchGorozhaninByFIO(const std::vector<GorozhaninData>& data, const std::string& fio) {
    std::vector<GorozhaninData> results;
    for (const auto& gorozhanin : data) {
        if (gorozhanin.data.person.fio.find(fio) != std::string::npos) {
            results.push_back(gorozhanin);
        }
    }
    return results;
}

Data::Data() : person{ {}, {}, {}, ' ' } {}

Data& Data::operator=(const Data& other) {
    person = other.person;
    searchKey = other.searchKey; // Deep copy of searchKey
    return *this;
}

Data::Data(const Data& other) : person(other.person) {  }

GorozhaninData::GorozhaninData() {}
GorozhaninData::~GorozhaninData() {}

GorozhaninData::GorozhaninData(const GorozhaninData& other) : data(other.data) {}

GorozhaninData& GorozhaninData::operator=(const GorozhaninData& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}