#include <iostream>
#include <fstream>
#include <regex>
#include <limits>
#include <string>

using namespace std;


bool isNumber(const string& word) {
    for (char c : word) {
        if (!isdigit(c))
            return false; 
    }
    return true; 
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8"); 

    string line;
    string firstWord;

    ofstream fout("FILE2.txt");
    ifstream fin("FILE1.txt");

    if (!fin.is_open()) {
        cout << "Файл не может быть открыт!\n";
        return 1;
    }

   
    while (fin >> firstWord && isNumber(firstWord)); 

    regex wholeWordRegex("\\b" + firstWord + "\\b");
    regex partOfWordRegex(firstWord);

    bool firstLineDeleted = false;

    while (getline(fin, line)) {
        bool containsWholeWord = regex_search(line, wholeWordRegex); 
        bool containsPartOfWord = regex_search(line, partOfWordRegex);

        
       
        if ((containsPartOfWord && !containsWholeWord) || !containsPartOfWord) {
            if (!firstLineDeleted) {
                firstLineDeleted = true;
                continue;
            }
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();

    int consonants = 0;

    ifstream fin2("FILE2.txt");
    if (!fin2.is_open()) {
        cout << "Файл не может быть открыт!\n";
        return 1;
    }

    getline(fin2, line);

    const string consonantLetters = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

    for (char c : line) {
        if (consonantLetters.find(tolower(c)) != string::npos) {
            consonants++;
        }
    }

    fin2.close();
    cout << "В первой строке файла FILE2 " << consonants << " согласных букв." << endl;

    return 0;
}
