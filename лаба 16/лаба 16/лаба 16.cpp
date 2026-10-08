#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void poisk_max(int** arr, int n, int m) 
{
    int max = arr[0][0]; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (max < arr[i][j]) 
            {
                max = arr[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (max == arr[i][j])
            {
                cout << i + 1 << " " << j + 1 << ", "; 
            }
        }
    }
}

int padschet_sum(int** arr, int n, int m) 
{
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            sum += arr[i][j]; 
        }
    }
    return sum;
}

void poisk_s(string s) 
{
    for (int i = 0; i < s.length(); i++) 
    {
        cout << s[i]; 
        if (s[i] == 'с') 
        {
            cout << "*";
        }
    }
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
                cout << "Ошибка. Выберите задание 1 или 2: " << endl;
            }
            else {
                validChoice = true;
            }
        } while (!validChoice);
        cin.clear();

        switch (choice)
        {
        case 1:
        {
            int** arr;
            int n, m;
            cout << "Введите размер массива: ";
            cin >> n >> m;
            arr = new int* [n];
            cout << "Введите элементы массива:" << endl;
            for (int i = 0; i < n; i++)
            {
                arr[i] = new int[m];
            }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    cin >> arr[i][j];
            cout << "Массив:" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << "Координата максимального элемента: ";
            poisk_max(arr, n, m);
            cout << endl;
            cout << "Сумма элементов под главной диагональю: " << padschet_sum(arr, n, m) << endl;

            for (int i  = 0; i < n; i++)
            {
                delete[] arr[i];
            }
            delete[] arr; 
            break;
        }

        case 2:
        {
            string s;
            cout << "Введите строку: ";
            cin.ignore();
            getline(cin, s);
            cout << "Новая строка: ";
            poisk_s(s);
            cout << endl;
            break;
        }
        }
        cout << "Введите слово \"" << exitWord << "\", когда хотите закончить программу, если нет, что-то другое: ";
        cin.ignore();
        cin.getline(userInput, sizeof(userInput)); 

        if (strcmp(userInput, exitWord) == 0) { 
            break;
        }
    } while (true); 
}
