#include <iostream>
#include <fstream>
#include <string>
#include <limits> 
#include <iomanip>

using namespace std;


struct Node {
    double data;
    Node* next;
};


void addNode(Node** head, double data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}


void deleteNode(Node** head, double value) {
    Node* current = *head;
    Node* previous = nullptr;

    
    if (current != nullptr && current->data == value) {
        *head = current->next;
        delete current;
        return;
    }

    
    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    
    if (current == nullptr) {
        cout << "Элемент со значением " << value << " не найден в списке.\n";
        return;
    }

    
    previous->next = current->next;
    delete current;
}


Node* searchNode(Node* head, double value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr; 
}


void printList(Node* head) {
    Node* current = head;
    if (current == nullptr)
    {
        cout << "Список пуст\n";
        return;
    }
    while (current != nullptr) {
        cout <<" -> " << std::fixed << std::setprecision(4) << current->data << " "; //  Использовать std::fixed и установить точность
        current = current->next;
    }
    cout << std::endl;
}

void saveListToFile(Node* head, const string& filename) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        Node* current = head;
        while (current != nullptr) {
            outputFile << current->data << endl;
            current = current->next;
        }
        outputFile.close();
        cout << "Список успешно записан в файл " << filename << endl;
    }
    else {
        cout << "Не удалось открыть файл для записи.\n";
    }
}


void loadListFromFile(Node** head, const string& filename) {
    ifstream inputFile(filename);
    double data;

    
    while (*head != nullptr) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
    }

    *head = nullptr;

    if (inputFile.is_open()) {
        while (inputFile >> data) {
            addNode(head, data);
        }
        inputFile.close();
        cout << "Список успешно считан из файла " << filename << endl;
    }
    else {
        cout << "Не удалось открыть файл для чтения.\n";
    }
}


double calculateProductLessThan10(Node* head) {
    double product = 1.0;
    Node* current = head;
    bool found_element = false;
    while (current != nullptr) {
        if (current->data < 10.0) {
            product *= current->data;
            found_element = true;
        }
        current = current->next;
    }
    if (!found_element) {
        return 0;
    }
    return product;
}


void freeList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    Node* head = nullptr;
    int choice;
    long double value;
    string filename;

    do {
        cout << "\n--- Меню ---\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Удалить элемент\n";
        cout << "3. Поиск элемента\n";
        cout << "4. Вывод списка в консоль\n";
        cout << "5. Запись списка в файл\n";
        cout << "6. Считывание списка из файла\n";
        cout << "7. Вычислить произведение элементов < 10\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        switch (choice) {
        case 1:
            cout << "Введите значение элемента: ";
            cin >> value;
            if (cin.fail()) {
                cout << "Некорректный ввод. Пожалуйста, введите число.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            addNode(&head, value);
            break;
        case 2:
            cout << "Введите значение элемента для удаления: ";
            cin >> value;
            if (cin.fail()) {
                cout << "Некорректный ввод. Пожалуйста, введите число.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            deleteNode(&head, value);
            break;
        case 3: {
            cout << "Введите значение элемента для поиска: ";
            cin >> value;
            if (cin.fail()) {
                cout << "Некорректный ввод. Пожалуйста, введите число.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            Node* foundNode = searchNode(head, value);
            if (foundNode != nullptr) {
                cout << "Элемент найден: " << foundNode->data << endl;
            }
            else {
                cout << "Элемент не найден.\n";
            }
            break;
        }
        case 4:
            printList(head);
            break;
        case 5:
            cout << "Введите имя файла для записи: ";
            getline(cin, filename);
            saveListToFile(head, filename);
            break;
        case 6:
            cout << "Введите имя файла для чтения: ";
            getline(cin, filename);
            loadListFromFile(&head, filename);
            break;
        case 7: {
            double product = calculateProductLessThan10(head);
            cout << "Произведение элементов, меньших 10: " << product << endl;
            break;
        }
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный ввод. Пожалуйста, выберите действие из меню.\n";
        }
    } while (choice != 0);

    
    freeList(head);

    return 0;
}