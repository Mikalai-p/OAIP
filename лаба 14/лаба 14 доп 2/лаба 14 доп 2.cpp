#include <iostream>
#include <Windows.h>
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n, m;
	int A[333][333];
	cout << "Введите размер массива: ";
	cin >> n;
	for (int i = 0; i < n; i++) { 
		m = i + 1;
		for (int j = 0; j < n; j++) {
			A[i][j] = m;
			m += 1;
			if (m > n) { 
				m = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
