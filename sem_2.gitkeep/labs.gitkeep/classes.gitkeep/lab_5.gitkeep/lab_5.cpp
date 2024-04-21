#include "object.h"
#include "object.h"
#include "time.h"
#include "vector.h"
#include <iostream>

using namespace std;

int main() {
	Triad a;

	cin >> a;
	cout << a << endl;

	Object* p = &a;
	p->Show();

	Time b;

	cin >> b;
	cout << b << endl;

	p = &b;
	p->Show();

	Vector v(5);
	Triad c;
	Time d;

	cin >> c >> d;

	p = &c;
	v.Add(p);
	p = &d;
	v.Add(p);

	cout << v;

	return 0;
}
