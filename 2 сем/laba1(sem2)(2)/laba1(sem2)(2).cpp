#include <iostream>
using namespace std;

int function(int row, int column, ...) {
    int* p = &column;
    int min = INT_MAX;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            *(++p);
            *(++p);
            if (*p < min)
                min = *p;
        }
    }
    return min;
}

int main()
{
    setlocale(LC_CTYPE, "RU");
    cout << "Минимальное значение в матрице: " << function(3, 3, 1, -100, 3, 4, 21, 6, 7, 84, 9) << endl;
    cout << "Минимальное значение в матрице: " << function(2, 2, 100, 84, -7, 0) << endl;
    cout << "Минимальное значение в матрице: " << function(3, 3, 45, -9, 23, 0, 1, 75, -567, 12, 23) << endl;
}