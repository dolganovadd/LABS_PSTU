#include <iostream>
using namespace std;

float diff(float a, float b) {
	return a - b;
}

double diff(double a, double b) {
	return a - b;
}

int main() {
	setlocale(LC_ALL, "RU");

	float a;
	cout << "Введите первое число" << endl;
	cin >> a; 
	
	float b;
	cout << "Введите второе число" << endl;
	cin >> b;

	cout << "Разность:"<<diff(a, b) << endl;

	double c;
	cout << "Введите первое число" << endl;
	cin >> c;

	double d;
	cout << "Введите второе число" << endl;
	cin >> d;

	cout << "Разность"<<diff(a, b) << endl;
	return 0;
}