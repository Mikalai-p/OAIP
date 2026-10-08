#include <iostream>
#include <Windows.h>
using namespace std;

void main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	int A[333][333];
	cout << "Введите размер массива: ";
	cin >> n;
	cout << "Введите элементы массива: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	int max = A[0][0];
	int rad = 0;  
	for (int i = 1; i < n; i++) { 
		if (A[i][i] > max) {
			max = A[i][i];
			rad = i;
		}
	}
	cout << "Ряд, в котором находится наибольший элемент главной диагонали: " << endl;
	for (int i = 0; i < n; i++) {
		cout << A[rad][i] << ' ';
	}
}
