#include <iostream>
using namespace std;
int main() {
	const int n = 5;
	int arr[n] = { 32, 43, 56, 12, 56 };
	int max = arr[0];
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (max <  arr[i]) {
			max = arr[i];
			k++;
		}
		
	}
	cout << "max " << max << endl;
	cout << k;
}