#include <iostream>
using namespace std;
int main() {
	int a, b, tmp;
	int* ptr1;
	int* ptr2;

	cin >> a;
	ptr1 = &a;
	tmp = *ptr1;
	cin >> b;
	ptr2 = &b;
	*ptr1 = *ptr2;
	*ptr2 = tmp;

	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

}