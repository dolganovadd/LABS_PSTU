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