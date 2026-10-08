#include <stdio.h>
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int capacity, choice;
    double data;

    printf("Введите максимальный размер очереди: ");
    scanf_s("%d", &capacity);

    Queue* queue = createQueue(capacity);
    Queue* queue1 = createQueue(capacity);
    Queue* queue2 = createQueue(capacity);

    do {
        printf("\nМеню:\n");
        printf("1. Добавить элемент в очередь\n");
        printf("2. Удалить элемент из очереди\n");
        printf("3. Посмотреть первый элемент очереди\n");
        printf("4. Вывести очередь на экран\n");
        printf("5. Разделить очередь\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            cout << "Введите значение для добавления в очередь: ";
            cin >> data;
            enqueue(queue, data);
            break;
        case 2:
            data = dequeue(queue);
            if (data != -1) {
                cout << "Удаленный элемент: " << data;
            }
            break;
        case 3:
            data = peek(queue);
            if (data != -1) {
                cout << "Первый элемент: " << data;
            }
            break;
        case 4:
            displayQueue(queue);
            break;
        case 5:
            splitQueue(queue, queue1, queue2);
            cout << "Queue1: " << endl;
            displayQueue(queue1);
            cout << "Queue2: " << endl;
            displayQueue(queue2);
            break;
        case 0:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    clearQueue(queue);
    clearQueue(queue1);
    clearQueue(queue2);
    free(queue);
    free(queue1);
    free(queue2);

    return 0;
}