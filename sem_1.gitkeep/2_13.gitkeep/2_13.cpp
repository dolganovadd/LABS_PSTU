#include <iostream> 
#include <cmath> 
//a*x*x+b*x+c=0 
using namespace std;

int main() {
	int a, b, c;
	double x1, x2;
	cin >> a >> b >> c;
	if (b * b - 4 * a * c < 0) {
		cout << "False" << endl;
	}
	else {
		if (b * b - 4 * a * c >= 0); {
			x1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
			x2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
			cout << x1 << endl << x2 << endl;
		}
	}
}