# Естественная и многофазная сортировки
# Блок - схема

будет позже

# Код программы
```cpp
﻿// естественное слияние и многофазная сортировка

#include <iostream>
using namespace std;
const int Size = 25;
int t[26];
int ta;
void Merge(int c[], int d[], int l, int m, int r);
void PhaseSort(int arr[])
{
    bool flag = true;
    int gap = Size;
    while (gap > 1 || flag)
    {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        flag = false;
        for (int i = 0; i < Size - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                flag = true;
            }
        }
    }
}
void MergePass(int x[], int y[], int s, int n)
{
    int i = 0;
    while (i <= ta - 2 * s)
    {
        int r = ((i + 2 * s) < ta) ? t[i + 2 * s] : n;

        Merge(x, y, t[i], t[i + s] - 1, r - 1);
        i = i + 2 * s;
    }
    if (i + s < ta)
        Merge(x, y, t[i], t[i + s] - 1, n - 1);
    else  if (i < ta)
    {
        for (int j = t[i]; j <= n - 1; j++)
            y[j] = x[j];
    }
}
void MergeSort(int a[], int n)
{
    int* b = new int[n];
    int s = 1;
    while (s < ta)
    {
        MergePass(a, b, s, n);
        s += s;
        MergePass(b, a, s, n);
        s += s;
    }
}
void Merge(int c[], int d[], int l, int m, int r)
{
    int i = l, j = m + 1, k = r;

    while ((i <= m) && (j <= r))
    {
        if (c[i] <= c[j])
            d[l++] = c[i++];
        else
            d[l++] = c[j++];
    }
    if (i > m)
        for (int q = j; q <= r; q++)
            d[l++] = c[q];
    else
        for (int p = i; p <= m; p++)
            d[l++] = c[p];
}
void GetBPoint(int a[], int b[], int n, int& m)
{
    int j = 0;
    b[j++] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
            b[j++] = i + 1;
    }
    m = j;
}
int menu()
{
    cout << "1 - многофазная сортировка\n2 - естественная сортировка\nВведите цифру соответствующую тому какой метод сортировки применить: ";
    int n;
    cin >> n;
    return n;
}
void CoutArray(int arr[])
{
    for (int i = 0; i < Size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
    int array[Size];
    for (int i = 0; i < Size; i++) { array[i] = rand() % 10; }
    cout << "Исходный массив: ";
    CoutArray(array);
    switch (menu())
    {
    case 1:
        PhaseSort(array);
        cout << "Отсортированный массив: ";
        CoutArray(array);
        break;
    case 2:
        GetBPoint(array, t, Size, ta);
        MergeSort(array, Size);
        cout << "Отсортированный массив: ";
        CoutArray(array);
        break;
    default:
        cout << "Неправильный выбор " << endl;
        break;
    }
    return 0;
}
```
# Результаты работы 

![Многофазная сортировка](https://sun9-53.userapi.com/impg/t9R4waGAfi4gOOBijmP86qNefwMyVxAEX9N8SA/XJkf_9MoXBE.jpg?size=625x102&quality=96&sign=c7145c2999888ebeccb35af53890ce9d&type=album)

![Естественная сортировка](https://sun9-22.userapi.com/impg/xGVstlHqrOIvLATPoK4NYrMPmNBObjVkcZE5sA/h7nqzsRfeSY.jpg?size=618x97&quality=96&sign=35149b6596a281b96e38f0d13c78d7b2&type=album)
