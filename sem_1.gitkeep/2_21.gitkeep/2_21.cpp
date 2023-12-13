#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int  tmp, next;
	bool ordered=true;
	cout << "введите число"<<endl;
	cin >> tmp;
	while (tmp != 0) {
		cout << "введите след число"<<endl;
		cin >> next;
			if (next != 0 && next < tmp) {
				ordered = false;
			}
		tmp = next;
	}
	if (ordered) {
		cout << "числа упорядочены по возрастанию" << endl;
	}
	else {
		cout << "числа не упорядочены по возрастанию" << endl;
	}

}