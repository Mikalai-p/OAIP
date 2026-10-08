#include <iostream>
using namespace std;

int fmin(int n, ...) {
    int* p = &n;
    int min = 10000;
    for (int i = 0; i < n; i++) {
        *(++p);
        *(++p);
        if (*p < min) {
            min = *p;
        }
    }
    return min;
}

int main()
{
    setlocale(LC_CTYPE, "RU");
    cout << "Минимальное число: " << fmin(4, 45, -9, 4, 78) << endl;
    cout << "Минимальное число: " << fmin(6, 45, 87, -5, 10, 7, 4) << endl;
    cout << "Минимальное число: " << fmin(5, 1, 0, 65, -8, 57) << endl;
    return 0;
}