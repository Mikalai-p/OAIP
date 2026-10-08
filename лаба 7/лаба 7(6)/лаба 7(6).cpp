#include <iostream>
#include <cmath>
using namespace std;/*t={5;1;-3;9;-1}*/
void main()
{
	setlocale(LC_CTYPE, "rus");
	double a = -4.2, t, i = 4, d, g, c, b;
	for (int n = 0; n < 5; n++)
	{
		cout << "Введите t = ";
		cin >> t;
		d = i + 2 * t * (1 + sqrt(3 * pow(a, 2)));
		g = t * (t + i);
		cout << "d = " << d << endl;
		cout << "g = " << g << endl;
		if (d >= g)
		{
			b = t * i;
			cout << "b = " << b << endl;
		}
		else
		{
			c = exp(t - d) + 9;
			cout << "c = " << c << endl;
		}
	}
}