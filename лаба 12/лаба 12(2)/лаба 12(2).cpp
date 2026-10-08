#include <iostream> 
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n, m, z, s1 = 0, s2 = 0;
	cout << "Введите количество чисел в массиве(1): " << endl;
	cin >> n;
	cout << "Введите числа для первого массива: " << endl;
	int a[333];
	for (int i = 0; i < n; i++) {
		cin >> *(a + i);
	}

	cout << "Введите количество чисел в массиве(2): " << endl;
	cin >> m;
	cout << "Введите числа для второго массива: " << endl;
	int b[333];
	for (int i = 0; i < m; i++) { 
		cin >> *(b + i);
	}

	cout << "Введите число, с которым будете сравнивать(z): " << endl;
	cin >> z; 

	for (int i = 0; i < n; i++) { 
		if (*(a + i) < z) {
			s1 += 1;
		}
	}

	for (int i = 0; i < m; i++) { 
		if (*(b + i) < z) {
			s2 += 1;
		}
	}

	if (s2 <= s1) { 
		for (int i = 0; i < m; i++) {
			cout << *(b + i) << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << *(a + i) << " ";
		}
		cout << endl;
	}

	else {
		for (int i = 0; i < n; i++) {
			cout << *(a + i) << " ";
		}
		cout << endl;
		for (int i = 0; i < m; i++) {
			cout << *(b + i) << " ";
		}
		cout << endl;
	}
}
