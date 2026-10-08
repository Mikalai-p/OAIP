#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    int f;
    cout << "Введите число f = ";
    cin >> f; // Ввод числа f

    if (f < 1 || f > 18) {
        cout << "Нет подходящих чисел." << std::endl;
        return 0;
    }

    int count = 0;
    for (int a = 1; a <= f; ++a) {
        int b = f - a;
        if (b > 0 && b < 10) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
