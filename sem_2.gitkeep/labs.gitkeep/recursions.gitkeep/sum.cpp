#include <iostream>
#include <cmath>
using namespace std;

int fact(double n) {
    if (n <= 1) return 1;
    else return n * fact(n - 1);
}

double sum(double n, double x) {
    const double PI = 3.141592653589793;
    if (n == 0) return 1;
    else return  ((cos((n*x)) / fact(n))) + sum(n - 1, x);
}

int main() {
    double n, x, k = 0;
    cin >> n >> x;
    cout << sum(n, x) << endl;
}