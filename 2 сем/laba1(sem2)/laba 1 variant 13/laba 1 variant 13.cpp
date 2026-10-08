#include <iostream>
using namespace std;

double f1(double x)
{
    return (5 * x) - 1 + pow(x, 3);
}

double f2(double x)
{
    return pow(x, 2) + (1 / x);
}

double function(double (*f)(double), double a, double b, double e, int maxIterations)
{
    double c;
    int iteration = 0;
    while (b - a >= 2 * e && iteration < maxIterations)
    {
        c = (a + b) / 2;
        if (f(c) == 0)
        {
            return c;
        }
        else
        {
            if (f(a) * f(c) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }
        iteration++;
    }
    cout << "a = " << a << " b = " << b << endl;
    return c;
}

int main()
{
    setlocale(LC_CTYPE, "RU");
    int maxIterations;
    double a, b, c;
    const double e = 0.001;


    cout << "Введите начальное значение a: ";
    cin >> a;
    cout << "Введите начальное значение b: ";
    cin >> b;
    cout << "Введите максимальное количество итераций n: ";
    cin >> maxIterations;

    double root1 = function(f1, a, b, e, maxIterations);
    double root2 = function(f2, a, b, e, maxIterations);

    cout << "Корень уравнения 5x - 1 + x^3: " << root1 << endl;
    cout << "Корень уравнения x^2 + 1/x = 0: " << root2 << endl;
    return 0;
}