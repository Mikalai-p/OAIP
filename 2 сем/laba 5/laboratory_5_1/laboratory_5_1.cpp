#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <stdexcept>

#ifdef _WIN32

#else
#include <locale>
#endif

using namespace std;

#define SIZE 4


enum class FormOfGovernment {
    MONARCHY,
    REPUBLIC,
    OTHER
};


string formOfGovernmentToString(FormOfGovernment form) {
    switch (form) {
    case FormOfGovernment::MONARCHY:   return "Монархия";
    case FormOfGovernment::REPUBLIC:  return "Республика";
    case FormOfGovernment::OTHER:     return "Другая";
    default:                         return "Неизвестно";
    }
}


string inputOtherFormOfGovernment() {
    string input;
    cout << "Введите форму правления (одно слово или два слова через дефис): ";
    getline(cin, input);

    int wordCount = 0;
    stringstream ss(input);
    string word;
    while (ss >> word) {
        wordCount++;
    }

    if (wordCount == 1 || (wordCount == 2 && input.find('-') != string::npos)) {
        return input;
    }
    else {
        cout << "Некорректный ввод. Допускается одно слово или два слова через дефис.\n";
        return inputOtherFormOfGovernment();
    }
}


FormOfGovernment inputFormOfGovernment(string& otherForm) {
    int choice;
    string input;

    cout << "Выберите форму правления:\n";
    cout << "1. Монархия\n";
    cout << "2. Республика\n";
    cout << "3. Другая\n";

    while (true) {
        cout << "Ваш выбор: ";
        getline(cin, input);

        stringstream ss(input);
        if (ss >> choice) {

            if (ss.eof()) {
                switch (choice) {
                case 1: return FormOfGovernment::MONARCHY;
                case 2: return FormOfGovernment::REPUBLIC;
                case 3:
                    otherForm = inputOtherFormOfGovernment();
                    return FormOfGovernment::OTHER;
                default: cout << "Неверный ввод. Пожалуйста, выберите от 1 до 3.\n";
                }
            }
            else {
                cout << "Неверный ввод. Введите только одну цифру (1-3).\n";
            }
        }
        else {
            cout << "Неверный ввод. Пожалуйста, введите число.\n";
        }
    }
}


struct State {
    string name;
    string capital;
    long long population:34;
    double area;
    FormOfGovernment governmentForm;
    string otherForm;
};

// Валидация наименования государства
bool isValidName(const string& name) {
    int wordCount = 0;
    stringstream ss(name);
    string word;
    while (ss >> word) {
        wordCount++;
    }

    if (wordCount > 3) return false;

    for (char c : name) {
        if (!isalpha(c) && c != ' ' && c != '-')
            return false;
    }
    int spaceCount = 0;
    int hyphenCount = 0;
    for (char c : name) {
        if (c == ' ')
            spaceCount++;
        if (c == '-')
            hyphenCount++;
    }

    if (spaceCount > 2) return false;
    if (hyphenCount > 2) return false;

    if (spaceCount != 0 && hyphenCount != 0) return false;

    return true;
}

// Валидация столицы государства
bool isValidCapital(const string& capital, const string& stateName, const vector<State>& states) {
    int wordCount = 0;
    stringstream ss(capital);
    string word;
    while (ss >> word) {
        wordCount++;
    }

    if (wordCount > 3) return false;

    for (char c : capital) {
        if (!isalpha(c) && c != ' ' && c != '-')
            return false;
    }
    int spaceCount = 0;
    int hyphenCount = 0;
    for (char c : capital) {
        if (c == ' ')
            spaceCount++;
        if (c == '-')
            hyphenCount++;
    }

    if (spaceCount > 2) return false;
    if (hyphenCount > 2) return false;

    if (spaceCount != 0 && hyphenCount != 0) return false;

    if (capital == stateName) return false;

    // Check for duplicate capital among existing states
    for (const auto& state : states) {
        if (capital == state.capital) {
            return false;
        }
    }

    return true;
}

