# Лабораторная работа №6 АТД. Контейнеры
>Вариант 11

Класс- контейнер СПИСОК с ключевыми значениями типа int. Реализовать операции:
[]– доступа по индексу;
int() – определение размера списка;
+ вектор – сложение элементов списков a[i]+b[i];
- n - переход влево к элементу c номером n ( с помощью класса-итератора).

# UML - диаграмма 

![](https://sun9-17.userapi.com/impg/D1si-77tStpUDzHy0PoS1sRSZ-luI6ZgQkU7fg/tZoflBiiglU.jpg?size=1620x2160&quality=95&sign=5452b5f91fa91de3d9fcd92a84dc3966&type=album)
# Код программы 

>list.h

```cpp
#pragma once
class Iterator
{
	friend class List;//дружественный класс 
public:
	Iterator() { elem = 0; }//конструктор без параметров
	Iterator(const Iterator& it) { elem = it.elem; }//конструктор копирования
	//перегруженные операции сравнения
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; };
	//перегруженная операция инкремент
	void operator++(){ ++elem;};
	//перегруженная операция декремент 
	void operator--(){--elem;}
	//перегруженная операция разыменования
int& operator *() const { return*elem; } 
private:
	int* elem;//указатель на элемент типа int
};

class List
{
public:
	//конструктор с параметрами: выделяет память под s элементов и заполняет их
	//значением k
	List(int s, int k = 0);
	//конструктор с параметрами 
	List(const List&a);
	//деструктор
	~List();
	//оператор присваивания
	List&operator=(const List&a);
	//операция доступа по индексу
	int&operator[](int index);
	//операция для добавление константы 
	List operator+(const int k);
	//операция, возвращающая длину вектора 
	int operator()();
	//перегруженные операции ввода-вывода
	friend ostream& operator<<(ostream& out, const List& a);
	friend istream& operator>>(istream& in, List& a);
	Iterator first() { return beg; }
	Iterator last() { return end; }

private:
	int size;//размер вектора
	int* data;//укзатель на динамический массив значений вектора
	Iterator beg, end;
};

```

>list.cpp

```cpp
#include <iostream>
#include "List.h"
using namespace std;

//конструктор с параметрами
List::List(int s, int k)
{
	size = s;
	data = new int[size]; for (int i = 0; i < size; i++)
		data[i] = k;
	beg.elem = &data[0];
	end.elem = &data[size];
}
//конструктор копирования
List::List(const List& a)
{
	size = a.size; 
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
}
//деструктор
List::~List()
{
	delete[]data; 
	data = 0;

}
//операция присваивания 
List&List::operator=(const List&a)
{
	if (this == &a)return *this; 
	size = a.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
	return *this;
}
//операция доступа по индексу 
int&List::operator[](int index)
{
	if (index < size) return data[index]; else cout << "\nError! Index>size";
}
//операция для добавления константы 
List List::operator+(const int k)//+k
{
	List temp(size);
	for (int i = 0; i < size; ++i) temp.data[i] += data[i] + k;
	return temp;
}
//операция для получения длины вектора 
int List::operator ()()
{
	return size;
}
//операции для ввода-выода 
ostream&operator<<(ostream&out,const List&a)
{
	for (int i = 0; i < a.size; ++i) out << a.data[i] << " ";
	return out;
}

istream& operator>>(istream& in, List& a)
{
	for (int i = 0; i < a.size; ++i) in >> a.data[i];
	return in;
}

```

>lab_6.cpp

```cpp
#include <iostream>
#include "list.h"
using namespace std;

void main()
{
	List a(5); 
	cout<<a<<"\n";
	cin>>a;
	cout<<a<<"\n";
	a[2] = 100;
	cout<<a<<"\n";
	List b(10);
	cout<<b<<"\n";
	b = a;
	cout<<b<<"\n";
	List c(10);
	c=b+100;
	cout<<c<<"\n";
	cout << "\nthe length of a=" << a() << endl;

}
```
