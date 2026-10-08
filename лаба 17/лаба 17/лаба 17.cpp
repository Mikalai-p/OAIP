#include <iostream>
#include <windows.h>
#include <cstdlib> 
using namespace std;

int* udalyem_neczot_func(int* a, int& n) {
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			for (int j = i; j < n; j++) {
				a[j] = a[j + 1];
			}
			n--;
			i--;
		}
	}
	return a;
}
int main() { 

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
	udalyem_neczot_func(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
}
