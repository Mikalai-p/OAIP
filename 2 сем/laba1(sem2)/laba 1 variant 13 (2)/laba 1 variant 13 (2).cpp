#include <iostream>

using namespace std;

void funSum(int a, int n, int m, int* first, ...) {
    int** p = reinterpret_cast<int**>(&first);
    for (int k = 0; k < a; k++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j < i) {
                    sum += **p;
                }
                ++(*p);
            }
        }
        cout << sum << '\n';
        p++;
    }
    cout << '\n';
}

int main() {
    setlocale(LC_ALL, "rus");

    int a[5][5];
    cout << "матрица A:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            a[i][j] = rand() % 100 + 1;
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    int b[5][5];
    cout << "матрица B:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            b[i][j] = rand() % 100 + 1;
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }

    

    cout << "сумма: " << endl;
    funSum(2, 5, 5, (int*)a, (int*)b);

    
    return 0;
}