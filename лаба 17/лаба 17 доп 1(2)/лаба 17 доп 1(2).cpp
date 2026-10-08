#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

bool RadokzAdmounimLikam(int** a, int n, int k, int& radokNumber)
{
    for (int i = 0; i < n; i++) {
        bool Admouni = false; 
        for (int j = 0; j < k; j++) {
            if (a[i][j] < 0) {
                Admouni = true;
                break; 
            }
        }
        if (Admouni) { 
            radokNumber = i;
            return true;
        }
    }
    return false; 
}

void YDvaRaziPamenshili(int** a, int n, int k, int slupNumber)
{
    for (int i = 0; i < n; i++) {
        a[i][slupNumber] /= 2;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int k, n;
    cout << "Введите размер матрицы: ";
    cin >> n >> k;

    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[k];
    }

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }

    int radokNumber;
    if (RadokzAdmounimLikam(a, n, k, radokNumber)) {
        cout << "Номер строки с отрицательным элементом: " << radokNumber+1 << endl;

        YDvaRaziPamenshili(a, n, k, radokNumber);

        cout << "Новая матрица:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "В матрице отсутствует строка с отрицательным элементом" << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}
