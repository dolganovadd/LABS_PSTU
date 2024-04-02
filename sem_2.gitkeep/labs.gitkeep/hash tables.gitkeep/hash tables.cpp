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