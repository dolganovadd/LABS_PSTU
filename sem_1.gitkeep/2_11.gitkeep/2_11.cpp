2_11
#include <iostream> 

using namespace std;

int main() {
	int n, b, max_0 = -1000;
	cin >> n;

	for (int a = 0; a < n; a++) {
		cin >> b;
		if (b > 0) {
			cout << "+" << endl;
			return 0;
		}
		if (b < 0) {
			cout << "-" << endl;
			return 0;
		}
	}
}