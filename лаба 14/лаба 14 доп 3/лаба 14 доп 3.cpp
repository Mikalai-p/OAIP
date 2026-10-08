#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    int A[333][333];
    cout << "Введите размер матрицы: ";
    cin >> n;

    vector<vector<float>> a(n, vector<float>(n)); // Робім двумерны вектар памерам n x n, каб рабіць радкі праз часавы вектар vector<float>(n) 

    cout << "Введите элементы матрицы: " << endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j]; // Выводзім, каб заўважыць розніцу
        }

    for (int k = 0; k < n; k++) {
        int mai = 0, maj = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (((j == i) && (j >= k)) || (j != i)) { // Глядзім, каб элемент не стаяў вышэй на галоўнай дыяганалі
                    if (a[i][j] > a[mai][maj]) { // Калі бягучы элемент a[i] [j] большы за бягучы максімальны элемент a[mai] [mai], мы абнаўляем індэксы mi і mj для захоўвання індэксаў максімальнага элемента
                        mai = i;
                        maj = j;
                    }
                }
            }
        }
        swap(a[k][k], a[mai][maj]); // Ставім найбольшы элемент на галоўную дыяганаль
    }

    cout << "Новая матрица: " << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
