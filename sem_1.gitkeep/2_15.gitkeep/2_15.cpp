#include <iostream> 

using namespace std;
int main()
{
    int n, a, b = 1;
    cin >> n >> a;
    while (true) {
        b = n % 10;
        if (a == b) {
            cout << "True" << endl;
            return 0;
        }
        if (n < 10) {
            return 1;
        }
        n = n / 10;
    }

}