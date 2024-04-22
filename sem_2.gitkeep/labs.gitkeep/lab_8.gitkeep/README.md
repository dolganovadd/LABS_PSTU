# Лабораторная работа №8 "Блоковый ввод-вывод"
>Вариант 11

Структура "Владелец автомобиля":
- фамилия, имя, отчество;
- номер автомобиля;
- телефон;
- номер техпаспорта.
  
Удалить элемент с заданным номером, добавить 2 элемента
перед элементом с заданной фамилией.

# Блок - схема

![](https://psv4.userapi.com/c237231/u272768864/docs/d19/ff1fd6b0c644/lab_8.png?extra=AFoPUKBrGpm1NUcd9CFTAbvLSspGfiPsj35mNV5zAsuGq1HBzTJPUqlrcJX-C1yyRiqwn0Qz16-lZ8qAb93QfC9jh_FqPJ4n2Yxn3LlVI_pAZCUKvu93pwTI9Sb1_ZXswm0DProkBDyMoGaGc7bJpDIE5Tk)

# Код программы 

```cpp
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include<string>
#include<stdio.h>

using namespace std;
int n, k; //n - количество исходных автомобилистов; k - заданный номер элемента; t - элемент с заданной Фамилией

//создание структуры, которая хранит информацию о владельцах автомобилей
struct Driver {
    string Surname;//Фамилия
    string carNumber;//Номер машины
    string phoneNumber;//Номер телефона
    string passportNumber;//Номер паспорта
};

string randStr() {
    string str;
    static const char absd[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i(0); i < rand() % 8 + 3; i++) {
        str += absd[rand() % 26];
    }
    return str;
};

string randStr() {
    string str;
    static const char absd[] = "0123456789";
    for (int i(0); i < k; i++) {
        str += absd[rand() % 10];
    }
    return str;
};

string randScore(int tmp) {
    string str;
    if (tmp == 0) str = '1';
    else str = tmp + 0x30;
    return str;
};

int main()
{
    srand((unsigned int)time(nullptr) + (unsigned int)clock());
    FILE* pFile; 
    pFile = fopen("D:\\уник\\яруллин инфа\\семестр 2\\lab_8\\F24.txt", "wb");
    setlocale(LC_ALL, "Rus");
    system("chcp 1251");
    string t;
    cout << "Введите количество водителей автомобилей: ";
    cin >> n;
    Driver arr[50];

    for (int i = 0; i < n; i++) { 
        cout << "Введите фамилию водителя, номер машины, номер телефона и номер паспорта: ";
        arr[i].Surname = randStr();
        arr[i].carNumber = randScore(rand() % 6);
        arr[i].phoneNumber = randScore(rand() % 6);
        arr[i].passportNumber = randScore(rand() % 6);
        
    }
   
    cout << "Исходные данные: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i].Surname << " " << arr[i].carNumber << " " << arr[i].phoneNumber << " " << arr[i].passportNumber << endl;
    }
    cout << endl;
    
    cout << "Введите номер элемента, который нужно удалить: ";
    cin >> k;
    for (int i = k - 1; i < n; i++) {
        arr[i].Surname = arr[i + 1].Surname;
        arr[i].carNumber = arr[i + 1].carNumber;
        arr[i].phoneNumber = arr[i + 1].phoneNumber;
        arr[i].passportNumber = arr[i + 1].passportNumber;
    }
    n--;
    cout << endl;
    cout << "измененный: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i].Surname << " " << arr[i].carNumber << " " << arr[i].phoneNumber << " " << arr[i].passportNumber << endl;
    }
    cout << endl;
    cout << "Введите элемент с заданной фамилией: ";
    cin >> t;
    int m;

    for (int i = 0; i < n; i++) {
        if (arr[i].Surname == t) {
            m = i;
            for (int j = n + 1; j > m; j--) {
                arr[j].Surname = arr[j - 2].Surname;
                arr[j].carNumber = arr[j - 2].carNumber;
                arr[j].phoneNumber = arr[j - 2].phoneNumber;
                arr[j].passportNumber = arr[j - 2].passportNumber;
            }
        }
    }

    cout << endl;
    cout << "Введите 1 новый элемент" << endl;
    arr[m].Surname = randStr();
    arr[m].carNumber = randScore(rand() % 6);
    arr[m].phoneNumber = randScore(rand() % 6);
    arr[m].passportNumber = randScore(rand() % 6);

    cout << endl;
    cout << "Введите 2 новый элемент" << endl;
    arr[m + 1].Surname = randStr();
    arr[m + 1].carNumber = randScore(rand() % 6);
    arr[m + 1].phoneNumber = randScore(rand() % 6);
    arr[m + 1].passportNumber = randScore(rand() % 6);

    cout << endl;
    
    for (int i = 0; i < n + 2; i++) {
        cout << arr[i].Surname << " " << arr[i].carNumber << " " << arr[i].phoneNumber << " " << arr[i].passportNumber << endl;
    }
}

```
