# 4 сортировки
блочная, подсчетом, слияния, быстрая по Ломуто
# Блок-схемы 
>Блочная сортировка

![](https://psv4.userapi.com/c909218/u272768864/docs/d19/0ed95a143905/bucket_sort.png?extra=roYC-XCcPhbp8g422MiIk6WhSnUlosWeqb_8Tfe32Gf2b9mcdx99fCwoTSMxmbMQKnh6zourpxHhPVNrUH3vJAXddiz_ez1_u4eFAgmtuqlzFYzas1gHLC8Sjm8o8POLA4hShnU9XaDrQp79NIQ8Yo6clpk)

>Сортировка подсчетом

![](https://psv4.userapi.com/c909218/u272768864/docs/d27/99702547627d/counting_sort.png?extra=1GwfBWWeB8NuRPWA3s-iViQ0qxoz3iUyjHDmYAmR62R5LSvCmBDTsYUNnlMfnHahdgmzTgdJAFvoBWgdfg1A-NGkCqqCNWnYqLZ3TwhfeR2cM_s_EZbpG2QrOlrYnl85vVcYd2Pj1PVFLur0OfJjNXHbgrY)

>Сортировка слиянием

![](https://psv4.userapi.com/c909218/u272768864/docs/d22/b7a149656441/merge_sort.png?extra=0q_QZXhO14oY20VnZSieN-lBT3FJdTmTgrjPurZ9Ls5J5OpYPqdIq3vi7sDsEs62pgHiFYy4JiJ4uMpxsiPBQDYnBG03rxNbzOtAcXNEtVSAtmo2LBwElFcEgskouPLpzjQkGuJhajr1ECxEsy68BDEmYtI)

>Быстрая по Ломуто

![](https://psv4.userapi.com/c909218/u272768864/docs/d37/0c5400c9d884/quick_sort.png?extra=e5lwKkZW0c1I514rC4YOn2nXZ1hfue2XpIjnCKP8Z88PpBRLVQwSbT16IPkbMa09CtJPedlU6mWoJ329-uN5-CsTi9O1d_V5eC4VmTwYiZzItCPU9PM3i0yGDGxLXu8-REtzukKB0h6kOPY-quRcYt3FmKE)

# Код программы
```cpp
#include <iostream>
using namespace std;

//Блочная сортировка
void bucketSort(int array[], int size, int minValue, int maxValue) {
    int bucketCount = maxValue - minValue + 1;  // Количество блоков

    // Создаем блоки
    int* buckets = new int[bucketCount];
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = 0;
    }

    // Считаем количество элементов в каждом блоке
    for (int i = 0; i < size; i++) {
        buckets[array[i] - minValue]++;
    }

    // Записываем элементы из блоков обратно в исходный массив
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        while (buckets[i] > 0) {
            array[index++] = i + minValue;
            buckets[i]--;
        }
    }

    // Освобождаем память, выделенную для блоков
    delete[] buckets;
}

// Сортировка подсчетом 
void countingSort(int array[], int size, int minValue, int maxValue) {
    int range = maxValue - minValue + 1;  // Диапазон чисел
    int* count = new int[range] {0};  // Массив для подсчета частоты

    // Подсчет частоты встречаемости чисел
    for (int i = 0; i < size; i++) {
        count[array[i] - minValue]++;
    }

    int index = 0;
    // Перезапись отсортированных чисел в исходный массив
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            array[index++] = i + minValue;
            count[i]--;
        }
    }

    // Освобождение памяти
    delete[] count;
}

// Сортировка слиянием
void merge(int array[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Создаем временные массивы
    int* L = new int[n1];
    int* R = new int[n2];

    // Копируем данные во временные массивы L и R
    for (i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[middle + 1 + j];
    }

    // Объединяем временные массивы L и R обратно в основной массив array[]
    i = 0;  // Индекс первого подмассива
    j = 0;  // Индекс второго подмассива
    k = left;  // Индекс слияния подмассивов

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы L[], если таковые имеются
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы R[], если таковые имеются
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    // Освобождаем память от временных массивов
    delete[] L;
    delete[] R;
}

// Рекурсивная функция для сортировки слиянием
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Рекурсивно сортируем две половины
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Сливаем две половины
        merge(array, left, middle, right);
    }
}

//Быстрая по Ломуто
// Функция для обмена двух элементов массива
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция разделитель (поиск опорного элемента и перестановка элементов относительно него)
int partition(int array[], int low, int high) {
    int pivot = array[high];  // Выбираем последний элемент массива как опорный
    int i = (low - 1);  // Индекс для меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному, меняем элементы местами
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[high]);
    return (i + 1);
}

// Рекурсивная функция сортировки
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Индекс разделения
        int pi = partition(array, low, high);

        // Рекурсивные вызовы для сортировки подмассивов до и после разделителя
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int menu()
{
    cout << "\n1 - Блочная сортировка\n2 - Сортировка подсчетом\n3 - Сортировка слиянием\n4 - Быстрая по Ломуто\nВыберите сортировку ";
    int n;
    cin >> n;
    return n;
}



int main() {
    system("chcp 1251");
    int array[25] = { 2, 4, 3, 1, 0, 5, 5, 2, 3, 4, 1, 0, 5, 3, 2, 4, 1, 3, 0, 2, 4, 1, 5, 0, 3 };
    int size = sizeof(array) / sizeof(array[0]);
    int minValue = 0;  // Минимальное значение в массиве
    int maxValue = 5;  // Максимальное значение в массиве

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    switch (menu()) {
    case 1: 
        bucketSort(array, size, minValue, maxValue);
        cout << "Отсортированный массив: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        break;
    case 2:
        countingSort(array, size, minValue, maxValue);
        cout << "Отсортированный массив: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        break;
    case 3:
        mergeSort(array, 0, size - 1);
        cout << "Отсортированный массив: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        break;
    case 4:
        quickSort(array, 0, size - 1);
        cout << "Отсортированный массив: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        break;
    }

    cout << endl;

    

    return 0;
}
```

# Результаты работы 

>Блочная сортировка

![](https://sun9-32.userapi.com/impg/N2OETKXLyG0PRzGLwX1hJpNHeIhvoFBKMSlx8g/JGECauKPXX8.jpg?size=614x175&quality=96&sign=8850081b53905203a053aafcb6364104&type=album)

>Сортировка подсчетом

![](https://sun9-74.userapi.com/impg/X-9lRm3PbTq6iM2i1Gmcq2WU5VOsDdpqqL8gkQ/XfYGPcNuX54.jpg?size=633x177&quality=96&sign=b4f407014fe46a5ef41e8e14f5aeffac&type=album)

>Сортировка слиянием

![](https://sun9-79.userapi.com/impg/cGqqpSLFEStiT3fjhJAO2SuZAlLtAhA_QK30AA/taS6Jjugrd0.jpg?size=629x171&quality=96&sign=e1334daed62724f6b66224ff7e871e76&type=album)

>Быстрая по Ломуто

![](https://sun9-30.userapi.com/impg/48i_kYZcWsy9siyaidRK--zmEQRxYhvPc_IMjg/R5Czybvjk6M.jpg?size=616x173&quality=96&sign=2a70d9df706c78a3e6d18d51c804b4c4&type=album)
