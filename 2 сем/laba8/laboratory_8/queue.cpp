#include "queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits> 
#include <iomanip>

using namespace std;

// Создание новой очереди
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        perror("Ошибка выделения памяти для очереди");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// Проверка очереди на пустоту
bool isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Проверка очереди на заполненность
bool isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Добавление элемента в очередь
void enqueue(Queue* queue, double data) {
    if (isFull(queue)) {
        printf("Очередь полна, нельзя добавить элемент.\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Ошибка выделения памяти для нового узла");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// Удаление элемента из очереди
double dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Очередь пуста, нельзя удалить элемент.\n");
        return -1.0; // Или другое значение по умолчанию
    }

    Node* temp = queue->front;
    double data = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL; // Если очередь стала пустой
    }

    free(temp);
    queue->size--;
    return data;
}

// Получение первого элемента очереди
double peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Очередь пуста, нет первого элемента.\n");
        return -1.0; // Или другое значение по умолчанию
    }
    return queue->front->data;
}

// Вывод очереди на экран
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Очередь пуста.\n");
        return;
    }

    Node* current = queue->front;
    printf("Содержимое очереди (от начала к концу):\n");
    while (current != NULL) {
        cout << "->" << fixed << setprecision(4)<< current->data;
        current = current->next;
    }
    printf("\n");
}

// Очистка очереди
void clearQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

// Нахождение минимального элемента в очереди
double findMin(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Очередь пуста, нет минимального элемента.\n");
        return -1; // Или другое значение по умолчанию
    }

    Node* current = queue->front;
    double minVal = current->data;
    while (current != NULL) {
        if (current->data < minVal) {
            minVal = current->data;
        }
        current = current->next;
    }
    return minVal;
}

// Нахождение максимального элемента в очереди
double findMax(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Очередь пуста, нет максимального элемента.\n");
        return -1; // Или другое значение по умолчанию
    }

    Node* current = queue->front;
    double maxVal = current->data;
    while (current != NULL) {
        if (current->data > maxVal) {
            maxVal = current->data;
        }
        current = current->next;
    }
    return maxVal;
}

// Разделение очереди на две (Queue1 с минимальными элементами, Queue2 с максимальными)
void splitQueue(Queue* queue, Queue* queue1, Queue* queue2) {
    bool useMin = true; // Флаг для выбора между минимальным и максимальным элементом

    while (!isEmpty(queue)) {
        if (useMin) {
            double minVal = findMin(queue);

            // Находим и удаляем все вхождения минимального значения из исходной очереди
            Queue tempQueue;
            tempQueue.front = tempQueue.rear = NULL;
            tempQueue.size = 0;
            tempQueue.capacity = queue->capacity; // Важно, чтобы временная очередь имела ту же емкость, что и исходная.

            while (!isEmpty(queue)) {
                double data = dequeue(queue);
                if (data != minVal) {
                    enqueue(&tempQueue, data); // Используем временную очередь, чтобы не потерять элементы
                }
                else {
                    enqueue(queue1, data); // Помещаем минимальный элемент в queue1
                }
            }
            // Скопируйте элементы обратно в исходную очередь
            while (!isEmpty(&tempQueue)) {
                enqueue(queue, dequeue(&tempQueue));
            }
            cout << "Минимальное значение " << minVal << " перемещено в Queue1" << endl;

        }
        else {
            double maxVal = findMax(queue);

            // Находим и удаляем все вхождения максимального значения из исходной очереди
            Queue tempQueue;
            tempQueue.front = tempQueue.rear = NULL;
            tempQueue.size = 0;
            tempQueue.capacity = queue->capacity; // Важно, чтобы временная очередь имела ту же емкость, что и исходная.
            while (!isEmpty(queue)) {
                double data = dequeue(queue);
                if (data != maxVal) {
                    enqueue(&tempQueue, data); // Используем временную очередь, чтобы не потерять элементы
                }
                else {
                    enqueue(queue2, data); // Помещаем максимальный элемент в queue2
                }
            }

            // Скопируйте элементы обратно в исходную очередь
            while (!isEmpty(&tempQueue)) {
                enqueue(queue, dequeue(&tempQueue));
            }
            cout << "Максимальное значение " << maxVal << " перемещено в Queue2" << endl;
        }
        useMin = !useMin; // Переключаем флаг
    }
}