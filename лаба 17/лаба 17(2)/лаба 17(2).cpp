#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

void poisk_sum(int** a, int n) {
    bool naidenotrizacel = false; 
    int admouniRow = -1; 

    for (int i = 0; i < n; i++) {
        bool otrizacel = false;

        for (int j = 0; j < n; j++) {
            if (a[i][j] < 0) {
                otrizacel = true; 
                admouniRow = i;
                break;
            }
        }

        if (otrizacel) {
            naidenotrizacel = true; 
            break;
        }
    }

    if (naidenotrizacel) {
        cout << "В матрице есть отрицательный элемент в строке " << admouniRow+1 << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = 0; j < n; j++) {
                sum += a[i][j];
            }

            cout << "Сумма элементов строки с индексом " << i+1 << " равна " << sum << endl;
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    int** a = new int* [n];
    cout << "Введите элементы матрицы: " << endl;

    for (int i = 0; i < n; i++) {
        a[i] = new int[n];

        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << endl;
    poisk_sum(a, n);

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a; 

    return 0;
}
