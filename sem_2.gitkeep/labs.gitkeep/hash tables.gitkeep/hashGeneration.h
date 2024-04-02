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