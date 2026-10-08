#include <iostream>
using namespace std;

int main()
{
    // Устанавливаем локаль для правильного отображения символов
    setlocale(LC_ALL, "Rus");

    // Запрашиваем значение переменной `t` у пользователя
    int t;
    cout << "Введите значение t: ";
    cin >> t;

    // Выводим значение переменной `t`
    cout << "Значение t = " << t << endl;

    // Отображаем размер типа в байтах
    cout << "Типы размеров в байтах:" << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;

    return 0;
}