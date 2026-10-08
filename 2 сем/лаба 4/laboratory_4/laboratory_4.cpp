#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <limits> // Required for numeric_limits
#include <vector>
#include <sstream> // Required for stringstream

using namespace std;

#define SIZE 1

struct univ {
    char name[20];
    char color[20];
    char num[20];
    int date;
    int type;
    int date2;
    char owner[40]; // Increased size
};

univ arr[SIZE];
int i = 0;
int oper;

bool isAlphaString(const string& str) {
    if (str.empty()) return false;

    for (size_t j = 0; j < str.length(); ++j) {
        char c = str[j];
        if (!isalpha(c) && c != ' ' && c != '-') {
            return false;
        }

        if (c == '-' && (j == 0 || j == str.length() - 1)) {
            return false; // Cannot start or end with hyphen
        }

        if (c == '-' && j > 0 && str[j - 1] == '-')
        {
            return false; // No consecutive hyphens
        }

    }

    // Check for consecutive spaces
    for (size_t j = 0; j < str.length() - 1; ++j) {
        if (str[j] == ' ' && str[j + 1] == ' ') {
            return false;
        }

    }
    if (str.length() > 0 && str[0] == ' ') return false;
    if (str.length() > 0 && str[str.length() - 1] == ' ') return false;

    return true;
}

bool isValidColor(const string& str) {
    for (char c : str) {
        if (!isalpha(c) && c != '-') {
            return false;
        }
    }
    return true;
}

bool isValidAlphanumericWithHyphens(const string& str) {
    for (char c : str) {
        if (!isalnum(c) && c != '-') {
            return false;
        }
    }
    return true;
}

bool isValidDate(int date) {
    if (date < 10000000 || date > 99999999) {
        return false;
    }

    int day = date / 1000000;
    int month = (date / 10000) % 100;
    int year = date % 10000;

    if (month < 1 || month > 12) {
        return false;
    }

    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysInMonth[2] = 29;
    }

    if (day < 1 || day > daysInMonth[month]) {
        return false;
    }

    return true;
}

void input();
void remove_record();
void output();
void search();
void infile();
void outfile();
vector<string> bodyTypes = { "универсал", "хэтчбек", "микроавтобус", "седан", "купе", "кабриолет", "пикап", "внедорожник", "минивэн", "лимузин" };

int main() {
    setlocale(LC_CTYPE, "rus");
    do {
        cout << "Что вы хотите сделать?\n";
        cout << "1 - Ввод данных в структуру\n";
        cout << "2 - Удаление данных из структуры\n";
        cout << "3 - Вывод данных на экран\n";
        cout << "4 - Поиск по владельцу\n";
        cout << "5 - Запись в файл\n";
        cout << "6 - Чтение из файла\n";
        cout << "7 - Для завершения работы\n";

        // Input validation loop for 'oper'
        while (!(cin >> oper)) {
            cout << "Ошибка: Некорректный ввод. Введите числовое значение.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Что вы хотите сделать?\n";
            cout << "1 - Ввод данных в структуру\n";
            cout << "2 - Удаление данных из структуры\n";
            cout << "3 - Вывод данных на экран\n";
            cout << "4 - Поиск по владельцу\n";
            cout << "5 - Запись в файл\n";
            cout << "6 - Чтение из файла\n";
            cout << "7 - Для завершения работы\n";
        }

        switch (oper) {
        case 1:  input(); break;
        case 2:  remove_record(); break;
        case 3:  output(); break;
        case 4:  search(); break;
        case 5:  infile(); break;
        case 6:  outfile(); break;
        case 7: break;
        default:
            cout << "Неверный ввод. Пожалуйста, выберите действие от 1 до 7.\n";
        }
    } while (oper != 7);

    system("pause");
    return 0;
}

