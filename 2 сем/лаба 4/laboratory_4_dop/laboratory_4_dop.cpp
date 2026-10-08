#include <string>
#include <fstream>
#include <iostream>
#include <cctype>   
#include <sstream>  
#include <vector>

using namespace std;

#define str_len 40
#define sizeS 30
#define trains_len 8
string A = "A.txt";
char str[512];


bool isAlphaString(const string& str) {
    for (char c : str) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
    }
    return true;
}


bool isDigitString(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}


bool isValidTime(const std::string& time) {
    if (time.length() != 5 || time[2] != ':') {
        return false;
    }

    std::string hours_str = time.substr(0, 2);
    std::string minutes_str = time.substr(3, 2);

    if (!isDigitString(hours_str) || !isDigitString(minutes_str)) {
        return false;
    }

    int hours = std::stoi(hours_str);
    int minutes = std::stoi(minutes_str);

    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
        return false;
    }

    return true;
}
struct Stu {
    char name[str_len];
    int date_of_in;
    char sp[str_len];
    char numgr[str_len];
    char f[str_len];
    char sr[str_len];
};

struct Students {
    char name[str_len];
    int amount_exams;
    int* marks = new int[1];
};

struct Trains {
    char name[str_len];
    int num;
    string time; 
};

struct Sanatorium {
    char name[str_len];
    char location[str_len];
    char profile[str_len];
    int amount;
};

struct Stu list_of_stu[sizeS], free_students;
int current_size = 0;

struct Students list_of_students[sizeS], free_student;
int current_size_st = 0;

struct Trains list_of_trains[trains_len], free_train, help_train;
int current_size_tr = 0;

struct Sanatorium list_of_sanatorium[sizeS], free_sanatorim, help_sanatorim;
int current_size_sn = 0;

void dop1();
void enter_new_st();
void del_st(int d);
void out_st();
void write_file_st();
void performance();
void read_file_st();

void dop2();
void enter_new_tr();
void del_tr(int d);
void out_tr();
void write_file_tr();
void sorting();
void read_file_tr();

void dop3();
void enter_new_sn();
void del_sn(int d);
void out_sn();
void write_file_sn();
void sorting_sn();
void read_file_sn();

int main() {
    
    setlocale(LC_ALL, "Russian");

    bool work = true;
    int n;
    while (work) {
        cout << "\n1. Доп 1\n2. Доп 2\n3. Доп 3\n0. Закончить\n(Введите вариант) ";
        cin >> n;
        switch (n) {
        case(1):
            dop1();
            break;

        case(2):
            dop2();
            break;

        case(3):
            dop3();
            break;

        case(0):
            work = false;
            break;

        default:
            break;
        }
    }
}

void dop1() {
    int choice = 1, d;

    while (choice != 0) {
        cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n4. Запись в файл\n5. Чтение из файла\n6. Успеваемость\n0. Завершить работу\n(Введите выбор) ";
        cin >> choice;
        switch (choice) {
        case(1):
            enter_new_st();
            break;

        case(2):
            cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
            cin >> d;
            del_st(d);
            break;

        case(3):
            out_st();
            break;

        case(4):
            write_file_st();
            break;

        case(5):
            read_file_st();
            break;

        case(6):
            performance();
            break;

        default:
            break;
        }
    }
}

