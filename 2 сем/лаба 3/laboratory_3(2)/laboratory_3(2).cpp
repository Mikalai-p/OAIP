#include <iostream>
#include <fstream>
using namespace std;

bool alphaP(string& word) {
    for (char c : word) {
        if (c == 'p' || c == 'P') {
            return  true;
        }
    }
    return false;
}

void inFile(ifstream& f, char s[100000]) {
    f.open(s);
    if (f.fail()) {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }

    string word;
    while (f >> word) {
        if (alphaP(word)) {
            cout << word << endl;
        }
    }

    f.close();
}

void fromFile(ofstream& f, char s[100000]) {
    f.open(s);
    if (f.fail()) {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    cout << "Введите строку: " << endl;
    cin.ignore(); 
    cin.getline(s, 100); 
    f << s;
    f.close();
}

int main() {
    setlocale(LC_CTYPE, "RU");
    char str[100];
    ifstream ifile;
    ofstream ofile;

    cout << "\n Ввести имя файла для записи: \n";
    cin >> str;
    fromFile(ofile, str);
    cout << endl;

    cout << "\n Ввести имя файла для чтения: \n";
    cin >> str;
    inFile(ifile, str);

    return 0;
}