#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	double d, b = -6, g = 2, c=0, x1, x2, a, S;
	d = b * b - 4 * g *c;
	cout << "Дискриминант= " << d <<endl;
	if (d > 0)
	{
		x1 = ((-b) + sqrt(d)) / (2 * g);
		x2 = ((-b) - sqrt(d)) / (2 * g);
		cout << "x1= " << x1 << endl;
		cout << "x2= " << x2 << endl;
	}
	if (d == 0)
	{
		x1 = ((-b) / (2 * g));
		cout << "x1=x2= " << x1 << endl;
	}
	if (d < 0)
	{
		cout << "D<0, значит нет корней" << endl;
	}
	if (x1 > 0)
	{
		a = 2 * x1;
		S = a * x1;
		cout << "S= " << S;
		cout << " a= " << a;
	}
	if (x1 <= 0)
	{
		cout << "Не удовлетворяет условию" << endl;
	}
	if (x2 > 0)
	{
		a = 2 * x2;
		S = a * x2;
		cout << "S= " << S <<endl;
		cout << " a= " << a <<endl;
	}
	cout << " " << endl;
	if (x2 <= 0)
	{
		cout << "Со вторым корнем вычисления не имеют смысла по условию" << endl;
	}
}