#include <iostream>

using namespace std;
int main() {
	int n, tmp;
	cin >> n;
	int arr[4] = { 41,42,66,77 };

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= n / 2; i++) {
		tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}