void input() {
    if (i < SIZE) {
        string temp;
        int dateInput;
        string bodyTypeChoiceStr;
        int bodyTypeChoice;
        bool validBodyType = false;
        bool firstAttempt = true;

        // Input and validation for name
        do {
            cout << "Введите марку автомобиля: ";
            cin.ignore();
            getline(cin, temp);
            if (!isAlphaString(temp)) {
                cout << "Ошибка: Марка должна содержать только буквы и не содержать нескольких пробелов подряд или символов.\n";
            }
        } while (!isAlphaString(temp));
        strncpy_s(arr[i].name, temp.c_str(), sizeof(arr[i].name) - 1);
        arr[i].name[sizeof(arr[i].name) - 1] = '\0';

        // Input and validation for color
        do {
            cout << "Введите цвет автомобиля (допускается дефис для оттенков): ";
            getline(cin, temp);
            if (!isValidColor(temp)) {
                cout << "Ошибка: Цвет должен содержать только буквы и дефисы для оттенков.\n";
            }
        } while (!isValidColor(temp));
        strncpy_s(arr[i].color, temp.c_str(), sizeof(arr[i].color) - 1);
        arr[i].color[sizeof(arr[i].color) - 1] = '\0';

        // Input validation loop for 'num'
        do {
            cout << "Введите заводской номер (буквы, цифры, дефис): ";
            getline(cin, temp);
            if (!isValidAlphanumericWithHyphens(temp)) {
                cout << "Ошибка: Заводской номер может содержать только буквы, цифры и дефисы.\n";
            }
            else {
                strncpy_s(arr[i].num, temp.c_str(), sizeof(arr[i].num) - 1);
                arr[i].num[sizeof(arr[i].num) - 1] = '\0';
                break;
            }
        } while (true);

        // Input and validation for date
        do {
            cout << "Введите дату выпуска авт.(ДДММГГГГ): ";
            cin >> dateInput;

            if (cin.fail()) {
                cout << "Ошибка: Неверный формат даты. Введите числовое значение в формате ДДММГГГГ.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                dateInput = 0;
            }
            else if (!isValidDate(dateInput)) {
                cout << "Ошибка: Неверный формат даты. Введите в формате ДДММГГГГ.\n";
            }
        } while (cin.fail() || !isValidDate(dateInput));
        arr[i].date = dateInput;

        


        while (!validBodyType) {
            if (!firstAttempt)
            {
                cout << "Выберите тип кузова (введите номер):\n";
                cout << "1 - универсал\n";
                cout << "2 - хэтчбек\n";
                cout << "3 - микроавтобус\n";
                cout << "4 - седан\n";
                cout << "5 - купе\n";
                cout << "6 - кабриолет\n";
                cout << "7 - пикап\n";
                cout << "8 - внедорожник\n";
                cout << "9 - минивэн\n";
                cout << "10 - лимузин\n";
            }
            cout << "Введите цифру от 1 до 10 для выбора типа кузова: ";



            getline(cin, bodyTypeChoiceStr); // Read the entire line
            stringstream ss(bodyTypeChoiceStr); // Create a stringstream from the input
            int num;
            char extra;

            if (ss >> num && !(ss >> extra)) // Try to read an int, and then something else
            {
                if (num >= 1 && num <= 10) {
                    arr[i].type = num;
                    validBodyType = true;
                    cout << "Тип кузова успешно выбран!\n";
                }
            }
                else {
                    cout << "Ошибка: Введите цифру от 1 до 10.\n";

                
            }
            
            firstAttempt = false;
        }

        // Input and validation for date2
        do {
            cout << "Введите дату последнего техосмотра авт.(ДДММГГГГ): ";
            cin >> dateInput;

            if (cin.fail()) {
                cout << "Ошибка: Неверный формат даты. Введите числовое значение в формате ДДММГГГГ.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                dateInput = 0;
            }
            else if (!isValidDate(dateInput)) {
                cout << "Ошибка: Неверный формат даты. Введите в формате ДДММГГГГ.\n";
            }
        } while (cin.fail() || !isValidDate(dateInput));
        arr[i].date2 = dateInput;

        // Input and validation for owner FIO
        do {
            cout << "Введите Фамилию Имя Отчество владельца: ";
            cin.ignore();
            getline(cin, temp);

            if (!isAlphaString(temp)) {
                cout << "Ошибка: ФИО владельца должно содержать только буквы и пробелы.\n";
                continue; // Skip to next iteration if the name is invalid
            }
            else if (temp.empty()) {
                cout << "Ошибка: ФИО владельца не может быть пустым.\n";
                continue;  // Skip to next iteration if the name is empty
            }

            strncpy_s(arr[i].owner, temp.c_str(), sizeof(arr[i].owner) - 1);
            arr[i].owner[sizeof(arr[i].owner) - 1] = '\0';
            break; // Exit loop if everything is valid


        } while (true);

        i++;
        cout << "-------------------------------------------" << endl;
    }
    else {
        cout << "Структура заполнена. Невозможно добавить больше элементов.\n";
    }
}

