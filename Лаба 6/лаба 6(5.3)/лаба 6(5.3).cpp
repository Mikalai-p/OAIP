#include <iostream>
#include <cmath>
using namespace std;/*a={0.2, -4, 0.6}*/
void main()
{
	setlocale(LC_CTYPE, "rus");
	float a, m = 16, w, r, j=0.1;
	while (j < 0.5)
	{
		for (int n = 0; n < 3; n++)
		{
			printf("Введите a = ");
			scanf_s("%f", &a);
			w = tan(a / 3) + exp(a / m);
			r = 0.9 * sqrt(w + j) + abs(pow(a, 2) - 1);
			printf("a = %5.2f\t", a);
			printf(" r = %5.2f\n", r);
		}
		j = j + 0.1;
	}
}