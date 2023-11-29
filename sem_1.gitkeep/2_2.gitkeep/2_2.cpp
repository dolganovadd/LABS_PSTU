#include <iostream>  
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    int N, b;
    int sum = 1;
    cout << "Введите количество чисел которые нужно умножить: ";
    cin >> N;
    for (int count = 1; count <= N; count++)
    {
        cout << "Введите число: ";
        cin >> b;
        sum *= b;
    }
    cout << sum<<endl;
}