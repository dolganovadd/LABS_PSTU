#include <cmath>
#include<iostream>
using namespace std;
int main()
{
    int n, s;
    cin >> n;
    s = sqrt(n);
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}