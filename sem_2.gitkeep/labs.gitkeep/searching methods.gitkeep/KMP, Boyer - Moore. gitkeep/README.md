# Поиск КМП, Бойера - Мура

# Блок - схемы

> КМП

![](https://psv4.userapi.com/c909328/u272768864/docs/d46/c23266152e1a/KMP.png?extra=dreUJh_aQwUVVSsX74rGnIDMTJdHYGil15AsX20yzzcDQOaFvuHn-dEj9af0354c02B9Z11exFy4l27k8fWr-fSiLRYlG2ZROcXh5ccpE5OP12ph80QARvbD8BPnOygz7L4VeN6zwiIUQBSMcZ-cZvJdsqw)

> Бойер - Мур

![](https://psv4.userapi.com/c909328/u272768864/docs/d46/9279b5943d78/Boyer_-_Moore.png?extra=oAdeSHG4RZpXZWXnqW7tIHJgDpLSKipAupOMSHtXYGjSGd6-kjzLGL_OTQDykEaTvV3m53TS42dUE1NxTztY24t1BwGZDAI8W5XBY8thbYnjxX-VwckojEwXUIk9GEHH09tec4xaBWzXf2EMXMchFZ_qrCY)

# Код программы

> КМП

```cpp
#include <iostream>
using namespace std;

void pref_func(string pattern, int* d) {
    d[0] = 0;
    int j = 0;
    int i = 1;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[j]) {
            d[i] = j + 1;
            i++;
            j++;
        }
        else
            if (j == 0) {
                d[i] = 0;
                i++;
            }
            else {
                j = d[j - 1];
            }
    }
}

void KMP_search(string pattern, string text) {
    int* d = new int[pattern.length()];
    pref_func(pattern, d);
    int i = 0, j = 0;
    while (i < text.length()) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == pattern.length()) {
            cout << "Найден шаблон по индексу " << i - pattern.length() << endl;
            j = d[j - 1];
        }
        else
            if (i < text.length() && pattern[j] != text[i]) {
                if (j == 0) {
                    i++;
                }
                else {
                    j = d[j - 1];
                }
            }
    }

}

int main()
{
    system("chcp 1251");
    string str;
    string substr;
    cout << "Введите текст: ";
    cin >> str;
    cout << "Шаблон: ";
    cin >> substr;
    KMP_search(substr, str);
    return 0;
}
```
> Бойер - Мур

```cpp
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

```

# Результаты работы 

> КМП

![](https://sun9-6.userapi.com/impg/1tiW_p17gKhwphhe-K-7a9h4uguj_iMFI3X9hg/bPiDQ5eRcZ8.jpg?size=278x107&quality=96&sign=5233bbb9e5fbe0c9b4591001ededb46c&type=album)

> Бойер - Мур

![](https://sun9-75.userapi.com/impg/0R58xmdAmGMZcEUcHi2v_6peFw1HNReDNE2xcw/rP4LQKTpo9M.jpg?size=285x101&quality=96&sign=327c97b6e2413b28d93338939aa8f251&type=album)
