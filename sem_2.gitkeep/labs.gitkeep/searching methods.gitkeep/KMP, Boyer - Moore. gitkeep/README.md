# Поиск КМП, Бойера - Мура

# Блок - схемы

> КМП

![](https://psv4.userapi.com/c909328/u272768864/docs/d46/c23266152e1a/KMP.png?extra=dreUJh_aQwUVVSsX74rGnIDMTJdHYGil15AsX20yzzcDQOaFvuHn-dEj9af0354c02B9Z11exFy4l27k8fWr-fSiLRYlG2ZROcXh5ccpE5OP12ph80QARvbD8BPnOygz7L4VeN6zwiIUQBSMcZ-cZvJdsqw)

> Бойер - Мур
...

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
...

# Результаты работы 

> КМП

![](https://sun9-6.userapi.com/impg/1tiW_p17gKhwphhe-K-7a9h4uguj_iMFI3X9hg/bPiDQ5eRcZ8.jpg?size=278x107&quality=96&sign=5233bbb9e5fbe0c9b4591001ededb46c&type=album)

> Бойер - Мур
...
