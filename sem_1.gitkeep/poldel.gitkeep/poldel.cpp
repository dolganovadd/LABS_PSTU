/* Вариант 15
3x - 4lnx - 5 = 0
[2;4]
Эпсилон: eps = 0.000001
*/
#include <iostream>
#include <cmath>;
using namespace std;
int main() {
	double a = 2, b = 4, eps = 0.000001, c;
	while (abs(a - b) > eps) {
		c = (a + b) / 2;
		if (((3 * a - 4 * log(a) - 5) * (3 * c - 4 * log(c) - 5)) < 0) { b = c; }
		else if (((3 * b - 4 * log(b) - 5) * (3 * c - 4 * log(c) - 5)) < 0) { a = c; }
		else { cout << "error" << endl; }
	}

	cout << "A=" << a <<","<< "B=" << b << endl;
	return 0;

}
