#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Rus");
	int k;
	cout << "Введите число k" << endl;
	cin >> k;
	if (k > 9)
	{
		cout << "ошибка" << endl;
	}
	if (k > 4)
	{
		cout << "Мне " << k << " лет" << endl;
	}
	if (k < 5)
	{
		if (k > 1)
		{
			cout << "Мне " << k << " года" << endl;
		}
	}
	if (k == 1)
	{
		cout << "Мне " << k << " год" << endl;
	}
	if (k < 1)
	{
		cout << "Ошибка" << endl;
	}
}