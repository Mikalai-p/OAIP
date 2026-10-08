#include <iostream>

#include <Windows.h>

#include <ctime> // Падключаем для выкарыстання функцыі time

using namespace std;


int main() {


	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);


	const int n = 333;

	int k, a[n];

	int count = 0;

	cout << "Увядзіце памер масіва (<333) ";

	cin >> k;

	if (k > n) {

		cout << "Памылка: перавышэнне максімальнага памеру масіва";

		return 0;

	}


	srand((unsigned)time(NULL));

	for (int i = 0; i < k; i++) { // Фарміруем масіў з выпадковых лікаў

		a[i] = rand() % 99;

	}

	for (int i = 0; i < k; i++) { // Вывад першапачатковага масіва, каб потым заўважыць розніцу

		cout << a[i] << " ";

	}

	cout << endl;


	for (int i = 0; i < k - 1; i++) // Падлік колькасці суседніх элементаў з аднолькавымі значэннямі

	{

		if (a[i] == a[i + 1]) {

			count++;

		}

	}


	cout << "Колькасць пар суседніх элементаў з аднолькавымі значэннямі: " << count << endl;


	return 0;

}