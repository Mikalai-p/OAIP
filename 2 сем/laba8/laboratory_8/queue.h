#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Структура узла очереди
typedef struct Node {
    double data;
    struct Node* next;
} Node;

// Структура очереди
typedef struct Queue {
    Node* front;
    Node* rear;
    double size;     // Текущий размер очереди
    int capacity; // Максимальный размер очереди
} Queue;

// Функции работы с очередью
Queue* createQueue(int capacity);
bool isEmpty(Queue* queue);
bool isFull(Queue* queue);
void enqueue(Queue* queue, double data);
double dequeue(Queue* queue);
double peek(Queue* queue);
void displayQueue(Queue* queue);
void clearQueue(Queue* queue);

// Дополнительные функции
void splitQueue(Queue* queue, Queue* queue1, Queue* queue2);
double findMin(Queue* queue);
double findMax(Queue* queue);

#endif