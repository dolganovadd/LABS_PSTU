# **Лабораторная работа №9 "Строковый ввод-вывод".**

Вариант 11

1. Создать текстовый файл F1 не менее, чем из 10 строк и
записать в него информацию
2. Выполнить задание:
   
 Скопировать из файла F1 в файл F2 все строки, кроме той
строки, которая содержит самое короткое слово.

 Напечатать номер этой строки.

 # Блок - схема
 ![](https://psv4.userapi.com/c909518/u272768864/docs/d48/834ee14e0e00/lab_9.png?extra=SqIxLAp-JjQPyAxtKTz2buUm_XbgI9y5kdxBWRkuDxRHP3rN-MT5G1JvnCUTcZWLoPW_yJX-1dZF9L4Og1CYSXwuoze8L9b3xx6zFexpgcRysHiMEOmNmKDrM6CcTJx8V77rouXiJVlFXpmwYdDwdpT4GIM)

 # Код программы 
 ```cpp
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
```
