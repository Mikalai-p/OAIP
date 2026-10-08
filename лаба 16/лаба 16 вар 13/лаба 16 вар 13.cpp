#include <iostream>
#include <string> 
#include <Windows.h>

using namespace std;

void SmenaRadov(int** matrix, int k, int n, int a, int b) {
    int aRad, bRad;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            if (matrix[i][j] == a)
            {
                aRad = i;
            }
            if (matrix[i][j] == b)
            {
                bRad = i;
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        int temp = matrix[aRad][j];
        matrix[aRad][j] = matrix[bRad][j];
        matrix[bRad][j] = temp;
    }
    cout << "Новая матрыца: " << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}


void SlovA(const string& sentense) {
    string word;
    for (int i = 0; i <= sentense.length(); i++) {
        char c = sentense[i];

        if (c == ' ' || c == '.' || c == ',' || i == sentense.length()) {
            if (!word.empty() && word.length() >= 2 && word.substr(word.length() - 2) == "ая") {
                cout << word << endl;
            }
            word.clear();
        }
        else {
            word.push_back(c);
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
                cout << "Ошибка. Пожалуйста, выберите 1 или 2: " << endl;
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
            int k, n;
            cout << "Введите размер матрицы(k <=12 и n<=8): ";
            cin >> k >> n;
            if (k <= 12 and n <= 8 and n > 0 and k > 0) 
            {
                int** A = new int* [k];
                cout << "Введите элементы массива: " << endl;
                for (int i = 0; i < k; i++)
                {
                    A[i] = new int[n];
                    for (int j = 0; j < n; j++)
                    {
                        cin >> A[i][j];
                    }
                }
                cout << "Массив:" << endl;
                for (int i = 0; i < k; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << A[i][j] << " ";
                    }
                    cout << endl;
                }

                cout << "Введите 2 значения, которые находятся в вашей матрице(массиве) для смены расположения строк: ";
                int a, b;
                cin >> a >> b;
                SmenaRadov(A, k, n, a, b);
            }
            break;
        }

        case 2:
        {
            string sentences;
            cout << "Введите предложение: ";
            cin.ignore();
            getline(cin, sentences);
            cout << "Слова, в которых последние буквы -ая:" << endl;
            SlovA(sentences);
            break;
        }
        }
        cout << "Введите слово \"" << exitWord << "\", если хотите закончить программу, если нет,то что угодно другое: ";
        cin.ignore();
        cin.getline(userInput, sizeof(userInput));

        if (strcmp(userInput, exitWord) == 0) { 
            break;
        }
    } while (true); 
}
