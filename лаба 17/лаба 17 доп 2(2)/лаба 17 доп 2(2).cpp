#include <iostream>
#include <windows.h>
#include <cstdlib> 

using namespace std;

void PoshukNuliouIPeratvarenneAdmounixLikau(int** a, int n, int k) 
{
    bool NuliYRadkax = true; 

    for (int i = 0; i < n; i++) {
        bool NauavnostNulia = false; 
        bool NauavnostAdmounaga = false; 


        for (int j = 0; j < k; j++) {
            if (a[i][j] == 0) { 
                NauavnostNulia = true;
            }
            if (a[i][j] < 0) { 
                NauavnostAdmounaga = true;
                a[i][j] = 0; 
            }
        }

        if (!NauavnostNulia) { 
            NuliYRadkax = false;
        }
    }

    if (!NuliYRadkax) {
        cout << "Не все строки имеют нулевой элемент. Все отрицательные преобразованы в нулевые" << endl;
    }
    else {
        cout << "Все строки имеют хотя бы один нулевой элемент" << endl;
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

    PoshukNuliouIPeratvarenneAdmounixLikau(a, n, k);

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
