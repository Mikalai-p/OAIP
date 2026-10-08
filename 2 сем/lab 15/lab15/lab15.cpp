#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <random> // Для более надежного генератора случайных чисел

using namespace std;

// Функция генерации случайного массива
void generateRandomArray(vector<long int>& arr, int size) {
    static default_random_engine generator(time(0)); // Статический генератор случайных чисел
    uniform_int_distribution<long int> distribution(0, 10000000); // Расширенный диапазон 0-10000000

    for (int i = 0; i < size; ++i) {
        arr.push_back(distribution(generator));
    }
}

// Сортировка пузырьком
void bubbleSort(vector<long int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) { // Сортировка по убыванию
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Пирамидальная сортировка
void heapify(vector<long int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<long int>& arr) {
    int n = arr.size();

    // Построение кучи (переворот)
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Извлечение элементов из кучи
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Главная функция
int main() {
    setlocale(LC_ALL, "rus");
    vector<int> sizes = { 1000, 2000, 3000, 4000, 5000 };

    for (int size : sizes) {
        cout << "Размер массива: " << size << endl;

        // Генерация массивов A и B
        vector<long int> A, B;
        generateRandomArray(A, size);
        generateRandomArray(B, size);

        // Нахождение максимального элемента в B
        long int maxB = *max_element(B.begin(), B.end());

        // Формирование массива C
        vector<long int> C;
        for (long int num : A) {
            if (num > maxB) {
                C.push_back(num);
            }
        }

        // Отладочная информация
        cout << "Максимальный элемент в B: " << maxB << endl;
        if (!C.empty()) {
            cout << "Минимальный элемент в C: " << *min_element(C.begin(), C.end()) << endl;
            cout << "Максимальный элемент в C: " << *max_element(C.begin(), C.end()) << endl;
        }
        else {
            cout << "Массив C пустой" << endl;
        }

        // Сортировка пузырьком
        vector<long int> C_bubble = C;
        auto startBubble = chrono::high_resolution_clock::now();
        bubbleSort(C_bubble);
        auto endBubble = chrono::high_resolution_clock::now();
        auto durationBubble = chrono::duration_cast<chrono::milliseconds>(endBubble - startBubble).count();

        // Пирамидальная сортировка
        vector<long int> C_heap = C;
        auto startHeap = chrono::high_resolution_clock::now();
        heapSort(C_heap);
        auto endHeap = chrono::high_resolution_clock::now();
        auto durationHeap = chrono::duration_cast<chrono::milliseconds>(endHeap - startHeap).count();

        // Вывод результатов
        cout << "Количество элементов в C: " << C.size() << endl;
        cout << "Время сортировки пузырьком: " << durationBubble << " мс" << endl;
        cout << "Время пирамидальной сортировки: " << durationHeap << " мс" << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}