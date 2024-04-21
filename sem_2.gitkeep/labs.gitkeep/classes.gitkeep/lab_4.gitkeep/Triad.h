#pragma once
#include <iostream>
using namespace std;
class Triad {
//конструктор без параметров 
public:
	Triad(void);
public:
//деструктор 
	virtual ~Triad(void);
//конструктор с параметрами 
	Triad(int, int, int);
//конструктор копирования
	Triad(const Triad&);
//селекторы 
	int getFirst() { return first; }
	int getSecond() { return second; }
	int getThird() { return third; }
//модификаторы 
	void setFirst(int);
	void setSecond(int);
	void setThird(int);
//перегрузка операции присваивания
	Triad& operator = (const Triad&);
//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Triad& T);
	friend ostream& operator>>(ostream& out, Triad& T);
//атрибуты
protected:
	int first;
	int second;
	int third;
};
