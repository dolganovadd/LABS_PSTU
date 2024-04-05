# Быстрая сортировка по Хоару

# Блок-схема
![](https://psv4.userapi.com/c237031/u272768864/docs/d2/30f753dc2561/hoara_sort_png.png?extra=7REbcg0yVgj2VoLsZx12a4jepwN7CW-4MHpci-Ey-dLeESAmMDL7zpDlMX3TWCjbWzTCRGKhS8BhqQLZO3UyGwVYoI1xLSUZIFVphtq2jGrhrkIlk7sQ3mLtRkbIJu4VTIvnI94vlVoFM0JHiRy6h5Dg3y4)

# Код программы
```cpp
#include <iostream>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int HoaraSort(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = HoaraSort(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    system("chcp 1251");
    int size = 25;
    int arr[] = { 1, 0, 2, 0, 3, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 5, 5, 5, 3, 4, 2, 0, 2, 3, 4 };

   cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, size - 1);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

```
# Результаты работы 
![](https://sun9-17.userapi.com/impg/uVX0UO_mWZKhknnSri0W0MMhCmVUutayzZXqsw/ISrajKmUZVQ.jpg?size=605x90&quality=96&sign=168822653288b2ac94760cb02c404d52&type=album)
