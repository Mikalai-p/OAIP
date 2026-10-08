#include <iostream>
#include <windows.h>
#include <cstdlib> 

using namespace std;

void FindMinMaxSum(int* a, int size, int& min, int& max, int& sum) 
{
    min = a[0];
    max = a[0];
    sum = min + max;

    for (int i = 1; i < size; i++) {
        if (a[i] < min) { 
            min = a[i]; 
        }
        if (a[i] > max) { 
            max = a[i];
        }
        sum = min + max; 
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* a = new int[size];

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    int min, max, sum;
    FindMinMaxSum(a, size, min, max, sum);

    cout << "Наименьший: " << min << endl;
    cout << "Наибольший: " << max << endl;
    cout << "Сумма: " << sum << endl;

    delete[] a; 
}
