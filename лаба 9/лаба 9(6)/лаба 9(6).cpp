#include <iostream>
int main()/*2x+x^3-7*/
{
	using namespace std;
	setlocale(LC_ALL, "RUS");
	double e = 0.0001, x = 0, a = 1, b = 3;
	do {
		x = (a + b) / 2; 
		if ((2*x+pow(x, 3) - 7) * (2 * a + pow(a, 3) - 7) <= 0)
		{ 
			b = x;
		}
		else {
			a = x; 
		}
	} while (abs(b-a) >  e); 
	cout << "x = " << x << endl;
	return 0;
}