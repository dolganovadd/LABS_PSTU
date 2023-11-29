#include <iostream> 

using namespace std;

int main() {
	int n, b, max_0 = -10000, min = 10000;
	cin >> n;

	for (int a = 0; a < n; a++) {
		cin >> b;
		if (b >= max_0) {
			max_0 = b;
		}
		if (b <= min) {
			min = b;
		}
	}
	cout << max_0 + min << endl;
}