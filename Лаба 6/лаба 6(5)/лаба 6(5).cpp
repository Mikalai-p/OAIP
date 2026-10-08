#include <iostream>
using namespace std;/*j={0.5, 9.1,5}*/

void main()
{
	setlocale(LC_CTYPE, "rus");
	float  a = -1.4, m = 16, j, w, r;
	for (int n = 0; n < 3; n++)
	{
		printf("Введите j = ");
		scanf_s("%f", &j);
		w = tan(a / 3) + exp(a / m);
		r = 0.9 * sqrt(w+j) + abs(pow(a, 2) - 1);
		printf("j=%5.2f\t", j);
		printf("r = %5.2f\n", r);
	}
}