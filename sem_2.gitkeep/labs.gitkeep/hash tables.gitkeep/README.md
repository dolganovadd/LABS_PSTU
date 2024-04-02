# **Лабораторная работа "Хеш-таблицы".**
>Вариант 11
![](https://sun9-38.userapi.com/impg/Z-f0IFQuxnvAStqz31yfYxnfWHbzmmgjhtaz3w/q7kKCcN_3zQ.jpg?size=1186x118&quality=96&sign=fe111cb1c4dbce000d66153caf441869&type=album)

# **Блок-схема**
будет

# **Код программы**

>Hash Tables
```cpp
#include <iostream>
#include <string>

#include "chainMethod.h"
#include "openAdressingMethod.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	cout << "Выберите способ сортировки: \n" << "1. Открытая адресация" << "2. Метод цепочек";
	int n;
	cin >> n;
	switch (n) {
	case 1: {
		hashTableOpAdr* people = new hashTableOpAdr;
		people->setHashTable(100);
		people->showTable();
		hashTableChain* people = new hashTableChain;
		break;
	}
	case 2: {
		hashTableChain* people = new hashTableChain;
		people->setHashTable(100);
		people->ShowTable();
		break;
	}
	default: {
		cout << "Выберите номер 1 или номер 2" << endl;
		break;
	}
	}
}
```
>hashGeneration

```cpp
#pragma once

#include <iostream>
#include <string>

using namespace std;

//H(k)=k mod M
int hashGeneration(int size, string str) {
	unsigned int key = 0;
	for (int i(0); i < str.size(); i++) {
		key += str[i];
	}
	return static_cast<int>(key) % size;
}
```
>openAdressingMethod
```cpp
#pragma once
#include "hashGeneration.h"
#include <iostream>
#include <string>

using namespace std;

struct nodeTableOpAdr {
	string name{ " " };
	string passport{ " " };
	string phone{ " " };
};

struct hashTableOpAdr {
	const int sizeTable = 45;
	nodeTableOpAdr* table = new nodeTableOpAdr[sizeTable];

	void setTable(string name, string passport, string phone) {
		int hash = hashGeneration(sizeTable, phone);
		while (table[hash % (sizeTable)].phone != " ") {
			if (++hash - sizeTable == sizeTable) {
				break;
			}
			if (hash - sizeTable < sizeTable) {
				table[hash % sizeTable].name = name;
				table[hash % sizeTable].passport = passport;
				table[hash % sizeTable].phone = phone;
			}
		}
	}

	void showTable() {
		for (int i = 0; i < sizeTable; i++) {
			printf("[%s]{%s} ", table[i].name.c_str(), table[i].phone.c_str());
			cout << endl;
			
		}
	}

	void setHashTable(int count) {
		auto randStr = []() {
			string str;
			static const char letters[] = "qwertyuiopasdfghjklzxcvbnm";
			for (int i = 0; i < rand() % 8 + 3; i++) {
				str += letters[rand() % 26];
			}
			return str;
			};

		auto randNumber = []() {
			string numPh = "7";
			for (int i = 0; i < 10; i++) {
				numPh += rand() % 10 + 0x30;
				return numPh;
			}
			};

		for (int i = 0; i < count; i++) {
			setTable(randStr(), randNumber(), randNumber());
		}
	}
};
```
>chainMethod
```cpp
#pragma once

#include "hashGeneration.h"
#include <iostream>
#include<string>

using namespace std;

struct nodeTableChain {
	string name{ ' ' };
	string passport{ ' ' };
	string phone{ ' ' };

	nodeTableChain* next = nullptr;
	nodeTableChain* prev = nullptr;

	int size = 0;
};

struct hashTableChain {
	const int sizeTable = 45;
	nodeTableChain* table = new nodeTableChain[sizeTable];

	void setTable(string name, string passport, string phone) {
		int hash = hashGeneration(sizeTable, phone);
		
		if (table[hash].phone != " ") {
			nodeTableChain* newNode = new nodeTableChain;
			newNode->name = name;
			newNode->passport = passport;
			newNode->phone = phone;
			nodeTableChain* tmp = &table[hash];

			for (int i = 0; i < table[hash].size - 1; i++) {
				tmp = tmp->next;
				tmp->next = newNode;
				newNode->prev = tmp;
				table[hash].size++;
			}
		}
		else {
			table[hash].name = name;
			table[hash].passport = passport;
			table[hash].phone = phone;
			table[hash].size++;
		}
	}

	void ShowTable() {
		for (int i = 0; i < sizeTable; i++) {

			if (table[i].size == 0) {
				continue;
			}
			else {
				nodeTableChain* tmp = &table[i];

				for (int j = 0; j <= table[i].size && tmp != nullptr; j++) {
					cout << '[' << tmp->name << ']' << '{' << tmp->phone << '}';
					tmp = tmp->next;
				}
				cout << endl;
			}
		}
	}

	void setHashTable(int count) {
		auto randStr = []() {
			string str;
			static const char letters[] = "qwertyuiopasdfghjklzxcvbnm";
			for (int i = 0; i < rand() % 8 + 3; i++) {
				str += letters[rand() % 26];
			}
			return str;
			};

		auto randNumber = []() {
			string numPh = "7";
			for (int i = 0; i < 10; i++) {
				numPh += rand() % 10 + 0x30;
				return numPh;
			}
			};

		for (int i = 0; i < count; i++) {
			setTable(randStr(), randNumber(), randNumber());
		}
	};
};

```
