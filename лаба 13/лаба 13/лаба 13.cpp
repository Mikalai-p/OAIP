#include <iostream>
#include <Windows.h>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i = 0;
	char a[333];
	cout << "Введите начальный текст: ";
	gets_s(a);
	cout <<"Полученный текст: ";
	while (a[i] != '\0') { 
		if (a[i + 1] == ' ' or a[i + 1] == '\0') {
			cout << a[i];
		}
		i++; 
	}
}
