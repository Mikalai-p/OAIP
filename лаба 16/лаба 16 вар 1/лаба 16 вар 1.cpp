#include <iostream>
#include <string> // Бібліятэка для задання з сказам
#include <Windows.h>

using namespace std;


void zamenaAdmounix(int** A, int n, int m) 
{
    int i, j;
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) {
            if ((i +1) % 2 != 0 && A[i][j] < 0) {
                A[i][j] *= -1;
            }
        }
    }
    cout << "Новая матрица: " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << A[i][j] <<"\t";
        }
        cout << endl;
    }
}

void zmenaRadka(char* str, int size) { 
    int i;
    for (i = 0; i < size; i++) {
        if (str[i] == '.' || str[i] == ' ') { 
            str[i + 1] = toupper(str[i + 1]);
        }
    }

    cout << "Новая строка: \n" << str << endl;
}

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char exitWord[11] = "end";
    char userInput[11];

    do {
        int choice = 0;
        bool validChoice = false; 

        do {
            cout << "Выберите задание (1 или 2): ";
            cin >> choice;


            if (cin.fail() || choice < 1 || choice > 2) { 
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Ошибка. Пожалуйста, выберите номер задания 1 или 2: " << endl;
            }
            else {
                validChoice = true;
            }
        } while (!validChoice);
        cin.clear();

        switch (choice)
        {
        case 1: {
            int n, m, i, j;
            cout << "Введите размер строк: "; cin >> n;
            cout << "Введите размер столбцов: "; cin >> m;
            int** A;
            A = new int* [n];
            for (i = 0; i < n; i++)
                A[i] = new int[m];
            cout << "Введите элементы массива: " << endl;
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    cin >> A[i][j];
                }
            }
            cout << "Введенная матрица: " << endl;
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    cout << A[i][j] << "\t";
                }
                cout << endl;
            }
            zamenaAdmounix(A, n, m);
            for (i = 0; i < n; i++)
                delete A[i];
            delete[] A; 
            break;
        }

        case 2: {
            int size = 0;
            cout << "Введите размер строки: "; cin >> size;
            cin.ignore();
            char* str = new char[size + 1]; 
            cout << "Введите строку: ";
            cin.getline(str, size + 1); 
            zmenaRadka(str, size + 1);
            delete[] str; 

        }
        }
        cout << "Введите слово \"" << exitWord << "\", если хотите закончить программу, если нет, что-нибудь другое: ";
        cin.ignore();
        cin.getline(userInput, sizeof(userInput)); 

        if (strcmp(userInput, exitWord) == 0) { 
            break;
        }
    } while (true); 
}
