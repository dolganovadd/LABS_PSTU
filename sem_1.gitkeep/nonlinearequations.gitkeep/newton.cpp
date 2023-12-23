/* Вариант 5
0,25x^3+x-1,2502=0
[0,2]
Первая производная f'(x): 0,75 *pow(x,2)+1
Вторая производная f''(x): 1,5*x
Выбираем конец отрезка, в котором истинно выражение f(x)*f''(x)>0:
A: (0,25a^3+a-1,2502)* (1,5*a)=0
B: (0,25b^3+b-1,2502)* (1,5*b)=2,7498
*/
#include<iostream>;
#include<cmath>;
using namespace std;
int main() {
	float x, xprev;
	xprev = 0;
	x = 2;
	double eps = 0.000001;
	while (abs(x - xprev) > eps) {
		xprev = x;
		x = xprev -( (0, 25 * (pow(xprev, 3)) + xprev - 1, 2502) / (0, 75 * (pow(xprev, 2)) + 1));
	}
	cout << "x=" << x << endl;
	return 0;
}