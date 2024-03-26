
#include <iostream>
#include <cmath>
using namespace std;

class Summa{
    
private:
    double first; //оклад
    int second; //количество отработанных дней
    
public:
    Summa(double f, int s):
    first(f), second(s) {}
    
    double calculateSumma(){
        int month = 30;
        return round(first/month * second)-1;
    }
};

int  main(){
//    setlocale(LC_ALL, 'RU');
    
    double payment;
    cout<<"Введите сумму оклада";
    cin>>payment;
    int daysWorked;
    cout<<"Введите количество отработанных дней";
    cin>>daysWorked;
    Summa salary(payment, daysWorked);
    double totalSalary=salary.calculateSumma();
    cout<<"Начисленная сумма за"<<daysWorked<<"дней - "<<totalSalary<<"рублей";
    
    return 0;
}
