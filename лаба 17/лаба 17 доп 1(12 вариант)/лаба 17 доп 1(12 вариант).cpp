#include <iostream>
#include <windows.h>
#include <cstdlib> 

using namespace std;

void schetotrizacel(int* element, int pazmer) 
{
	int otrizacel = 0;
	for (int i = 0; i < pazmer; i++) {
		if (*(element + i) < 0) {
			if (i % 2 != 0) {
				otrizacel++;
			}
		}
	}
	cout << "Количество отрицательных элементов, стоящих на четных местах в массиве: " << otrizacel << endl;
}

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	int* a = new int[n];
	cout << "Введите элементы массива: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	schetotrizacel(a, n);
}
