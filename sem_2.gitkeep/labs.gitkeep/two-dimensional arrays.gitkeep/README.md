# **Работа с двумерными массивами**

>Задача 1

Заполнить массив, если сумма номера строки и номера столбца - нечетное число, то такой элемент = 0. Все остальные элементы заполняются от 1-9 по порядку(последовательно, пропуская те элементы, которые заняты нулями)

# Блок - схема

![](https://psv4.userapi.com/c909218/u272768864/docs/d57/87c0c40a8212/two-dimensional_arrays1.png?extra=U-m0a6rVIs64o7lbw78lUBHV-KiWvDmo0xbad2FFx9ZiR3YBSQS9ryjmAYge8r6Eydi5NlgQOQoZt7kQDcSRhFtO6gcFCM4OLmb8TcsbYnC6_Va31iOwc15kdnx4XOIfv6Urq66Z3UyqepIKUALffZ1Xvw0)

# Код программы 
```cpp
﻿#include <iostream>
using namespace std;

int main() {

    int str_arr, col_arr, k = 0, num[9] = { 1,2,3,4,5,6,7,8,9 };
    cin >> str_arr >> col_arr;
    int array[str_arr][col_arr];

    int* ptr0 = &array[0][1];
    int* ptr1 = &array[0][0];


    for (int i = 0; i < (str_arr * col_arr); i += 2) {
        *ptr1 = num[k % 9];
        k++;
        ptr1 += 2;
        *ptr0 = 0;
        ptr0 += 2;
    }

    for (int i = 0; i < str_arr; cout << endl, i++)
        for (int j = 0; j < col_arr; cout << array[i][j] << " ", j++);


    return 0;
}
```
>Задача 2

Все элементы выше главной диагонали = 0. Элементы стоящие на главной диагонали и на параллельно заполнены одинаковыми числами

# Блок - схема

![](https://psv4.userapi.com/c909218/u272768864/docs/d2/69a9a1377215/two-dimensional_arrays2.png?extra=iD0RUt-ptWMlW_dpGQvQEz78TgTpb6C6Z5MtRHMZfevF5gCHxu7mjiUZUcDt5pbIB9m6aA02i93lYM3kS4LKC5YMzN7uJD2W9AjItkrSNlzk6zsj0O7s6kkS9aY0VIkBtBKEi72K_SdTcV1YGuYjy4ZK-1U)

# Код программы 
```cpp
﻿#include <iostream>

using namespace std;

int main() {

    int str_arr, col_arr, cnt;
    cin >> str_arr >> col_arr >> cnt;
    int array[str_arr][col_arr];

    int num[cnt];
    for (int i = 0; i < cnt; i++) {
        num[i] = i + 1;
    }

    for (int i = 0; i < str_arr; i++) {
        for (int j = 0; j < col_arr; j++) {
            array[i][j] = 0;
        }
    }

    for (int i = 0, k = 0; i < str_arr; k++, i++) {
        for (int n = 0; n < col_arr - k; n++) {
            array[i + n][n] = num[k % cnt];
        }
    }
    for (int i = 0; i < str_arr; cout << endl, i++)
        for (int j = 0; j < col_arr; cout << array[i][j] << " ", j++);

    return 0;
}
```