void enter_new_st() {
    if (current_size_st < sizeS) {
        string name_str;
        int amount_exams;
        Students& student = list_of_students[current_size_st];  
        do {
            cout << "Введите фамилию студента: ";
            cin.ignore();
            getline(cin, name_str);
            if (name_str.length() > str_len - 1) {
                cout << "Ошибка: Превышена максимальная длина имени (" << str_len - 1 << " символов).\n";
            }
            else if (!isAlphaString(name_str)) {
                cout << "Ошибка: Фамилия должна содержать только буквы.\n";
            }

        } while (!isAlphaString(name_str) || name_str.length() > str_len - 1);
        strncpy_s(student.name, name_str.c_str(), str_len - 1);
        student.name[str_len - 1] = '\0';

        
        do {
            cout << "Введите количество экзаменов: ";
            cin >> amount_exams;
            if (cin.fail()) {
                cout << "Ошибка: Количество экзаменов должно быть числом.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        } while (true);
        delete[] student.marks; 
        student.marks = new int[amount_exams]; // Allocate new memory
        student.amount_exams = amount_exams;

        

        string marks_str;
        cin.ignore(); 

        do {
            cout << "Введите отметки (через пробел): ";
            getline(cin, marks_str);

            stringstream ss(marks_str);
            int mark;
            int count = 0;
            bool valid = true;

            
            vector<int> temp_marks;

            while (ss >> mark) {
                temp_marks.push_back(mark); 
                count++;
                if (ss.fail()) { 
                    valid = false;
                    break;
                }
            }

            if (count != student.amount_exams) {
                cout << "Ошибка: Введено неверное количество отметок. Необходимо ввести " << student.amount_exams << " отметок.\n";
                valid = false; 
            }

            if (valid) {
                for (int i = 0; i < student.amount_exams; i++) {
                    student.marks[i] = temp_marks[i];
                }
                break; 
            }
            else {
                cin.clear(); 
                cout << "Ошибка: Введено неверное значение.\n";
            }
        } while (true);

        current_size_st++;
    }
    else {
        cout << "Введено максимальное кол-во строк" << endl;
    }
}

void del_st(int d) {
    if (d == -1) {
        for (int i = 0; i < current_size_st; i++) {
            delete[] list_of_students[i].marks; // Release memory
        }
        current_size_st = 0;
        memset(list_of_students, 0, sizeof(list_of_students)); //Zero out the array
    }
    else if (d > 0 && d <= current_size_st) {
        delete[] list_of_students[d - 1].marks; //Delete array befor removing student
        for (int i = d - 1; i < current_size_st - 1; i++) {
            list_of_students[i] = list_of_students[i + 1];
        }
        current_size_st--;
        memset(&list_of_students[current_size_st], 0, sizeof(Students)); //Zero out the last element
    }
    else {
        cout << "Неверный номер записи.\n";
    }
}

void out_st() {
    string name;
    cout << " Введите фамилию для поиска записи (для вывода всех записей введите 1): ";
    cin.ignore();  
    getline(cin, name);

    if (name == "1") {
        for (int i = 0; i < current_size_st; i++) {
            cout << " Запись №" << i + 1 << " | Фамилия - " << list_of_students[i].name << " | кол-во экзаменов - " << list_of_students[i].amount_exams;
            for (int j = 0; j < list_of_students[i].amount_exams; j++) {
                cout << " | отметка за " << j + 1 << "-й экзамен - " << list_of_students[i].marks[j];
            }
            cout << endl;
        }
    }
    else {
        for (int i = 0; i < current_size_st; i++) {
            if (string(list_of_students[i].name) == name) {
                cout << " Запись №" << i + 1 << " | Фамилия - " << list_of_students[i].name << " | кол-во экзаменов - " << list_of_students[i].amount_exams;
                for (int j = 0; j < list_of_students[i].amount_exams; j++) {
                    cout << " | отметка за " << j + 1 << "-й экзамен - " << list_of_students[i].marks[j];
                }
                cout << endl;
            }
        }
    }
}

void write_file_st() {
    ofstream fAout(A);
    if (fAout.is_open()) {
        for (int i = 0; i < current_size_st; i++) {
            fAout << list_of_students[i].name << "\n";
            fAout << list_of_students[i].amount_exams << "\n";
            for (int j = 0; j < list_of_students[i].amount_exams; j++) {
                fAout << list_of_students[i].marks[j] << "\n";
            }
        }
    }
    else {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAout.close();
}

void read_file_st() {
    del_st(-1);
    char str2[200], str3[200];
    ifstream fAin(A);
    if (fAin.is_open()) {
        while (fAin.peek() != EOF) //Check that file isn't empty
        {
            Students& student = list_of_students[current_size_st]; // Use a reference

            fAin.getline(student.name, sizeof(student.name));
            fAin.getline(str2, sizeof(str2));
            if (strlen(str2) == 0) break; //Prevent errors if EOF is mid-student

            student.amount_exams = atoi(str2);
            delete[] student.marks; // Delete old array
            student.marks = new int[student.amount_exams]; // Create new array

            for (int i = 0; i < student.amount_exams; i++) {
                fAin.getline(str3, sizeof(str3));
                student.marks[i] = atoi(str3);
            }

            current_size_st++;
            if (current_size_st >= sizeS) break;  //Prevent overflow
        }
    }
    else {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAin.close();
}

void performance() {
    float num = 0;
    for (int i = 0; i < current_size_st; i++) {
        for (int j = 0; j < list_of_students[i].amount_exams; j++) {
            if (list_of_students[i].marks[j] < 4) break;
            if (j == list_of_students[i].amount_exams - 1) num++;
        }
    }
    cout << "Процент студентов, сдавших экзамены на 4 и 5 = " << num / current_size_st * 100 << "%" << endl;
}

void dop2() {
    int choice = 1, d;

    while (choice != 0) {
        cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n4. Запись в файл\n5. Чтение из файла\n6. Сортировка\n0. Завершить работу\n(Введите выбор) ";
        cin >> choice;
        switch (choice) {
        case(1):
            enter_new_tr();
            break;

        case(2):
            cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
            cin >> d;
            del_tr(d);
            break;

        case(3):
            out_tr();
            break;

        case(4):
            write_file_tr();
            break;

        case(5):
            read_file_tr();
            break;

        case(6):
            sorting();
            break;

        default:
            break;
        }
    }
}

void enter_new_tr() {
    if (current_size_tr < trains_len) {
        string name_str, time_str;
        int num_val;

        // Validate Destination Name (Only Letters) and Length
        do {
            cout << "Введите название пункта назначения: ";
            cin.ignore();  // Consume the newline character
            getline(cin, name_str); // Use getline to read the whole name
            if (name_str.length() > str_len - 1) {
                cout << "Ошибка: Превышена максимальная длина названия (" << str_len - 1 << " символов).\n";
            }
            else if (!isAlphaString(name_str)) {
                cout << "Ошибка: Название пункта назначения должно содержать только буквы.\n";
            }
        } while (!isAlphaString(name_str) || name_str.length() > str_len - 1);
        strncpy_s(list_of_trains[current_size_tr].name, name_str.c_str(), str_len - 1);
        list_of_trains[current_size_tr].name[str_len - 1] = '\0';

        // Validate train Number(Only Numbers)
        do {
            cout << "Введите номер поезда: ";
            cin >> num_val;

            if (cin.fail()) {
                cout << "Ошибка: Номер поезда должен быть числом.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                list_of_trains[current_size_tr].num = num_val;
                break;
            }
        } while (true);

        // Validate Time (hh:mm format)
        do {
            cout << "Введите время отправления (hh:mm): ";
            cin.ignore(); // Consume the newline character
            getline(cin, time_str);
            if (!isValidTime(time_str)) {
                cout << "Ошибка: Неверный формат времени. Введите в формате hh:mm.\n";
            }
        } while (!isValidTime(time_str));
        list_of_trains[current_size_tr].time = time_str;

        current_size_tr++;
    }
    else {
        cout << "Введено максимальное кол-во строк" << endl;
    }
}

void del_tr(int d) {
    if (d == -1) {
        for (int i = 0; i < trains_len; i++) {
            list_of_trains[i] = free_train;
        }
        current_size_tr = 0;
    }
    else {
        for (int i = d - 1; i < current_size_tr; i++) {
            list_of_trains[i] = list_of_trains[i + 1];
        }
        current_size_tr--;
    }
}

void out_tr() {
    string t_str;
    cout << "Введите время: ";
    cin >> t_str;
    if (isValidTime(t_str)) {
        int q = 0;
        for (int i = 0; i < current_size_tr; i++) {
            if (list_of_trains[i].time >= t_str) {
                cout << " Запись №" << i + 1 << " | названия пункта назначения - " << list_of_trains[i].name << " | номер поезда - " << list_of_trains[i].num << " | время отправления - " << list_of_trains[i].time << endl;
                q++;
            }
        }
        if (q == 0) cout << "Таких поездов нет" << endl;
    }
    else {
        cout << "Ошибка: Неверный формат времени. Введите в формате hh:mm.\n";
    }
}

void write_file_tr() {
    ofstream fAout(A);
    if (fAout.is_open()) {
        for (int i = 0; i < current_size_tr; i++) {
            fAout << list_of_trains[i].name << endl;
            fAout << list_of_trains[i].num << endl;
            fAout << list_of_trains[i].time << endl;
        }
    }
    else {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAout.close();
}

void read_file_tr() {
    del_tr(-1);
    char str2[200];
    string str3;
    ifstream fAin(A);
    if (fAin.is_open()) {
        while (fAin.peek() != EOF)
        {
            fAin.getline(list_of_trains[current_size_tr].name, sizeof(list_of_trains[current_size_tr].name));
            fAin.getline(str2, sizeof(str2));
            if (strlen(str2) == 0) break; //Prevent errors if EOF is mid-student
            std::getline(fAin, str3); //Read string instead of int
            list_of_trains[current_size_tr].num = atoi(str2);
            list_of_trains[current_size_tr].time = str3; // Store the string

            current_size_tr++;
            if (current_size_tr >= trains_len) break;  //Prevent overflow
        }
    }
    else {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAin.close();
}

void sorting() {
    int q, i;
    for (i = 0; i < current_size_tr - 1; i++) {
        q = (strlen(list_of_trains[i].name) > strlen(list_of_trains[i + 1].name)) ? strlen(list_of_trains[i + 1].name) : strlen(list_of_trains[i].name);
        for (int j = 0; j < q; j++) {
            if (list_of_trains[i].name[j] < list_of_trains[i + 1].name[j]) break;
            if (list_of_trains[i].name[j] > list_of_trains[i + 1].name[j]) {
                help_train = list_of_trains[i + 1];
                list_of_trains[i + 1] = list_of_trains[i];
                list_of_trains[i] = help_train;
                i = -1;
                break;
            }
        }
    }
}

void dop3() {
    int choice = 1, d;

    while (choice != 0) {
        cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n4. Запись в файл\n5. Чтение из файла\n6. Сортировка\n0. Завершить работу\n(Введите выбор) ";
        cin >> choice;
        switch (choice) {
        case(1):
            enter_new_sn();
            break;

        case(2):
            cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
            cin >> d;
            del_sn(d);
            break;

        case(3):
            out_sn();
            break;

        case(4):
            write_file_sn();
            break;

        case(5):
            read_file_sn();
            break;

        case(6):
            sorting_sn();
            break;

        default:
            break;
        }
    }
}

void enter_new_sn() {
    if (current_size_sn < sizeS) {
        string name_str, location_str, profile_str;
        int amount_val;

        Sanatorium& sanatorium = list_of_sanatorium[current_size_sn]; // Use a reference
        // Validate Sanatorium Name (Only Letters) and Length
        do {
            cout << "Введите название санатория: ";
            cin.ignore();
            getline(cin, name_str);
            if (name_str.length() > str_len - 1) {
                cout << "Ошибка: Превышена максимальная длина названия (" << str_len - 1 << " символов).\n";
            }
            else if (!isAlphaString(name_str)) {
                cout << "Ошибка: Название санатория должно содержать только буквы.\n";
            }
        } while (!isAlphaString(name_str) || name_str.length() > str_len - 1);
        strncpy_s(sanatorium.name, name_str.c_str(), str_len - 1);
        sanatorium.name[str_len - 1] = '\0';

        // Validate Location Name (Only Letters) and Length
        do {
            cout << "Введите место расположения: ";
            getline(cin, location_str);
            if (location_str.length() > str_len - 1) {
                cout << "Ошибка: Превышена максимальная длина местоположения (" << str_len - 1 << " символов).\n";
            }
            else if (!isAlphaString(location_str)) {
                cout << "Ошибка: Место расположения должно содержать только буквы.\n";
            }
        } while (!isAlphaString(location_str) || location_str.length() > str_len - 1);
        strncpy_s(sanatorium.location, location_str.c_str(), str_len - 1);
        sanatorium.location[str_len - 1] = '\0';

        // Validate Profile Name (Only Letters) and Length
        do {
            cout << "Введите лечебный профиль: ";
            getline(cin, profile_str);
            if (profile_str.length() > str_len - 1) {
                cout << "Ошибка: Превышена максимальная длина профиля (" << str_len - 1 << " символов).\n";
            }
            else if (!isAlphaString(profile_str)) {
                cout << "Ошибка: Лечебный профиль должен содержать только буквы.\n";
            }
        } while (!isAlphaString(profile_str) || profile_str.length() > str_len - 1);
        strncpy_s(sanatorium.profile, profile_str.c_str(), str_len - 1);
        sanatorium.profile[str_len - 1] = '\0';

        // Validate Amount (Only Digits)
        do {
            cout << "Введите количество путевок: ";
            cin >> amount_val;

            if (cin.fail()) {
                cout << "Ошибка: Количество путевок должно быть числом.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                sanatorium.amount = amount_val;
                break;
            }
        } while (true);

        current_size_sn++;
    }
    else {
        cout << "Введено максимальное кол-во строк" << endl;
    }
}

void del_sn(int d) {
    if (d == -1) {
        for (int i = 0; i < sizeS; i++) {
            list_of_sanatorium[i] = free_sanatorim;
        }
        current_size_sn = 0;
    }
    else {
        for (int i = d - 1; i < current_size_sn; i++) {
            list_of_sanatorium[i] = list_of_sanatorium[i + 1];
        }
        current_size_sn--;
    }
}

void out_sn() {
    string name;
    cout << " Введите название санатория для поиска записи (для вывода всех записей введите 1): ";
    cin.ignore(); // Consume the newline character
    getline(cin, name);

    if (name == "1") {
        for (int i = 0; i < current_size_sn; i++) {
            cout << " Запись №" << i + 1 << " | название санатория - " << list_of_sanatorium[i].name << " | место расположения - " << list_of_sanatorium[i].location << " | лечебный профиль - " << list_of_sanatorium[i].profile << " | кол-во путёвок - " << list_of_sanatorium[i].amount << endl;
        }
    }
    else {
        for (int i = 0; i < current_size_sn; i++) {
            if (string(list_of_sanatorium[i].name) == name) {
                cout << " Запись №" << i + 1 << " | название санатория - " << list_of_sanatorium[i].name << " | место расположения - " << list_of_sanatorium[i].location << " | лечебный профиль - " << list_of_sanatorium[i].profile << " | кол-во путёвок - " << list_of_sanatorium[i].amount << endl;
            }
        }
    }
}

void write_file_sn() {
    ofstream fAout(A);
    if (fAout.is_open()) {
        for (int i = 0; i < current_size_sn; i++) {
            fAout << list_of_sanatorium[i].name << endl;
            fAout << list_of_sanatorium[i].location << endl;
            fAout << list_of_sanatorium[i].profile << endl;
            fAout << list_of_sanatorium[i].amount << endl;
        }
    }
    else {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAout.close();
}

void read_file_sn() {
    del_sn(-1);
    char str4[200];
    ifstream fAin(A);
    if (fAin.is_open()) {
        while (fAin.peek() != EOF)
        {
            fAin.getline(list_of_sanatorium[current_size_sn].name, sizeof(list_of_sanatorium[current_size_sn].name));
            fAin.getline(list_of_sanatorium[current_size_sn].location, sizeof(list_of_sanatorium[current_size_sn].location));
            fAin.getline(list_of_sanatorium[current_size_sn].profile, sizeof(list_of_sanatorium[current_size_sn].profile));
            fAin.getline(str4, sizeof(str4));
            if (strlen(str4) == 0) break; //Prevent errors if EOF is mid-student
            list_of_sanatorium[current_size_sn].amount = atoi(str4);
            current_size_sn++;
            if (current_size_sn >= sizeS) break;  //Prevent overflow
        }
    }
    else {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAin.close();
}

void sorting_sn() {
    int q, n;
    for (int i = 0; i < current_size_sn - 1; i++) {
        q = (strlen(list_of_sanatorium[i].name) > strlen(list_of_sanatorium[i + 1].name)) ? strlen(list_of_sanatorium[i + 1].name) : strlen(list_of_sanatorium[i].name);
        for (int j = 0; j < q; j++) {
            if (list_of_sanatorium[i].name[j] < list_of_sanatorium[i + 1].name[j]) break;
            if (list_of_sanatorium[i].name[j] > list_of_sanatorium[i + 1].name[j]) {
                help_sanatorim = list_of_sanatorium[i + 1];
                list_of_sanatorium[i + 1] = list_of_sanatorium[i];
                list_of_sanatorium[i] = help_sanatorim;
                i = -1;
                break;
            }
        }
    }

    n = 0;
    for (int k = 0; k < current_size_sn; k++) {
        if (list_of_sanatorium[k].name != list_of_sanatorium[k + 1].name) {
            for (int i = n; i < k; i++) {
                q = (strlen(list_of_sanatorium[i].profile) > strlen(list_of_sanatorium[i + 1].profile)) ? strlen(list_of_sanatorium[i + 1].profile) : strlen(list_of_sanatorium[i].profile);
                for (int j = 0; j < q; j++) {
                    if (list_of_sanatorium[i].profile[j] < list_of_sanatorium[i + 1].profile[j]) break;
                    if (list_of_sanatorium[i].profile[j] > list_of_sanatorium[i + 1].profile[j]) {
                        help_sanatorim = list_of_sanatorium[i + 1];
                        list_of_sanatorium[i + 1] = list_of_sanatorium[i];
                        list_of_sanatorium[i] = help_sanatorim;
                        i = -1;
                        break;
                    }
                }
            }
            n = k;
        }
    }
}