#ifndef GOROZHANIN_H
#define GOROZHANIN_H

#include <string>
#include <vector>
#include <fstream>
#include <regex>

// Структура для хранения информации о человеке
struct Person {
    std::string fio;
    std::string birthday; 
    std::string address; 
    char gender;       
};

// Объединение для представления данных
union Data {
    Person person;       
    std::string searchKey; 
    Data();
    ~Data() {}
    Data& operator=(const Data& other);
    Data(const Data& other);
};

struct GorozhaninData {
    Data data;          // Данные (либо Person, либо searchKey)
    GorozhaninData();
    ~GorozhaninData();   // Явный деструктор
    GorozhaninData(const GorozhaninData& other); // Копирующий конструктор
    GorozhaninData& operator=(const GorozhaninData& other); // Оператор присваивания копированием
};
// Function prototypes
GorozhaninData inputGorozhanin();
void writeGorozhaninToFile(const GorozhaninData& gorozhanin, const std::string& filename);
std::vector<GorozhaninData> readGorozhaninFromFile(const std::string& filename);
void printGorozhanin(const GorozhaninData& gorozhanin);
std::vector<GorozhaninData> searchGorozhaninByFIO(const std::vector<GorozhaninData>& data, const std::string& fio);

// Validation function prototypes
bool isValidFIO(const std::string& fio, std::string& errorMessage);
bool isValidBirthday(const std::string& birthday, std::string& errorMessage);
bool isValidAddress(const std::string& address, std::string& errorMessage);

#endif // GOROZHANIN_H