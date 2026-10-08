#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>
using namespace std;

string peraculenaeSlova(const string& slova) { 
    string peraculenaeSlova = slova;
    int length = slova.length(); 
    for (int i = 0; i < length / 2; i++) { 
        swap(peraculenaeSlova[i], peraculenaeSlova[length - i - 1]); 
    }
    return peraculenaeSlova;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string skaz;
    cout << "Введите предложение: ";
    getline(cin, skaz);

    vector<string> slovi;
    string slova;
    int index = 0;
    for (int i = 0; i < skaz.length(); i++) {
        if (skaz[i] == ' ') {
            if (index % 2 != 0) { 
                slovi.push_back(peraculenaeSlova(slova)); 
            }
            slova = ""; 
            index++;
        }
        else {
            slova += skaz[i]; 
        }
    }
    if (!slova.empty() && index % 2 != 0) {
        slovi.push_back(peraculenaeSlova(slova));
    }

    string result;
    for (const string& w : slovi) { 
        result += w + " ";
    }

    cout << "новое предложение: " << result << endl;

    return 0;
}
