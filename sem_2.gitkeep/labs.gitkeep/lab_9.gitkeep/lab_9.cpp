#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    ifstream F1("F1.txt");
    ofstream F2("F2.txt");
    string str, shortestWord, word;
    int shortestWordLine = 0, line = 1;

    while (getline(F1, str)) {
        stringstream ss(str);
        int wordCount = 0;
        int shortestLength = INT_MAX;

        while (ss >> word) {
            wordCount++;
            if (word.length() < shortestLength) {
                shortestLength = word.length();
                shortestWord = word;
            }
        }

        if (wordCount > 0 && shortestLength < INT_MAX) {
            if (line == shortestWordLine) {
                cout << "Номер строки с самым коротким словом: " << line << endl;
            }
            else {
                F2 << str << endl;
            }
        }
        line++;
    }

    F1.close();
    F2.close();

    return 0;
}