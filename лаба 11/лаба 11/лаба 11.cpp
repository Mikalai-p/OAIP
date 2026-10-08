#include <iostream> 
#include <Windows.h>
using namespace std;

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int A; char tmp[33];
	cout << "Введите число " << endl; cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "Число в двоичной системе: " << tmp << endl;
	if ((A & 15) == 0) {
		cout << "Число кратно 16" << endl; 
	}
	else {
		cout << "Число не кратно 16" << endl;
	}
}
