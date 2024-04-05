# Сортировка Шелла 

# Блок - схема
![](https://psv4.userapi.com/c909228/u272768864/docs/d39/b69a0bc3b029/shell_sort_png.png?extra=Xx3onXhb-D5ccAZInsgKmBZLbZrmsCMJqzf9kb30zuJYFnIBnjAi-pKwzVl-x_ZVAr1ifjNHPw9GwO7W8SE0iNQgpTXp8nllbJVFSuUrCPP8U9HLxPwDeFx2GiiDFAtX09S3RvTGk-uCIwi2O1pkRqILGLc)

# Код программы
```cpp
#include <iostream>
using namespace std;

void shellSort(int arr[], int size) {
    for (int step = size / 2; step > 0; step /= 2) {
        for (int i = step; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= step && arr[j - step] > temp; j -= step) {
                arr[j] = arr[j - step];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    system("chcp 1251");
    int size = 25;
    int arr[] = { 3, 3, 2, 4, 1, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 5, 5, 5, 3, 4, 2, 1, 2, 3, 4 };

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    shellSort(arr, size);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
```
# Результаты работы 

![](https://sun9-52.userapi.com/impg/LpOP4XVTEMbZwXg_sqyj8a58cAvy9UF4z__Uxg/BftDYLZzPgQ.jpg?size=574x111&quality=96&sign=b98359d21575dc518412d597e0e27330&type=album)
