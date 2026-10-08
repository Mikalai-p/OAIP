#include <iostream> 
#include <Windows.h>
using namespace std;

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char tmp[33]; 
	int A, B, n, p, m, q, maskA = 0, maskB = 0;
	cout << "Введите число A= "; cin >> A;
	_itoa_s(A, tmp, 2); 
	cout << "A= " << tmp << endl;
	cout << "Введите количество изменяемых битов A(n): " << endl;
	cin >> n;
	cout << "Введите начало позиции изменения(p): " << endl;;
	cin >> p;
	cout << "Введите число B= "; cin >> B;
	_itoa_s(B, tmp, 2); 
	cout << "B= " << tmp << endl;
	cout << "Введите количество изменяемых битов B(m)" << endl;
	cin >> m;
	cout << "Введите начало позиции изменения(q): " << endl;
	cin >> q;
	for (int i = p - 1; i < p + n - 1; i++) { 
		maskA += pow(2, i);    
	}
	A = (A & ~maskA); 
	p = q - p; 
	if (p < 0) { 
		maskA = maskA >> abs(p);
	}
	else if (p > 0) { 
		maskA = maskA << p;
	}
	for (int i = q - 1; i < q - 1 + m; i++) {
		maskB += pow(2, i);
	}
	B = (B & ~maskB); 
	B = (B | maskA);  
	_itoa_s(A, tmp, 2); 
	cout << "Число A= " << tmp << endl;
	_itoa_s(B, tmp, 2);
	cout << "Число B= " << tmp << endl;
}
