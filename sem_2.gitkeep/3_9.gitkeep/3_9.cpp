#include <iostream>

using namespace std;

int main()
{
    int n;

    int a[100];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            i--;
            n--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
