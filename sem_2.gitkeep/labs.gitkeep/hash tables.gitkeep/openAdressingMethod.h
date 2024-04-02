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


