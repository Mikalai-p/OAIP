#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int  num = -1, s = 0;
    double n;
    bool t = false;
    int A[333][333];
    cout << "Введите размер массива: ";
    cin >> n;
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    double average = 0.0;
    bool columnProcessed = false; 
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 0; j < n; j++) {
            if (A[j][i] >= 0) {
                break;
            }
            else {
                s += 1;
            }
            if (s == n) {
                t = true;
                num = i;
                break;
            }
        }
        if (t == true)
        {
            if (!columnProcessed) { 
                cout << "Это столбец номер " << num + 1 << endl;
                for (int i = 0; i < n; i++) { 
                    s += A[i][num];
                }
                average = (s/ n)-1;
                cout << "Среднее арифметическое равно " << average << endl;
                for (int i = 0; i < n; i++)
                for (int j=0;j<n;j++) { 
                    A[i][j] -= average;
                }
                columnProcessed = true;
            }
        }
    }
    if (t == false) {
        cout << "Такого столбца нет" << endl;
    }

    cout << "Новый массив:" << endl;
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
}
