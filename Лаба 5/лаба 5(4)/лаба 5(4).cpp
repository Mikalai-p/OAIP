#include <iostream> 
#include <cmath> 

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    double a, b, c, d, x1, x2;
    cout << "Введите a\n";
    cin >> a;
    cout << "Введите b\n";
    cin >> b;
    cout << "Введите c\n";
    cin >> c;

    d = b * b - 4 * a * c;
    if (d < 0) 
        cout << "D < 0, Действительных корней уравнения не существует";
    else
    {
        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }
}