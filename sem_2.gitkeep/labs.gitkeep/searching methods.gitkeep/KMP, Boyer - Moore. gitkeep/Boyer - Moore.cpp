#include <iostream>
#include <string>
using namespace std;

int boyerMoore(string str, string sub) { 
    int lenStr, lenSub, index = -1;
    lenStr = str.size();
    lenSub = sub.size();
    bool flag;
    int lastChar; // положение последнего символа подстроки в строке
    int table[256];// таблица смещений
    for (int i = 0; i < 256; i++) { // заполнение таблицы
        table[i] = lenSub;
    }
    for (int i = lenSub - 2; i >= 0; i--) { // создание таблицы смещения элементов для подстроки
        if (table[int((unsigned char)sub[i])] == lenSub) { // если смещение элемента подстроки равно длине подстроки
            table[int((unsigned char)sub[i])] = lenSub - i - 1; // вычисление шага смещения
        }
    }
    lastChar = lenSub - 1;
    while (lastChar < lenStr && index == -1) {
        if (sub[lenSub - 1] != str[lastChar]) {
            lastChar += table[int((unsigned char)str[lastChar])]; // смещение подстроки
        }
        else {
            flag = true;
            for (int i = lenSub - 1; i >= 0 && index == -1 && flag; i--) {
                if (sub[i] != str[lastChar - lenSub + i + 1]) { // смещение по таблице последнего символа, если он не равен элементу
                    lastChar += table[int((unsigned char)str[lastChar - lenSub + i + 1])]; // смещение по строке
                    flag = false; // смена флага
                }
                else if (i == 0) { // если подстрока найдена
                    index = lastChar - lenSub + 1; // вычисление индекса
                }
            }
        }
    }
    return index; // возврат индекса
}
int main() {
    system("chcp 1251");
    string str, sub;
    cout << "Введите строку: ";
    cin >> str;
    cout << "Введите подстроку: ";
    cin >> sub;
    if (boyerMoore(str, sub) != -1) {
        cout << "Подстрока есть в строке";
    }
    else {
        cout << "Подстроки нет в строке";
    }
    return 0;
}
