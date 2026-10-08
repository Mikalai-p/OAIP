#include <iostream>
using namespace std;
void main()
{
	float a = -1.4, m = 16, w, r, j = 1.8;
	while (j < 3.2)
	{
		w = tan(a / 3) + exp(a / m);
		r = 0.9 * sqrt(w + j) + abs(pow(a, 2) - 1);
		cout << "j=" << j << "\t";
		cout << " r=" << r << endl;
		j = j + 0.2;
	}
}