#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

int multiplication(float*, int, int);
int colC(float*, int, float);
int indexMaxArray(float*, int);
string upWord(string, int);

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);

    int n;
    char text[10000];
    int index = 0;
    int sizeText;

    cout << "1. Задание 1(Одномерный массив)" << '\n' << "2. Задание 2(Upper first word)" << endl;
    cin >> n;
    cin.ignore();

    switch (n) {
    case 1:
        float* arr, C;
        int sizeArray;

        cout << "Введите размер массива" << endl;
        cin >> sizeArray;
        arr = new float[sizeArray]; 

        for (int i = 0; i < sizeArray; i++) { 
            cout << "Введите " << i + 1 << " элемент последовательности: ";
            cin >> arr[i];
        }

        cout << "Введите элемент C: " << endl;
        cin >> C;

        cout << "Количество элементов, больших C: " << colC(arr, sizeArray, C) << endl; 

        index = indexMaxArray(arr, sizeArray) + 1; 

        cout << "multiplication: " << multiplication(arr, sizeArray, index) << endl; 

        for (int i = 0; i < sizeArray; i++) {
            cout << arr[i] << ' ';
        }

        delete[] arr;

        break;
    case 2:

        cout << "Введите строку: " << endl;
        cin.getline(text, 10000);
        sizeText = strlen(text);

        cout << upWord(text, sizeText);
        break;

    default:
        cout << "Ошибка(" << "\nВыберите верный вариант!" << endl;
    }
    return 0;
}

int colC(float* arr, int size, float c) {
    int col = 0;
    for (int i = 0; i < size; i++) {
        if (c < arr[i]) {
            col++; 
        }
    }
    return col; 
}

int indexMaxArray(float* arr, int size) {

    int index, max = arr[0];

    for (int i = 0; i < size; i++) { 
        if (abs(arr[i]) > max) {
            max = abs(arr[i]);
            index = i;
        }
    }
    return index; }

int multiplication(float* arr, int size, int y) {
    int subtr = 1;
    for (; y < size; y++) { 
        subtr *= arr[y];
    }
    return subtr;
}

string upWord(string text, int g) {
    int t = 0, intSymbol;
    string wordUp;


    for (int i = 0; i < g; i++) {
        if (text[i] != ' ') { 
            intSymbol = text[i] - 32;
            wordUp += char(intSymbol);
            t++; 
        }
        if (text[i] == ' ') 
            break;
    }
    for (t; t < g; t++) {
        wordUp += text[t]; 
    }
    return wordUp;
}

