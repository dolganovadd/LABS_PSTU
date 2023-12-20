/* Вариант 5
0,25x^3+x-1,2502=0
[0,2]
Первая производная f'(x): 0,25*3*(pow(x,2)+x)
Вторая производная f''(x): 0,25*3*2*x
Выбираем конец отрезка, в котором истинно выражение f'(x)*f''(x)>0:
A: (0,25*3*(pow(a,2)+x))* (0,25*3*2*a)=0
B: (0,25*3*(pow(b,2)+x))* (0,25*3*2*b)=0,96
Выбираем В
*/
#include<iostream>;
#include<cmath>;
using namespace std;
int main() {
	double a = 0, b = 2, eps = 0.000001, x, xprev;
	xprev = b;
	x = a;
	while (abs(x - xprev) > eps) {
		xprev = x;
		x = xprev - (0, 25 * (pow(xprev, 3)) + xprev - 1, 2502) / (0, 25 * 3 * (pow(xprev, 2) + x));
	}
	cout << "A = " << x << ", B = " << xprev << endl;
	return 0;
}