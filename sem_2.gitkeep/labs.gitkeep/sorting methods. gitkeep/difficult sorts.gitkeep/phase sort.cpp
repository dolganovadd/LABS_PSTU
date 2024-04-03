#include <iostream> 
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    int* temp = new int[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }

    delete[] temp; // освобождение памяти 
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void multiPhaseSort(int arr[], int size) {
    int phaseSize = 1;

    while (phaseSize < size) {
        int left = 0;

        while (left < size - 1) {
            int mid = std::min(left + phaseSize - 1, size - 1);
            int right = std::min(left + 2 * phaseSize - 1, size - 1);

            merge(arr, left, mid, right);

            left += 2 * phaseSize;
        }

        phaseSize *= 2;
    }
}

int main() {
    system("chcp 1251");
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    multiPhaseSort(arr, size);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // освобождение памяти 

    return 0;
}