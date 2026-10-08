#include <iostream>
#include <windows.h>
#include <cstdlib> 
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "Введите размер массива: " << endl;
	cin >> n;
	cout << "Введите элементы массива: " << endl;
	bool t = false; 
	int* a = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		cin >> *(a + i);
	}

	for (int i = 0; i < n; i++) {
		if (*(a + i) == 0) { 
			cout << "Элемент с индексом " << i+1 << " равен 0" << endl; 
			t = true; 
			break;
		}
	}

	if (t == false) {
		cout << "В массиве нет элементов равных 0" << endl;
	}

	free(a); 

	return 0;
}
