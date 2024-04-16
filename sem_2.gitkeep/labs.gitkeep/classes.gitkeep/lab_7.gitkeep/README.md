# Лабораторная работа №7 Шаблоны классов

>Вариант 11

Класс- контейнер СПИСОК с ключевыми значениями типа int. Реализовать операции:
[]– доступа по индексу;
int() – определение размера списка;
+ вектор – сложение элементов списков a[i]+b[i];

Пользовательский класс Money для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей и типа int для копеек.
Дробная часть числа при выводе на экран должна быть отделена от целой части запятой.

#  Код программы 

>list.h

```cpp
#include <iostream>
#pragma once

using namespace std;

template <class T>
class List {
private:
	T size;
	T* array;
public:
	List(T size);
	virtual void show();
	~List();
	int& operator ()();
	List operator +(const List& other);
	T& operator [](int index);
};

template<class T>
List<T>::List(T size) {
	this->size = size;
	array = new T[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100 + 1;
	}
}
template<class T>
void List<T>::show() {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

template<class T>
List<T>::~List() {}

template<class T>
int& List<T>::operator()() {
	return size;
}

template<class T>
List<T> List<T>::operator+(const List& other) {
	List<T> tmp(size);
	for (int i = 0; i < size; i++) {
		tmp[i] = array[i] + other.array[i];
	}
	delete[]array;
	return tmp;
}

template<class T>
T& List<T>::operator [](int index) {
	if (index >= 0 && index < size) {
		return array[index];
	}
	else {
		cout << "Error" << endl;
	}
}
```

>money.h

```cpp
#pragma once
#include <iostream>
#include "list.h"

using namespace std;

template <class T, class T1>
class Money {
private:
	T rub;
	T kop;
public:
	Money(long, int);
	~Money();
	Money(const Money&);
	Money operator =(const Money&);
	Money operator +(const Money&);
	void show();
};

template <class T, class T1>
Money<T, T1>::Money(long R, int K) {
	rub = R;
	kop = K;
}

template <class T, class T1>
Money<T, T1>::~Money() {}

template <class T, class T1>
Money<T, T1> Money<T, T1>::operator =(const Money& money) {
	rub = money.rub;
	kop = money.kop;
}

template <class T, class T1>
void Money<T, T1>::show() {
	cout << "\nResult money: " << rub << ", " << kop;
}

template <class T, class T1>
Money<T, T1>Money<T, T1>::operator +(const Money& money) {
	int M = rub * 100 + kop;
	int monM = money.rub * 100 + money.kop;
	M += monM;

	Money temp(M / 100, M % 100);
	return temp;
}
```

>money.cpp

```cpp
#include <iostream>
#include "money.h"

using namespace std;

Money::Money(void) { rub = 0; kop = 0; }
Money::Money(int R, int K) { rub = R; kop = K; }
Money::Money(const Money& m) { rub = m.rub; kop = m.kop; }
Money& Money::operator=(const Money& m) { rub = m.rub; kop = m.kop; return *this; }
Money Money::operator+(Money k) {
	int t = rub * 100 + kop;
	int kt = k.rub * 100 + k.kop;
	t += kt;
	Money temp(t / 100, t & 100);
	return temp;
}
ostream& operator << (ostream& out, const Money& t) { out << t.rub << " : " << t.kop; return out; }
istream& operator >> (istream& in, Money& t) { cout << "\nRUB: "; in >> t.rub; cout << "\nKOP: "; in >> t.kop; return in; }

```

>lab_7.cpp

```cpp
#include <iostream>
#include "list.h"
#include "money.h"

using namespace std;

int main() {
	int k = 1;
	int size = 5;
	List<int> A(size);
	cout << "A: "; A.show();
	cout << "A[k]: " << A[k] << endl;
	cout << "A: " << A() << endl;

	List<int> B(size);
	cout << "B: "; B.show();
	cout << "B: " << B() << endl;

	List<int> C(size);
	C = A + B;
	cout << "C = A + B: "; C.show();

	/////////////
	Money<long, int> a(10203040, 110);
	a.show();
	Money<long, int> b(1000000, 21);
	b.show();

	return 0;
}

```

>
>
