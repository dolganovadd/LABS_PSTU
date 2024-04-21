# Лабораторная работа №9 Обработка исключительных ситуаций

>Вариант 11

Класс- контейнер СПИСОК с ключевыми значениями типа int.
Реализовать операции:
[]– доступа по индексу;
int() – определение размера списка;
+ вектор – сложение элементов списков a[i]+b[i];
- n - переход влево к элементу c номером n.
- 
Реализация 2, 3


# UML - диаграмма
...

# Код программы 

# Реализация 2

>error.h

```cpp
#pragma once
#include <string> 
#include <iostream> 

using namespace std;

class Error //класс ошибка
{
	string str;
public:
	//конструктор, инициирует атрибут str сообщением об ошибке 
	Error(string s) { str = s; }
	void what() { cout << str << endl; } //выводит значение атрибута str
};
```

>list.h

```cpp
#pragma once
#include <iostream>

using namespace std;
const int MAX_SIZE = 20;

class List {
	int size, * beg;
public:
	List() { size = 0; beg = 0; }
	List(int L);
	List(int L, int* arr);
	List(const List& list);
	~List();

	List& operator=(const List& list);
	int operator[](int index);

	List operator +(const List& other);
	int operator -(int n);

	friend ostream& operator << (ostream& out, const List& list);
	friend istream& operator >> (istream& in, List& list);
};

```

>list.cpp

```cpp
#include "list.h"
#include "error.h"
#include <iostream>

using namespace std;

List::List(int l) {
	size = l;
	beg = new int[l];
	for (int i = 0; i < size; i++) { beg[i] = 1; }
}

List::List(int l, int* arr) {
	if (l > MAX_SIZE) throw Error("Length > 20\n");
	size = l;
	beg = new int[size];
	for (int i = 0; i < size; i++) { beg[i] = arr[i]; }
}
List::List(const List& list) {
	size = list.size;
	beg = new int[size];
	for (int i = 0; i < size; i++) {
		beg[i] = list.beg[i];
	}
}

List::~List() {
	if (beg != 0) { delete[] beg; }
}

List& List::operator=(const List& list) {
	if (this == &list) { return *this; }
	if (beg != 0) { delete[]beg; }
	size = list.size;
	beg = new int[size];
	for (int i = 0; i < size; i++) { beg[i] = list.beg[i]; }
	return *this;
}

int List::operator[] (int index) {
	if (index > size) { throw Error("index > size"); }
	if (index < 0) { throw Error("Index < 0 or > size"); }
	return beg[index];
}

List List::operator +(const List& other) {
	List result;
	if (size != other.size) { return result; }
	result.size = size;
	result.beg = new int[size];
	for (int i = 0; i < size; i++) { result.beg[i] = beg[i] + other.beg[i]; }
	return result;
}
int List::operator-(int n) {
	if (n >= 0 && n < size) { return beg[n]; }
	else { throw Error("Error n"); }
}
ostream& operator << (ostream& out, const List& list) {
	if (list.size == 0) { out << "Empty" << endl; }
	else {
		for (int i = 0; i < list.size; i++) { out << list.beg[i] << " "; }
		out << endl;
	}
	return out;
}
istream& operator >> (istream& in, List& list) {
	for (int i = 0; i < list.size; i++) {
		cout << " > ";
		in >> list.beg[i];
	}
	return in;
}

```

>lab_9.cpp

```cpp
#include <iostream>
#include "error.h"
#include "list.h"

using namespace std;

int main() {
	try {
		List x(15), y;
		int i;

		cout << "Result with parametres: " << x << endl;
		cout << "Number: "; cin >> i;

		cout << "Result: " << x[i] << endl;

		y = x + i;

		cout << "Result y: " << y;
	}
	catch (Error e) {
		e.what();
	}
	return 0;
}
```

# Реализация 3

>error.h

```cpp
#pragma once
#include <string> 
#include <iostream> 
using namespace std;

class Error//базовый класс
{
public:
	virtual void what() {};
};
class IndexError :public Error 
{
protected:
	string msg;
public:
	IndexError() { msg = "Index Error\n"; }
	virtual void what() { cout << msg; }
};
class SizeError :public Error {
protected:
	string msg;
public:
	SizeError() { msg = "size error\n"; }
	virtual void what() { cout << msg; }
};
class MaxSizeError :public SizeError {
protected:
	string msg_;
public:
	MaxSizeError() { SizeError(); msg_ = "size>MAXSIZE\n"; }
	virtual void what() { cout << msg << msg_; }
};
class EmptySizeError :public SizeError 
{
protected:
	string msg_;
public:
	EmptySizeError() { SizeError(); msg_ = "Vector is empty\n"; }
	virtual void what() { cout << msg << msg_; }
};
class IndexError1 :public IndexError 
{
protected:
	string msg_;
public:
	IndexError1() { IndexError(); msg_ = "index <0\n"; }
	virtual void what() { cout << msg << msg_; }
};
class IndexError2 :public IndexError {
protected:
	string msg_;
public:
	IndexError2() { IndexError(); msg_ = "index>size\n"; }
	virtual void what() { cout << msg << msg_; }
};
```

>list.h

```cpp
#pragma once
#include <iostream>

using namespace std;
const int MAX_SIZE = 20;

class List {
	int size, * beg;
public:
	List() { size = 0; beg = 0; }
	List(int L);
	List(int L, int* arr);
	List(const List& list);
	~List();

	List& operator=(const List& list);
	int operator[](int index);

	List operator +(const List& other);
	int operator -(int n);

	friend ostream& operator << (ostream& out, const List& list);
	friend istream& operator >> (istream& in, List& list);
};

```

>list.cpp

```cpp
#include "list.h" 
#include "error.h" 
#include <iostream> 
using namespace std;

List::List(int s)
{

	if (s > MAX_SIZE) throw MaxSizeError();
	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}
List::List(const List& v)
{
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
}
List::~List()
{
	if (beg != 0) delete[]beg;
}
List::List(int s, int* mas)
{
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}
List& List::operator =(const List& v)
{
	if (this == &v)return *this;
	if (beg != 0) delete[]beg;
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
	return*this;
}

ostream& operator<<(ostream& out, const List& v)
{
	if (v.size == 0) out << "Empty\n";
	else
	{
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << " ";
		out << endl;
	}
	return out;
}
istream& operator >>(istream& in, List& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}
int List::operator [](int i)
{

	if (i < 0)throw IndexError1();
	if (i >= size) throw IndexError2();
	return beg[i];
}

List List::operator +(int a)
{
	if (size + 1 == MAX_SIZE) throw MaxSizeError();
	List temp(size + 1, beg);
	temp.beg[size] = a;
	return temp;
}
List List::operator --()
{
	if (size == 0) throw EmptySizeError();
	if (size == 1)
	{
		size = 0;
		delete[]beg;
		beg = 0;
		return *this;
	};
	List temp(size, beg);
	delete[]beg;
	size--;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = temp.beg[i];
	return*this;
}
```

>lab_9.cpp

```cpp
#include <iostream>
#include "error.h"
#include "list.h"

using namespace std;

int main() {
	try {
		List x(15), y;
		int i;

		cout << "Result with parametres: " << x << endl;
		cout << "Number: "; cin >> i;

		cout << "Result: " << x[i] << endl;

		y = x + i;

		cout << "Result y: " << y;
	}
	catch (Error e) {
		e.what();
	}
	return 0;
}

```
