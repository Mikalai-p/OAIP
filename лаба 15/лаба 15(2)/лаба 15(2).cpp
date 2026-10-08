#include <iostream>
#include <windows.h>
#include <cstdlib> 
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n, s = 0;
	cout << "Введите размер массива: " << endl;
	cin >> n;
	cout << "Введите элементы массива: " << endl;
	bool t = false;
	int** a = new int* [n]; 
	for (int i = 0; i < n; i++) {
		a[i] = new int[n]; 
		for (int j = 0; j < n; j++) {
			cin >> a[i][j]; 
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != a[j][i]) { 
				break;
			}
			else if (a[i][j] == a[j][i]) {
				s += 1; 
			}
		}
		if (s == n) { 
			cout << "Индекс равных ряда и столбца = " << i+1<< endl; 
			t = true; 
		}
		s = 0; 
	}
	if (t == false) {
		cout << "Нету ряда и столбца с одинаковым индексом" << endl;
	}
	delete[] a; 
}
