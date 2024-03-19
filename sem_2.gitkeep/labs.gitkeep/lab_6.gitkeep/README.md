# **Лабораторная работа №6 "Строки".**

Задана строка, состоящая из символов. Символы
объединяются в слова. Слова друг от друга отделяются
одним или несколькими пробелами. В конце текста ставится
точка. Текст содержит не более 255 символов. Выполнить
ввод строки, используя функцию Gets(s) и обработку
строки в соответствии со своим вариантом.

Вариант 11

Преобразовать строку таким образом, чтобы в ее
начале были записаны слова, содержащие только цифры,
потом слова, содержащие только буквы, а затем слова,
которые содержат и буквы и цифры.

# Блок - схема
![](https://sun9-18.userapi.com/impg/2t1KgPzEYMGgRMaCu3s-FeGUaGv0YaNJCEzy2A/cqGwYe_fBc0.jpg?size=736x626&quality=95&sign=34ab1183eac340ba23e46f9d51bca34f&type=album)

# Код программы 
```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

bool onlyNumbers(const string& str) {
	return all_of(str.begin(), str.end(), isdigit);
}

bool onlyLetters(const string& str) {
	return all_of(str.begin(), str.end(), isalpha);
}

int main() {
	setlocale(LC_ALL, "RU");
	string str, word;
	string numbersOnly, lettersOnly, mixedWords;
	cout <<"Введите строку" << endl;
	getline(cin, str);
	istringstream iss(str);
	while (iss >> word) {
		if (onlyNumbers(word)) {
			numbersOnly += word + " ";
		}
		else if (onlyLetters(word)) {
			lettersOnly += word + " ";
		}
		else {
			mixedWords += word + " ";
		}
	}
	string result;
	result = numbersOnly + lettersOnly + mixedWords;
	cout << result;

}
```

