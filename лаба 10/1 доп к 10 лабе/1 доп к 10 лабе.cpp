#include <iostream>

#include <Windows.h>

#include <ctime> // Падключаем для выкарыстання функцыі time

using namespace std;


int main() {


	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);


	const int n = 333;

	int k, a[n];

	cout << "Увядзіце памер масіва (<333) ";

	cin >> k;

	if (k > n) {

		cout << "Памылка: перавышэнне максімальнага памеру масіва";

		return 0;

	}


	srand(unsigned(time(NULL)));

	for (int i = 0; i < k; i++) { // Фарміруем масіў з выпадковых лікаў

		a[i] = rand() % 99;

	}

	for (int i = 0; i < k; i++) {

		cout << a[i] << " ";

		if ((i + 1) % 7 == 0) { // Групіруем па сем, каб тыдні былі добра бачныя

			cout << endl;

		}

	}

	cout << endl;


	int maxSum = 0; // Найбольшая колькасць ападкаў

	int maxWeek = 0; // Нумар тыдня з найбольшай колькасцью ападкаў


	for (int i = 0; i <= k - 7; i++) {

		int sum = 0; // Сума ападкаў на бягучым тыдні

		for (int j = i; j < i + 7; j++) {

			sum += a[j];

		}

		if (sum > maxSum) { // Параўноўваем ападкаў бягучага тыдня з найбольшай сумай ападкаў

			maxSum = sum;

			maxWeek = i / 7 + 1;

		}

	}


	cout << "Найбольшая колькасць ападкаў выпала на тыдзень: " << maxWeek << endl;

}