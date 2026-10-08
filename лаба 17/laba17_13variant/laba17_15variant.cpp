#include <iostream>
#include<windows.h>
using namespace std;

int minIndex(int* arr, int size) {
	int result = 0;
	for (int i = 1; i < size; i++) {
		if (arr[result] > arr[i])
			result = i;
	}
	return result;

}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int* arr = NULL;
	int size;
	cout << "размер: ";
	cin >> size;
	arr = new int[size];

	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = -100 + rand() % 201;
		cout << arr[i] << " ";
	}
	int minIdx = minIndex(arr, size);
	cout << endl << "минимальный элемент = " << arr[minIdx] << endl;
	if (minIdx == size - 1) {
		cout << "минимальный элемент - последний в массиве.";
	}
	int k = 0;
	for (int i = minIdx + 1; i < size; i++) {
		if (arr[i] < 0)
		{
			k = k + 1;
		}
	}
	cout << k << " " << "отрицательных элементов находится после последнего минимального элемента" << endl;
}