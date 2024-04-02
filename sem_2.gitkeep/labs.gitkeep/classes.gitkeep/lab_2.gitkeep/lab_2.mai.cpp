#include "Car.h" 
#include <iostream> 
#include <string> 
using namespace std;

//функция для возврата объекта как результата 
Car makeCar()
{
	string b;
	string m;
	int c;
	cout << "Enter brand: ";
	cin >> b;
	cout << "Enter model: ";
	cin >> m;
	cout << "Enter cost: ";
	cin >> c;
	Car t(b, m, c);
	return t;
}

//функция для передачи объекта как параметра 
void printCar(Car t)
{
	t.show();
}

void main()
{
	//конструктор без параметров 
	Car t1;
	t1.show();

	//коструктор с параметрами 
	Car t2("Lada ", "Vesta", 1500000);
	t2.show();

	//конструктор копирования 
	Car t3 = t2;
	t3.setBrand("Mersedes");
	t3.setModel("Benz");
	t3.setCost(5000000);

	//конструктор копирования 
	printCar(t3);

	//конструктор копирования 
	t1 = makeCar();
	t1.show();
}
