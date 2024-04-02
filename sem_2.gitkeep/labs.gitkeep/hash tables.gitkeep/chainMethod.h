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


