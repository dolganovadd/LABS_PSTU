# Поиски: линейный, интерполяционный, бинарный

# Блок - схемы
> Линейный поиск

![](https://psv4.userapi.com/c909328/u272768864/docs/d34/1de86ef46eb8/linear_search.png?extra=MNSg3o0Zbts1Uj5pw90vQ6PU_URTKZi-Jr0qhu_SmC5N49zlJuEizo1bQYlQunFyadLt_agiTi1aVA2nOw8YsrGTu77X2Fx2ZzGI9ZALBHFwmThsnmLqGSvAGaBoygdH4MAyfTcxqaOXgBQQav0eYdI0BAw)

> Интерполяционный поиск

![](https://psv4.userapi.com/c909328/u272768864/docs/d19/b2a785b6d651/interpolation_search.png?extra=H3HxkxYW1rWqXw54VQaXok0KJ1oONPsd_yRCDFJtAkjD625rzJ1ia-1esnXk6xUNns-rz3CCMOnXk1xQAblCWs0RHbX9Hk4nIaE-_fHwTRvWF_O6p8ryz6_sY5WlkHu7-osz3Rv7IsPSQdwFxnKyBALJLE8)

> Бинарный поиск

![](https://psv4.userapi.com/c909328/u272768864/docs/d13/ce1de0b0a0e5/binary_search.png?extra=qNZMwdYQHabzfURMg6PQK4iCIZGp9-VGGRh-DPto_7c4Bk51rSwAFzQe8fo0qQpuLuIN80bsLhj0mbefv-uu7_-yO6WiECM4Rht64XrDz6_t3v6T2uA7JrjUlrMD54POJvrGglwKxfEphK6sXMOh5ZyEock)

# Код программы 

>Линейный поиск

```cpp
#include <iostream>
#include <ctime>
using namespace std;

//линейный поиск
int linSearch(int arr[], int Size, int target)
{
    for (int i = 0; i < Size; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    system("chcp 1251");
    int array[] = { 6, 2, 8, 4, 5, 1, 7, 3 };
    int size = 8;
    int target = 1;

    int result = linSearch(array, size, target);

    if (result == -1) {
        cout << "Элемент не найден" << endl;
    }
    else {
        cout << "Элемент найден в позиции " << result << endl;
    }

    return 0;
}
```

> Интерполяционный поиск

```cpp
#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int find) {
    int left = 0; //Левая граница области поиска
    int right = size - 1; //Правая граница области поиска

    //цикл поиска по массиву, пока искомое не найдено
    //или пределы поиска еще существуют
    while (left <= right && find >= arr[left] && find <= arr[right]) {
        if (left == right) {
            if (arr[left] == find) {
                return left;
            }
            return -1;
        }
        //текущая позиция массива, с которым сравнивается искомое
        int x = left + (((double)(right - left) / (arr[right] - arr[left])) * (find - arr[left]));
        if (arr[x] == find) {
            return x;
        }
        else if (arr[x] < find) {
            left = x + 1;
        }
        else {
            right = x - 1;
        }
    }
    return -1;
}

int main()
{
    system("chcp 1251");
    int arr[] = { 1,2,5,67,89,100,145,160,1090 }; //массив значений 
    int size = 9;
    int find = 145;
    int index = interpolationSearch(arr, size, find);
    if (index != -1) {
        cout << find << " Найдено на элементе " << index << endl;
    }
    else {
        cout << "Значение не найдено(" << endl;
    }
    return 0;
}
```

> Бинарный поиск

```cpp
#include <iostream>
using namespace std;

int BINsearch(int arr[], int left, int right, int find) {
    bool flag = false;
    //int left = 0; //левая граница множества
    //int right = Size-1; //правая граница множества
    int mid;
    while ((left <= right) && (flag != true)) {
        mid = (left + right) / 2; //вычисление индекса элемента mid
        if (arr[mid] == find) { //сравнивается заданный ключ с элементом mid
            flag = true;
            return mid;
        }
        //если искомое значение элемента множества меньше значения множества с индексом mid,
        //то алгоритм начинает новый поиск в левой половине множества
        if (arr[mid] > find) {
            right = mid - 1;
        }
        //иначе новый поиск ведется в правой половине множества
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    system("chcp 1251");
    int arr[] = { 2, 3, 4, 5, 6, 7, 8 };
    int Size = 7;
    int find = 6;

    int result = BINsearch(arr, 0, Size, find);

    if (result == -1) {
        cout << "Элемент не найден" << endl;
    }
    else {
        cout << "Элемент найден в позиции " << result << endl;
    }

    return 0;
}

```

# Результаты работы 

> Линейный поиск

![](https://sun9-66.userapi.com/impg/0g6y1zRoXRkzIbjCof25rCI-yChPzkT8VjA22Q/fd7pdXQDIJo.jpg?size=344x71&quality=96&sign=ea29c83963d7a81fc9861e49a3a52e59&type=album)

> Интерполяционный поиск

![](https://sun9-11.userapi.com/impg/N4259T51PZkVAIbgykRTphYrtzoXwH48PtYLoA/vr1uCE8XxOU.jpg?size=281x76&quality=96&sign=2f6713d908718f2a39fb6a480bbc5018&type=album)

> Бинарный поиск

![](https://sun9-22.userapi.com/impg/a2fmqx3lNsydcGyHgRhNhbCffVgVlqnLjVAlEw/BeIFCqL4TVM.jpg?size=267x71&quality=96&sign=164df00abb9dd6118fe1ed1a6e6c87ba&type=album)




