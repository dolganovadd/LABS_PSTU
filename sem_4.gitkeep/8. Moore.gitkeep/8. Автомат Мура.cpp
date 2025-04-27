#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Automat {
 
    // 0 - начальное состояние
    // 1- последняя буква была гласной (а)
    // 2 - последняя буква была согласной (b,c,d)
    // 3 - состояние ошибки

    int transitions[4][4] = {
        {1, 2, 2, 2},  // Из состояния 0: a->1, b/c/d->2
        {3, 2, 2, 2},  // Из состояния 1: a->3 (ошибка), b/c/d->2
        {1, 3, 3, 3},  // Из состояния 2: a->1, b/c/d->3 (ошибка)
        {3, 3, 3, 3}   // Состояние 3 
    };

    unordered_map<char, int> charToIndex = {
        {'a', 0},
        {'b', 1},
        {'c', 2},
        {'d', 3}
    };

public:
    bool isAccepted(const string& word) {
        int state = 0; // Начальное состояние

        for (char ch : word) {
            
            ch = tolower(ch);

            // Проверяем допустимость символа
            if (charToIndex.find(ch) == charToIndex.end()) {
                cout << "Недопустимый символ: " << ch << endl;
                return false;
            }

            int symbolIndex = charToIndex[ch];
            state = transitions[state][symbolIndex];

            // Если попали в состояние ошибки - возвращаем false
            if (state == 3) {
                return false;
            }
        }

        // Слово принимается, если закончили в состоянии 0, 1 или 2
        return state != 3;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Automat automat;

    while (true) {
        cout << "Введите слово: ";
        string input;
        cin >> input;

        bool result = automat.isAccepted(input);
        cout << (result ? "Слово принадлежит языку" : "Слово НЕ принадлежит языку") << endl;
        cout << endl;
    }

    return 0;
}