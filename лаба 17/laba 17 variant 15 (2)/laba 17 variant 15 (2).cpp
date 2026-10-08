#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int i, j;
    const int n = 3, m = 3;
    double  sum = 0, massiv[n][m], st = 0;
    int ind[n];
    cout << (" Введите элементы матрицы\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> massiv[i][j];

    for (i = 0; i < n; i++) {
        cout << "\n";
        for (j = 0; j < m; j++)
            cout << ' ' << massiv[i][j];
    }
    cout << endl;
    int k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (massiv[i][j] > 0) {
                ind[k] = i;
                k++;
                break;
            }
    
    for (j = 0; j < k; j++)
        for (i = 0; i < m; i++) {
         {
            if (massiv[i][ind[j]] < 0) {
                massiv[i][ind[j]] = abs(massiv[i][ind[j]]);
                k = j ;

            }
        }


    }
    for (i = 0; i < n; i++) {
        cout << "\n";
        for (j = 0; j < m; j++)
            cout << ' ' << massiv[i][j];
    }

}