#pragma once

struct AAA {
    int x;
    void print();
};

namespace heap {
    enum CMP {
        LESS = -1, EQUAL = 0, GREAT = 1
    };

    struct Heap {
        int size;
        int maxSize;
        void** storage;              // Данные    
        CMP(*compare)(void*, void*);

        // Конструктор
        Heap(int maxsize, CMP(*f)(void*, void*)) {
            size = 0;
            storage = new void* [maxSize = maxsize];
            compare = f;
        };

        // Методы для работы с индексами
        int left(int ix);
        int right(int ix);
        int parent(int ix);

        // Проверки
        bool isFull() const {
            return (size >= maxSize);
        };
        bool isEmpty() const {
            return (size <= 0);
        };

        // Сравнение элементов
        bool isLess(void* x1, void* x2) const {
            return compare(x1, x2) == LESS;
        };
        bool isGreat(void* x1, void* x2) const {
            return compare(x1, x2) == GREAT;
        };
        bool isEqual(void* x1, void* x2) const {
            return compare(x1, x2) == EQUAL;
        };

        // Основные операции
        void swap(int i, int j);
        void heapify(int ix);
        void insert(void* x);
        void* extractMax();
        void* extractMin();          // Новая функция: удаление минимального
        void* extractI(int i);      // Новая функция: удаление i-го элемента
        Heap unionHeap(const Heap& other); // Новая функция: объединение куч

        // Вывод
        void scan(int i) const;
    };

    Heap create(int maxsize, CMP(*f)(void*, void*));
}