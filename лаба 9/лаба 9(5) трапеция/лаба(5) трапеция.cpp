#include <iostream>
void main()
{
	using namespace std;
	setlocale(LC_ALL, "rus");
	int  n = 200;
	double h, x, s = 0, a = 1, b = 3;
	h = (b - a) / n;/*0.01*/
	x = a; /*1*/
	for (x; x <= (b - h); x = x + h)
	{
		s = s + h * ((sin(x) + 1) + (sin(x + h)+1))/2;
		x = x + h;
	}
	cout << "s = " << s << endl;
}