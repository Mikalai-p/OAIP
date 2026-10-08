#include <iostream>
#include "лабораторная 8.h"
using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");
	int n ;
	float a, y, s, q, g, res;
	cout << "Введите n = ";/*n=5*/
	cin >> n;
	cout << "Введите a = ";/*a=5,45*/
	cin >> a;
	cout << "Введите 1.0 res = ";/*res=1.0*/
	cin >> res;
	for (int h = 0; h < n; h++)
	{
		cout << "Введите y = ";/*y={2,1; 7,7; - 4; 9; 5}*/
		cin >> y;
		for (int i = 1; i <= n; i++)
		{
			g = y * i;
			res = res * g;
			q = (4 * res ) / (pow(i, 2) + 1);
		}
		cout << "res = " << res << endl;
		cout << "q = " << q << endl;
		s = 2 * a + q * sin(a);
		cout << "s = " << s << endl;
	}
}