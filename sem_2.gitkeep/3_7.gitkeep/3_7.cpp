#include <iostream>
using namespace std;
int main() {
	const int n = 5;
	int arr[n] = { 32, 43, 56, 12, 56 };
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
		else if (arr[i] < min) {
			min = arr[i];
		}
	}	
	cout << "max=" << max << endl;
	cout << "min=" << min << endl;
}