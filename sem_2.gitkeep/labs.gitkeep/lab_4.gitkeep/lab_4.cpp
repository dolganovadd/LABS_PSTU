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

    for (int i = 0; i < 5; i++)
    {
            for (int j = 0; j < n - 1; j++)
            {
                a[j] = a[j+1];
            }
           
            n--;  
    }

    for (int i = n; i < n+3; i++)
    {
        a[i] = rand() % 100;
    }
    n += 3;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}

/* Результаты 

1. n=10
41 67 34 0 69 24 78 58 62 64
24 78 58 62 64 5 45 81

2. n=7
41 67 34 0 69 24 78
24 78 58 62 64

3. n=5
41 67 34 0 69
24 78 58

*/
