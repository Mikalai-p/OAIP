#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    setlocale(LC_CTYPE, "rus");
   
    ifstream input("FileA.txt");
    if (!input.is_open()) {
        cerr << "Ошибка открытия файла FileA.txt для чтения." << std::endl;
        return 1;
    }

    ofstream output("FileB.txt");
    if (!output.is_open()) {
        cerr << "Ошибка открытия файла FileB.txt для записи." << std::endl;
        return 1;
    }

    string line;
    while (getline(input, line)) {
        if (line.back() == 'a') {  
            output << line << "\n";  
        }
    }

    input.close();
    output.close();

    cout << "Программа успешно завершена!" << std::endl;
    return 0;
}
