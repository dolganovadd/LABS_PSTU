#include <iostream> 

using namespace std;

int main()
{
	signed int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << n / 2 << endl;
	}
	else {
		n = (n + 1) * (-1);
		cout << n / 2 << endl;
	}
}