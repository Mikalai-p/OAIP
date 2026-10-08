#include<iostream>
#include<ctime>
#include<cmath>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "размер массива? ";
	int n;
	cin >> n;
	char* a = new char[n], * e = a + n;
	cout << "символы ? ";
	for (char* p = a; p < e; ++p)
		cin >> p;
	for (char* p = a; p < e; ++p)
		e = remove(p + 1, e, *p);
	cout << "результат: ";
	for (char* p = a; p < e; ++p) cout << ' ' << *p;
	delete[] a;
	return 0;
}