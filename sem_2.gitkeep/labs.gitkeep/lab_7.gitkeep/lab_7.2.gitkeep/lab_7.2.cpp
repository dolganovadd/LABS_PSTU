#include<iostream>
#include<cmath>
#include <stdarg.h>
using namespace std;
int kvadr(int m,...) {
	va_list ptr;
	va_start(ptr, m);
	int k = 0;
	for (; m != 0; m--) {
		int tmp;
		tmp = va_arg(ptr, int);
		if (pow((int)sqrt(tmp), 2) == tmp) {

			k += 1;
		}

	}
	va_end(ptr);
	return k;
}

int main() {
	cout << kvadr(3, 4, 8, 2) << endl;
	cout << kvadr(7, 6, 2, 9, 5, 16, 8, 5) << endl;
	cout << kvadr(11, 6, 9, 70, 45, 36, 49, 84, 5, 2, 3, 1) << endl;
	return 0;
}
