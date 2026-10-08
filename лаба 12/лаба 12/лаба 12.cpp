#include <iostream> 
#include <Windows.h>
using namespace std;

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "Введите количество чисел в массиве: " << endl;
	cin >> n;
	bool t = false;
	cout << "Введите числа для массива: " << endl;
	int a[333];
	for (int i = 0; i < n; i++) { 
		cin >> *(a + i);
	}
	for (int j = 1; j < 333; j++) { 
		for (int i = 0; i < n; i++) { 
			if (*(a + i) == j) {
				 t = true;
				break;
			}
		}

		if (t == false) { 
			cout << "Наименьшее натуральное число, вне массива: " << j;
			break;
		}
		else {
			t = false;  
		}
	}
}
