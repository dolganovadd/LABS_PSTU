**Лабораторная работа №7. Перегрузка функций в С++**
>7.1

**Вариант 10.** Написать перегруженные функции и основную программу, которая их вызывает:

а) для вычитания десятичных дробей;
б) для вычитания обыкновенных дробей.

**Код программы:**
```cpp
#include <iostream>
using namespace std;

float diff(float a, float b) {
	return a - b;
}

double diff(double a, double b) {
	return a - b;
}

int main() {
	setlocale(LC_ALL, "RU");

	float a;
	cout << "Введите первое число" << endl;
	cin >> a; 
	
	float b;
	cout << "Введите второе число" << endl;
	cin >> b;

	cout << "Разность:"<<diff(a, b) << endl;

	double c;
	cout << "Введите первое число" << endl;
	cin >> c;

	double d;
	cout << "Введите второе число" << endl;
	cin >> d;

	cout << "Разность"<<diff(a, b) << endl;
	return 0;
}
```

>7.2

**Вариант 10.** Написать функцию kvadr с переменным числом
параметров, которая определяет количество чисел,
являющихся точными квадратами (2, 4, 9, 16,. . . ) типа

**Код программы:**
```cpp
#include<iostream>
#include<cmath>
#include <stdarg.h>
using namespace std;
int kvadr(int m,...) {
	va_list ptr;
	va_start(ptr, m);
	int k = 0;
	for (; m != 0; m--) {
		int tmp;
		tmp = va_arg(ptr, int);
		if (pow((int)sqrt(tmp), 2) == tmp) {

			k += 1;
		}

	}
	va_end(ptr);
	return k;
}

int main() {
	cout << kvadr(3, 4, 8, 2) << endl;
	cout << kvadr(7, 6, 2, 9, 5, 16, 8, 5) << endl;
	cout << kvadr(11, 6, 9, 70, 45, 36, 49, 84, 5, 2, 3, 1) << endl;
	return 0;
}

```
int. Написать вызывающую функцию main, которая
обращается к функции kvadr не менее трех раз с
количеством параметров 3, 7, 11.

