#include <iostream>;
using namespace std;
int main() {
	const int n=5;
	int arr[n] = { 43, 56, 87, 12, 21 };
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}

	}
	cout << "max " << max << endl;
	return 0;
}