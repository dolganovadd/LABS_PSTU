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