#include <iostream>
#include <cctype>
#include<windows.h>

using namespace std;

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char input;

    cout << "Введите букву русского алфавита: ";
    cin >> input;

    if (input == 'ё' || input == 'Ё') {
        char upper = toupper(input);
        char lower = tolower(input);

        
        int diff = (static_cast<int>(lower) + 256) - (static_cast<int>(upper) + 240);

        cout << "Введенная буква: " << input << std::endl;
        cout << "Разница: " << diff << std::endl;

    }
    else {
        char upper = toupper(input);
        char lower = tolower(input);

        // Определяем разницу между значениями кодов
        int diff = (static_cast<int>(lower) + 256) - (static_cast<int>(upper) + 224);

        cout << "Введенная буква: " << input << endl;
        cout << "Разница: " << diff << endl;
    }
    return 0;
}
