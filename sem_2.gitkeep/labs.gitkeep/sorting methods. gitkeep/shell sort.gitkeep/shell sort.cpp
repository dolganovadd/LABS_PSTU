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