void output() {
    if (i > 0) {
        int n;
        cout << "Введите номер элемента, который хотите вывести: ";
        cin >> n;
        n--;

        if (n >= 0 && n < i) {
            cout << "Mаркa автомобиля: " << arr[n].name << endl;
            cout << "Цвет: " << arr[n].color << endl;
            cout << "Заводской номер: " << arr[n].num << endl;
            cout << "Дата выпуска: " << arr[n].date << endl;
            cout << "Тип кузова: " << bodyTypes[arr[n].type - 1] << endl;
            cout << "Фамилия владельца: " << arr[n].owner << endl;
            cout << "Дата последнего техосмотра: " << arr[n].date2 << endl;
        }
        else {
            cout << "Неверный номер элемента.\n";
        }
    }
    else {
        cout << "Нет данных для вывода.\n";
    }
    cout << "-------------------------------------------" << endl;
}

void remove_record() {
    if (i > 0) {
        int d;
        cout << "Номер записи, которую нужно удалить: ";
        cin >> d;
        d--;

        if (d >= 0 && d < i) {
            for (int de1 = d; de1 < i - 1; de1++) {
                arr[de1] = arr[de1 + 1];
            }
            i--;
            cout << "Запись удалена" << endl;
        }
        else {
            cout << "Неверный номер записи.\n";
        }
    }
    else {
        cout << "Нет данных для удаления.\n";
    }
    cout << "-------------------------------------------" << endl;
}

void search() {
    string t, owner;
    if (i > 0) {
        cout << "Введите фамилию владельца: ";
        cin >> t;

        bool found = false;
        for (int k = 0; k < i; k++) {
            owner = arr[k].owner;
            if (owner == t) {
                cout << "Mаркa автомобиля: " << arr[k].name << endl;
                cout << "Цвет: " << arr[k].color << endl;
                cout << "Заводской номер: " << arr[k].num << endl;
                cout << "Дата выпуска: " << arr[k].date << endl;
                cout << "Тип кузова: " << bodyTypes[arr[k].type - 1] << endl;
                cout << "Фамилия владельца: " << arr[k].owner << endl;
                cout << "Дата последнего техосмотра: " << arr[k].date2 << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Владелец не найден.\n";
        }
    }
    else {
        cout << "Нет данных для поиска.\n";
    }
    cout << "-------------------------------------------" << endl;
}

void infile() {
    ofstream fout("data.txt", ios::binary);

    if (fout.is_open()) {
        fout.write((char*)arr, sizeof(univ) * i);
        fout.close();
        cout << "Данные успешно записаны в файл.\n";
    }
    else {
        cout << "Ошибка открытия файла для записи.\n";
    }
}

void outfile() {
    ifstream fin("data.txt", ios::binary);

    if (fin.is_open()) {
        fin.read((char*)arr, sizeof(univ) * i);
        if (fin) {
            i = SIZE;
        }
        else {
            i = fin.gcount() / sizeof(univ);
        }
        fin.close();
        cout << "Данные успешно прочитаны из файла.\n";
    }
    else {
        cout << "Ошибка открытия файла для чтения.\n";
    }
}