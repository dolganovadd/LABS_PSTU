#include <iostream>
#include "fraction.h"
using namespace std;

void fraction::Init(double F, int S)
{
	first = F; second = S;
}

void fraction::Read()
{
	cout << "Salary: "; cin >> first;
	cout << "Days worked: "; cin >> second;
}

void fraction::Show()
{	
	cout << "Salary: " << first;
	cout << "Days worked: " << second;
	cout << "\n";
}

double fraction::Summa()
{	
	return (first * second) / 30;
}
