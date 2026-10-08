#include <iostream>
#include <vector>
#include <chrono> // Для измерения времени
#include <functional> // Для std::function

using namespace std;

// Размер хеш-таблицы
const int hashTableSize = 16; // Можно изменить на 32, 64, 128

// Хеш-функция
int hashFunction(int key) {
    return key % hashTableSize;
}

// Функция разрешения коллизий (линейная проба)
int resolveCollision(int key, int i) {
    return (hashFunction(key) + i) % hashTableSize;
}

// Класс хеш-таблицы
class HashTable {
private:
    vector<int> table;
    int size;

public:
    HashTable(int size) : table(size, -1), size(0) {}

    // Вставка элемента
    void insert(int key) {
        if (size == table.size()) {
            cout << "Хеш-таблица переполнена!\n";
            return;
        }

        int index = hashFunction(key);
        int i = 0;
        while (table[resolveCollision(key, i)] != -1 && i < table.size()) {
            i++;
        }
        if (i < table.size()) {
            table[resolveCollision(key, i)] = key;
            size++;
        }
        else {
            cout << "Нет места для вставки ключа " << key << "\n";
        }
    }

    // Поиск элемента
    bool search(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (i < table.size()) {
            if (table[resolveCollision(key, i)] == key) {
                return true;
            }
            i++;
        }
        return false;
    }

    // Удаление элемента
    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (i < table.size()) {
            if (table[resolveCollision(key, i)] == key) {
                table[resolveCollision(key, i)] = -1;
                size--;
                return;
            }
            i++;
        }
    }

    // Вывод содержимого таблицы
    void display() {
        for (int i = 0; i < table.size(); ++i) {
            cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};

// Измерение времени выполнения
double measureTime(std::function<void()> func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int main() {
    setlocale(LC_ALL, "Rus");

    // Создание хеш-таблицы
    HashTable ht(hashTableSize);

    // Добавление элементов
    vector<int> keys = { 12, 15, 124, 144, 123, 87, 65, 23, 9, 55, 532, 1234, 84, 1111, 0 };
    for (int key : keys) {
        ht.insert(key);
    }

    // Вывод содержимого таблицы
    cout << "Содержимое хеш-таблицы:\n";
    ht.display();

    // Поиск элементов
    cout << "\nПоиск элементов:\n";
    for (int key : keys) {
        if (ht.search(key)) {
            cout << "Ключ " << key << " найден.\n";
        }
        else {
            cout << "Ключ " << key << " не найден.\n";
        }
    }

    // Удаление элементов
    cout << "\nУдаление элементов:\n";
    for (int key : keys) {
        ht.remove(key);
        cout << "Удаляем ключ " << key << ". ";
        if (ht.search(key)) {
            cout << "Ключ " << key << " все еще существует.\n";
        }
        else {
            cout << "Ключ " << key << " успешно удален.\n";
        }
    }

    // Измерение времени поиска
    cout << "\nИзмерение времени поиска:\n";
    for (int key : keys) {
        double time = measureTime([&]() { ht.search(key); });
        cout << "Время поиска ключа " << key << ": " << time << " мс\n";
    }

    return 0;
}