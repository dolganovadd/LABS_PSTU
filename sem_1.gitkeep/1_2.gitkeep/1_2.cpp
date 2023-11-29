#include <iostream>
using namespace std;
int main() {
	float a, b, res;
	cin >> a >> b;
	res = a / b;
	if (b != 0)
	{
		cout << res;
	}
	else
	{
		cout << "no result";
	}

	return 0;
}