# Естественная и многофазная сортировки
# Блок - схема

будет позже

# Код программы
```cpp
//естественное слияние
#include <iostream> 
using namespace std; 
 
void merge(int* v, int r, int t) { 
    int p = 1; //количество элементов в первой серии 
    int k = 1; //количество элементов во второй серии 
    int i = 0; 
    bool flag = false; //флажок для определения надобности второй серии  
 
    while (v[i] <= v[i + 1] && i < r - 1) { //счетчик количества элементов 1 серии 
        p++; 
        i++; 
    } 
    if (v[i] > v[i + 1] && i < r - 1) { 
        i++; 
        flag = true; 
        while (v[i] <= v[i + 1] && i < r - 1) { 
            k++; 
            i++; 
        } 
    } 
    int num = i + 1;  
    int* a = new int[p]; //1 серия 
    int* b = new int[k]; //2 серия 
 
    for (int i = 0; i < p; i++) { 
        a[i] = v[i]; 
    } 
 
    int g = 0; 
    if (flag == true) { 
        for (int i = p; i < p + k; i++) { //заполнение 2 серии 
            b[g] = v[i]; 
            g++; 
        } 
    } 
    int j = 0; 
    int l = 0; 
    if (flag == true) { //проверка на наличие второй надобности слияния 
        for (int i = 0; i < num; i++) { 
            if ((a[l] < b[j] || j >= k) && l < p) { 
                v[i] = a[l]; 
                l++; 
            } 
            else  
            if ((a[l] > b[j] || l >= p) && j < k) { 
                v[i] = b[j]; 
                j++; 
            } 
            else 
            if (a[l] == b[j] && j < k && l < p) { 
                v[i] = a[l]; 
                v[i + 1] = b[j]; 
                l++; 
                j++; 
                i++; 
            } 
        } 
    } 
    delete[] a; 
    delete[] b; 
 
} 
void mergeSort(int* v, int r, int i) { 
    if (i < r) { 
        merge(v, r, i); //функция сортировки 
        mergeSort(v, r, i + 1); //рекурсия 
    } 
} 
 
 
int main() 
{ 
    system("chcp 1251"); 
    int array[25] = {1,2,3,4,5,5,5,5,5,5,0,0,0,0,0,3,3,3,3,4,5,3,1,1,1}; 
 
    cout << "Исходный массив: " << endl; 
    for (int i = 0; i < 25; i++) { 
        cout << array[i]; 
    } 
    cout << endl; 
    mergeSort(array, 25, 0); 
    cout << "Отсортированный массив: " << endl; 
    for (int i = 0; i < 25; i++) { 
        cout << array[i]; 
    } 
}
```

```cpp
//многофазная сортировка
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
```
# Результаты работы 

Естественная сортировка

![](https://sun9-45.userapi.com/impg/mqGs0HYHuEO6c0cwe6OA3RZOHHh0M9fDmSkroA/x97XWenC9DU.jpg?size=316x114&quality=96&sign=37592962d8b05736c5820942b6740f59&type=album)

Многофазная сортировка

![](https://sun9-22.userapi.com/impg/yEQ2ry438TzOjl3U3rWOXiDx4PrzU8g_hjSIeA/lxsTeS7yxAE.jpg?size=385x108&quality=96&sign=ed54458fc33f714b5fe3b44d1701aaae&type=album)
