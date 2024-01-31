#include <iostream>
using namespace std;
int main() {
	const int n=5;
    bool flag = true;
    int arr[n] = { 23, 45, 21, 67, 90 };

    for (int i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i - 1]) {
            flag = false;
        }
        }

    if (flag) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
    return 0;
}