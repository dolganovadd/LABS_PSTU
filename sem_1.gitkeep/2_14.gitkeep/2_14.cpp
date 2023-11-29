#include <iostream> 

using namespace std;
int main()
{
    int n, a = 0, b;
    cin >> n;
    while (true) {
        b = n % 10;
        if (n < 10) {
            a += n;
            cout << a << endl;
            return 0;
        }
        a += b;
        n = (n - (n % 10)) / 10;
    }
}
