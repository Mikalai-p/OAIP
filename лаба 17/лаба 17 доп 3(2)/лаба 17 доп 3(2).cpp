#include <iostream>
#include <windows.h>
#include <cstdlib> 

using namespace std;

void PoshukPounasczuStanouchagaSlupka(int** a, int n, int k) 
{
    bool StanouchiSlupokZnoidzen = false;  

    for (int j = 0; j < k; j++) {
        bool allStanouchiua = true;

        for (int i = 0; i < n; i++) {
            if (a[i][j] <= 0) { 
                allStanouchiua = false;
                break;
            }
        }

        if (allStanouchiua) {
            StanouchiSlupokZnoidzen = true;

            if (j > 0) {
                for (int i = 0; i < n; i++) {
                    if (a[i][j - 1] < 0) { 
                        a[i][j - 1] = -a[i][j - 1];
                    }
                    else if (a[i][j - 1] > 0) { 
                        a[i][j - 1] = -a[i][j - 1];
                    }
                }
            }

            break;
        }
    }

    if (StanouchiSlupokZnoidzen) {
        cout << "В матрице есть столбец, в котором все элементы положительные, поэтому знаки прошлого изменены на противоположные" << endl;
    }
    else {
        cout << "В матрице нет столбца, все элементы которого положительные" << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, k;
    cout << "Введите размер матрицы: ";
    cin >> n >> k;

    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[k];
    }

    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }

    PoshukPounasczuStanouchagaSlupka(a, n, k);

    cout << "Новая матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}
