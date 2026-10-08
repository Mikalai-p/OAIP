#include <iostream> 
#include <cmath>
int main()
{
	double a = 1.5, b = -8.1, j = 4, t = 4 * std::pow(10, -8), s, w, u;
	s = sqrt(t * a / t + 1) + 4 * exp(2 * b);
	w = s * a / (1 + 0.1 * a);
	u = s + j * sqrt(a * a + b * b);
	std::cout << "s=" << s;
	std::cout << " w=" << w;
	std::cout << " u=" << u;
}