// Валидация численности населения
bool isValidPopulation(const string& populationStr) {
    for (char c : populationStr) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Валидация площади государства
bool isValidArea(const string& areaStr) {
    int decimalCount = 0;
    for (char c : areaStr) {
        if (!isdigit(c)) {
            if (c == '.' || c == ',') {
                decimalCount++;
            }
            else return false;
        }
    }
    if (decimalCount > 1) return false;
    return true;
}

// Валидация формы правления (просто проверяем, что введен номер от 1 до 3)
bool isValidGovernmentForm(const string& governmentFormStr) {
    if (governmentFormStr.length() != 1 || !isdigit(governmentFormStr[0])) {
        return false;
    }
    int choice = stoi(governmentFormStr);
    return (choice >= 1 && choice <= 3);
}

// Функции для работы с данными
void addState(vector<State>& states) {
    State newState;
    string input;
    bool validName = false;
    bool validCapital = false;

    // Ввод и валидация наименования
    do {
        cout << "Введите наименование государства: ";
        getline(cin, newState.name);

        // Check for duplicate name
        bool nameExists = false;
        for (const auto& state : states) {
            if (state.name == newState.name) {
                nameExists = true;
                break;
            }
        }
        if (nameExists) {
            cout << "Ошибка: Государство с таким названием уже существует.\n";
            validName = false; // Force re-entry
            continue; // Restart this do-while loop iteration
        }
        validName = isValidName(newState.name);
        if (!validName) {
            cout << "Ошибка: Некорректное наименование. Допускается до трех слов (либо через пробелы, либо через дефисы).\n";
            continue; // Restart this do-while loop iteration
        }
    } while (!validName);

    // Ввод и валидация столицы
    do {
        cout << "Введите столицу государства: ";
        getline(cin, newState.capital);

        // Check for duplicate capital (in the context of all states)
        validCapital = isValidCapital(newState.capital, newState.name, states);
        if (!validCapital) {
            cout << "Ошибка: Некорректная столица. Допускается до трех слов (либо через пробелы, либо через дефисы). Столица не должна совпадать с названием страны или других стран.\n";
            continue; // Restart this do-while loop iteration
        }

    } while (!validCapital);

    // Ввод и валидация численности населения
    do {
        cout << "Введите численность населения(10000000000): ";
        getline(cin, input);
        if (isValidPopulation(input)) {
            try {
                newState.population = stoll(input);
                break; // Exit the loop if the population is valid
            }
            catch (const out_of_range& oor) {
                cout << "Ошибка: Слишком большое число для населения.\n";
            }
        }
        else {
            cout << "Ошибка: Некорректная численность населения. Допускаются только цифры без пробелов.\n";
        }
    } while (true);

    // Ввод и валидация площади
    do {
        cout << "Введите площадь государства(км. кв.): ";
        getline(cin, input);
        if (isValidArea(input)) {
            try {
                // Replace comma with a dot for correct conversion
                replace(input.begin(), input.end(), ',', '.');
                newState.area = stod(input);
                break; // Exit the loop if the area is valid
            }
            catch (const invalid_argument& ia) {
                cout << "Ошибка: Некорректная площадь.\n";
            }
        }
        else {
            cout << "Ошибка: Некорректная площадь. Допускаются только цифры с точкой или запятой.\n";
        }
    } while (true);

    newState.governmentForm = inputFormOfGovernment(newState.otherForm);

    states.push_back(newState);
    cout << "Государство успешно добавлено!\n";
}

void printState(const State& state) {
    cout << "Наименование: " << state.name << endl;
    cout << "Столица: " << state.capital << endl;
    cout << "Население: " << state.population << endl;
    cout << "Площадь: " << state.area << endl;
    cout << "Форма правления: " << formOfGovernmentToString(state.governmentForm) << endl;
    if (state.governmentForm == FormOfGovernment::OTHER) {
        cout << "Пользовательская форма правления: " << state.otherForm << endl;
    }
}

void listStates(const vector<State>& states) {
    if (states.empty()) {
        cout << "Список государств пуст.\n";
        return;
    }

    cout << "Список государств:\n";
    for (size_t i = 0; i < states.size(); ++i) {
        cout << "--- Государство #" << i + 1 << " ---\n";
        printState(states[i]);
    }
}

void removeState(vector<State>& states) {
    if (states.empty()) {
        cout << "Список государств пуст. Удаление невозможно.\n";
        return;
    }

    int index;
    cout << "Введите номер государства для удаления (1-" << states.size() << "): ";
    cin >> index;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (index >= 1 && index <= states.size()) {
        states.erase(states.begin() + index - 1);
        cout << "Государство успешно удалено!\n";
    }
    else {
        cout << "Неверный номер государства.\n";
    }
}

void searchStateByCapital(const vector<State>& states) {
    string capital;
    cout << "Введите столицу для поиска: ";
    getline(cin, capital);

    bool found = false;
    cout << "Результаты поиска:\n";
    for (const State& state : states) {
        if (state.capital == capital) {
            printState(state);
            found = true;
        }
    }

    if (!found) {
        cout << "Государство со столицей '" << capital << "' не найдено.\n";
    }
}

// Главная функция с меню
int main() {
#ifdef _WIN32
    setlocale(LC_ALL, "rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif

    vector<State> states;
    int choice;

    while (true) {
        cout << "\n--- Меню ---\n";
        cout << "1. Добавить государство\n";
        cout << "2. Список государств\n";
        cout << "3. Удалить государство\n";
        cout << "4. Поиск государства по столице\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: addState(states); break;
        case 2: listStates(states); break;
        case 3: removeState(states); break;
        case 4: searchStateByCapital(states); break;
        case 0: cout << "Выход из программы.\n"; return 0;
        default: cout << "Неверный ввод. Пожалуйста, выберите действие из меню.\n";
        }
    }

    return 0;
}