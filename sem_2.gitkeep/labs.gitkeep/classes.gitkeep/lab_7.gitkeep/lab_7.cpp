#include <iostream>
#include "list.h"
#include "money.h"

using namespace std;

int main() {
	int k = 1;
	int size = 5;
	List<int> A(size);
	cout << "A: "; A.show();
	cout << "A[k]: " << A[k] << endl;
	cout << "A: " << A() << endl;

	List<int> B(size);
	cout << "B: "; B.show();
	cout << "B: " << B() << endl;

	List<int> C(size);
	C = A + B;
	cout << "C = A + B: "; C.show();

	/////////////
	Money<long, int> a(10203040, 110);
	a.show();
	Money<long, int> b(1000000, 21);
	b.show();

	return 0;
}
