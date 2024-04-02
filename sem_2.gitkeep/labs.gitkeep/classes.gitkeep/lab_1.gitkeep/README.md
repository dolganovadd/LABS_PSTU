**Лабораторная работа №1 - Классы и объекты. Инкапсуляция.**
>Вариант 11

Поле first – дробное положительное число, оклад, поле second – целое положительное число, количество отработанных дней. Реализовать метод summa() –вычисление начисленной суммы за данное количество дней по формуле: оклад/количество_дней_месяца*количество_отработанных _дней

**Контрольные вопросы**
>Что такое класс?

Классы в С++ — это абстракция описывающая методы, свойства ещё не существующих объектов.
> Что такое объект (экземпляр) класса?

Объект (экземпляр)– это отдельный представитель класса, имеющий конкретное состояние и поведение, полностью определяемое классом.
>Как называются поля класса?

Данные, относящиеся к классу, называются полями класса.
>Как называются функции класса?

Классы имеют свои функции, которые называются методами класса.
>Для чего используются спецификаторы доступа?

Модификаторы доступа (или спецификаторы доступа) — это ключевые слова в объектно-ориентированных языках, которые устанавливают доступность классов, методов и других элементов.

>Для чего используется спецификатор public?

Модификатор public (общий) используется в языке C++ для указания на то, что свойства и методы класса доступны без ограничений.

>Для чего используется спецификатор private?

Private (закрытый) — указывает на то, что свойства и методы доступны только внутри класса;
>Если описание класса начинается со спецификатора class, то какой спецификатор 
доступа будет использоваться по умолчанию?

Private
>Если описание класса начинается со спецификатора struct, то какой спецификатор 
доступа будет использоваться по умолчанию?

Public

>Какой спецификатор доступа должен использоваться при описании интерфейса 
класса? Почему?

Спецификатор public - для доступа к методам интерфейса.

>Каким образом можно изменить значения атрибутов экземпляра класса?

Ввод или изменение параметров в методе.

>Каким образом можно получить значения атрибутов экземпляра класса?

s->name.

>Класс описан следующим образом 
struct Student
{
string name; 
int group;
………
};
Объект класса определен следующим образом 
Student *s=new Student;
Как можно обратиться к полю name объекта s?

s.name = "name".

>Класс описан следующим образом 
class Student
{
string name; 
int group;
…….
};
Объект класса определен следующим образом 
Student *s=new Student;
Как можно обратиться к полю name объекта s?

s->name.

>Класс описан следующим образом 
class Student
{
string name; 
int group; 
public:
…..
};
Объект класса определен следующим образом 
Student s;
Как можно обратиться к полю name объекта s?

s.name

>Класс описан следующим образом 
class Student
{
public:
char* name; 
int group;
………
};
Объект класса определен следующим образом 
Student *s=new Student;
Как можно обратиться к полю name объекта s?

s->name.

