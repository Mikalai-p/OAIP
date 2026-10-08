#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Ввод символа для закраски квадрата
    char fill_char = ' ';
    cout << "Введите символ для закраски квадрата: "<<std::endl;
    cin >> fill_char;

    // Очистка экрана перед выводом
    system("cls");

    // Вывод квадрата размером 40х40 символов, заполненного введённым символом
    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            cout << fill_char;
        }
        cout << "\n";
    }

    return 0;
}
