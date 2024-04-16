# Лабораторная работа №4 "Простое наследование. Принцип подстановки"
> Вариант 11

Базовый класс: ТРОЙКА_ЧИСЕЛ (TRIAD)

Первое_число (first) - int

Второе_число (second) - int

Третье_число (third) - int

Определить методы изменения полей и увеличения полей на 1.
Создать произвольный класс TIME с полями часы, минуты, секунды.
Переопределить методы увеличения полей на 1 и определить метод увеличения даты на n секунд и минут.

# UML - диаграмма

![](https://psv4.userapi.com/c909218/u272768864/docs/d42/5b96c152aa1e/lab_4.png?extra=FNN6GPsSV4etaKl1Lly4ax41K0DUOZZxLeApeak_WjV_V7Z_G4UxlM9xze1k8rWGlRxFZvBQ6qeRTCeiH7MDKgX_oTYGXKX93tj5mI6r503DDylt1xC3qGWeav5J0Y-01a94XJe7W6N1-5uA4hbApiLnEw)

# Код программы 
> Triad.h

```cpp
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

```

>Time.h

```cpp
#pragma once
#include <iostream>
#include "Triad.h"

using namespace std;

class Time :
	public Triad {
public:
	Time(void);
	~Time(void);
	Time(int, int, int);
	Time(const Time&);

	int getHour() { return hour; }
	int getMin() { return min; }
	int getSec() { return sec; }

	void setHour(int);
	void setMin(int);
	void setSec(int);

	Time& operator =(const Time&);

	friend istream& operator >>(istream& in, Time& time);
	friend ostream& operator <<(ostream& out, const Time& time);

protected:
	int hour, min, sec;
};

```

> triadMain.cpp
```cpp
#include <iostream>
#include "Time.h"
#include "Triad.h"
using namespace std;

void f1(Triad& triad) {
	triad.setFirst(111111111);
	triad.setSecond(222222222);
	triad.setThird(33333333);
	cout << triad;
}

Triad f2() {
	Time time(00, 00, 00);
	return time;
}

int main() {
	Triad num0;
	cin >> num0;
	cout << num0;
	Triad num1(0, 11, 22);
	cout << num1;

	num0 = num1;
	cout << num0;

	Time time;
	cin >> time;
	cout << time;

	return 0;
}

```

>Triad.cpp
```cpp
#include "Triad.h"
//конструктор без параметров 
Triad::Triad(void) {
	first = 0;
	second = 0;
	third = 0;
}
//деструктор
Triad::~Triad(void) {}
//конструктор с параметрами
Triad::Triad(int F, int S, int T) {
	first = F;
	second = S;
	third = T;
}
//конструктор копирования 
Triad::Triad(const Triad& triad) {
	first = triad.first;
	second = triad.second;
	third = triad.third;
}
//модификаторы
void Triad::setSecond(int S) {
	second = S;
}
void Triad::setFirst(int F) {
	first = F;
}
void Triad::setThird(int T) {
	third = T;
}
//перегрузка операции присваивания 
Triad& Triad::operator=(const Triad& T) {
	if (&T == this) return *this;
	first = T.first;
	second = T.second;
	third = T.third;
	return *this;
}
//глобальная функция для ввода
istream& operator<<(istream& in, Triad& T) {
	cout << "\nFIRST:"; in>> T.first;
	cout << "\nSECOND:"; in >> T.second;
	cout << "\nTHIRD:"; in >> T.third;
	return in;
}
//глобальная функция для вывода 
ostream& operator<<(ostream& out, const Triad& T) {
	out << "\nFIRST:" << T.first;
	out << "\nSECOND:" << T.second;
	out << "\nTHIRD:" << T.third;
	out << "\n";
	return out;
}
```
>Time.cpp

```cpp
#include <iostream>
#include "Time.h"

using namespace std;

Time::Time(void) :Triad() {
	hour = 0;
	min = 0;
	sec = 0;
}

Time::~Time(void) {}

Time::Time(int H, int M, int S) {
	hour = H;
	min = M;
	sec = S;
}

Time::Time(const Time& time) {
	hour = time.hour;
	sec = time.sec;
	min = time.min;
}

void Time::setHour(int H) {
	hour = H;
}
void Time::setMin(int M) {
	min = M;
}
void Time::setSec(int S) {
	sec = S;
}

Time& Time::operator =(const Time& time) {
	if (&time == this) {
		return *this;
	}
	first = time.first;
	second = time.second;
	third = time.third;
	hour = time.hour;
	min = time.min;
	sec = time.sec;
	return *this;
}

istream& operator >>(istream& in, Time& time) {
	cout << "\nFirst: " << time.first;
	cout << "\nSecond: " << time.second;
	cout << "\nThird: " << time.third;
	cout << "\nHour: " << time.hour;
	cout << "\nMinutes: " << time.min;
	cout << "\nSeconds: " << time.sec;
	return in;
}

ostream& operator <<(ostream& out, const Time& time) {
	out << "\nFirst: " << time.first;
	out << "\nSecond: " << time.second;
	out << "\nThird: " << time.third;
	out << "\nHour: " << time.hour;
	out << "\nMinutes: " << time.min;
	out << "\nSeconds: " << time.sec;
	return out;
}

```
# Результаты работы 

![](https://sun9-80.userapi.com/impg/77CXbffKk3h1b3viRFKB6Qjw9gbmKPcvMoGI0g/_Mof59x0Au8.jpg?size=167x583&quality=96&sign=a48e5969c0407a8b99fad8b08a45ebed&type=album)

# Контрольные вопросы

>Для чего используется механизм наследования?

Наследование - это механизм создания нового класса на основе уже существующего. При этом к существующему классу могут быть добавлены новые элементы (данные и функции), либо существующие функции могут быть изменены. Наследование содействует повторному использованию атрибутов и методов класса, а значит, делает процесс разработки ПО более эффективным.

>Каким образом наследуются компоненты класса, описанные со спецификатором public?

Protected и public данные из базового класса остаются, соответственно protected и public в производном классе.

>Каким образом наследуются компоненты класса, описанные со спецификатором private?

Данные protected и public базового класса доступны из методов производного класса, но недоступны извне, то есть они становятся private.

>Каким образом наследуются компоненты класса, описанные со спецификатором protected?

Данные, которые были protected и public становятся protected.

>Производный класс описывается с помощью механизма наследования.

>Наследуются ли конструкторы?

Нет.

>Наследуются ли деструкторы?

Нет.

>В каком порядке конструируются объекты производных классов?

Объекты класса конструируются снизу вверх: сначала базовый, потом компоненты-объекты (если они имеются), а потом сам производный класс. 

>В каком порядке уничтожаются объекты производных классов?

Уничтожаются объекты в обратном порядке: сначала производный, потом его компоненты-объекты, а потом базовый объект.

>Что представляют собой виртуальные функции и механизм позднего связывания?

Виртуальный метод — это метод, ссылка на который разрешается на этапе выполнения программы.

Механизм позднего связывания в С++ реализуется с помощью виртуальных методов. Разрешение ссылок на функции происходит на этапе выполнения программы в зависимости от конкретного типа объекта, вызвавшего функцию.

Для определения виртуального метода используется спецификатор virtual.

>Могут ли быть виртуальными конструкторы? Деструкторы?

Виртуальных конструкторов не бывает. Возможна имитация виртуального конструктора с помощью паттерна "Фабрики объектов". Виртуальный деструктор необходим, когда в классе есть хоть одна виртуальная функция или класс является базовым.

>Наследуется ли спецификатор virtual?

Нет.

>Какое отношение устанавливает между классами открытое наследование?

Открытое наследование устанавливает между классами отношение «является», или в английской нотации «is-а». 

>Какое отношение устанавливает между классами закрытое наследование?

"Содержит"

>В чем заключается принцип подстановки?

Этот принцип позволяет использовать полиморфизм, который является ключевым аспектом ООП. Полиморфизм позволяет объектам разных классов обрабатываться единообразно, что делает код более гибким и понятным.

>Имеется иерархия классов: class Student
>{
public:
}; 
int age;
string name;
... 
class Employee : public Student
{
protected:
string post;
...
};
class Teacher : public Employee
{
protected: int stage;
...
};
Teacher x;
Какие компонентные данные будет иметь объект х?

Объект x, созданный как экземпляр класса Teacher, будет иметь следующие компонентные данные в соответствии с иерархией классов:

1. Поля класса Student, так как Teacher является производным от Student:
   - int age
   - string name

2. Поля класса Employee, так как Teacher является производным от Employee:
   - string post

3. Поля класса Teacher:
   - int stage

Таким образом, объект x будет иметь следующие компонентные данные:

- age (типа int)
- name (типа string)
- post (типа string)
- stage (типа int)

>Для классов Student, Employee и Teacher написать конструкторы без параметров.

```cpp
class Student {
public:
    // Конструктор без параметров для класса Student
    Student() {
        // По умолчанию устанавливаем возраст и имя
        age = 0;
        name = "NoName";
    }

protected:
    int age;
    string name;
};

class Employee : public Student {
public:
    // Конструктор без параметров для класса Employee
    Employee() {
        // По умолчанию устанавливаем должность
        post = "Unknown";
    }

protected:
    string post;
};

class Teacher : public Employee {
public:
    // Конструктор без параметров для класса Teacher
    Teacher() {
        // По умолчанию устанавливаем стаж
        stage = 0;
    }

protected:
    int stage;
};

```
>Для классов Student, Employee и Teacher написать конструкторы с параметрами.

```cpp
class Student {
public:
    // Конструктор с параметрами для класса Student
    Student(int studentAge, const string& studentName) : age(studentAge), name(studentName) {}

protected:
    int age;
    string name;
};

class Employee : public Student {
public:
    // Конструктор с параметрами для класса Employee
    Employee(int employeeAge, const string& employeeName, const string& employeePost)
        : Student(employeeAge, employeeName), post(employeePost) {}

protected:
    string post;
};

class Teacher : public Employee {
public:
    // Конструктор с параметрами для класса Teacher
    Teacher(int teacherAge, const string& teacherName, const string& teacherPost, int teacherStage)
        : Employee(teacherAge, teacherName, teacherPost), stage(teacherStage) {}

protected:
    int stage;
};

```
>Для классов Student, Employee и Teacher написать конструкторы копирования.

```cpp
class Student {
public:
    // Конструктор копирования для класса Student
    Student(const Student& other) : age(other.age), name(other.name) {}

protected:
    int age;
    string name;
};

class Employee : public Student {
public:
    // Конструктор копирования для класса Employee
    Employee(const Employee& other) : Student(other), post(other.post) {}

protected:
    string post;
};

class Teacher : public Employee {
public:
    // Конструктор копирования для класса Teacher
    Teacher(const Teacher& other) : Employee(other), stage(other.stage) {}

protected:
    int stage;
};
```

>Для классов Student, Employee и Teacher определить операцию присваивания.

```cpp
class Student {
public:
    // Конструктор с параметрами
    Student(int studentAge, const string& studentName) : age(studentAge), name(studentName) {}

    // Конструктор копирования
    Student(const Student& other) : age(other.age), name(other.name) {}

    // Оператор присваивания
    Student& operator=(const Student& other) {
        if (this != &other) {
            age = other.age;
            name = other.name;
        }
        return *this;
    }

protected:
    int age;
    string name;
};

class Employee : public Student {
public:
    // Конструктор с параметрами
    Employee(int employeeAge, const string& employeeName, const string& employeePost)
        : Student(employeeAge, employeeName), post(employeePost) {}

    // Конструктор копирования
    Employee(const Employee& other) : Student(other), post(other.post) {}

    // Оператор присваивания
    Employee& operator=(const Employee& other) {
        if (this != &other) {
            // Вызываем оператор присваивания базового класса
            static_cast<Student&>(*this) = other;
            post = other.post;
        }
        return *this;
    }

protected:
    string post;
};

class Teacher : public Employee {
public:
    // Конструктор с параметрами
    Teacher(int teacherAge, const string& teacherName, const string& teacherPost, int teacherStage)
        : Employee(teacherAge, teacherName, teacherPost), stage(teacherStage) {}

    // Конструктор копирования
    Teacher(const Teacher& other) : Employee(other), stage(other.stage) {}

    // Оператор присваивания
    Teacher& operator=(const Teacher& other) {
        if (this != &other) {
            // Вызываем оператор присваивания базового класса
            static_cast<Employee&>(*this) = other;
            stage = other.stage;
        }
        return *this;
    }

protected:
    int stage;
};

```

