#include <iostream>
int main()/*sin(x)+1, */
{
	using namespace std;
	setlocale(LC_CTYPE, "rus");
	int n = 200, i =1;
	double h, x, s1 = 0, s2 = 0, s, a = 1, b = 3;
	h = (b - a) / (2 * n);/*0.005*/
	x = a + 2 * h;/*1.01*/
	for (i; i < n; i++)
	{
		s2 = s2 + (sin(x) + 1);
		x = x + h;
		s1 = s1 + (sin(x) + 1);
		x = x + h;
		i = i + 1;
	}
	s = (h / 3) * ((sin(a) + 1) + 4 * (sin(a + h) + 1) + 4 * s1 + 2 * s2 + (sin(b) + 1));
	cout << s << endl;
}