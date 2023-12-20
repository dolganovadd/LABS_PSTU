
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int d = n / 2;
	//задняя грань
	for (int i = 0; i < d + 1; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < n; i++)
	{
		cout << "* ";
	}
	cout << endl;
	//диагонали верхние
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < d - i; j++)
		{
			cout << " ";
		}
		cout << "* ";
		for (int j = 0; j < n + 2; j++)
		{
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << "*" << endl;
	}
	//передняя верхняя грань
	for (int i = 0; i < n; i++)
	{
		cout << "* ";
	}
	for (int i = 0; i < d - 1; i++)
	{
		cout << " ";
	}
	cout << "*" << endl;
	//боковые грани-пустой квадрат
	for (int i = 0; i < n - d; i++)
	{
		cout << "* ";
		for (int j = 0; j < n + 2; j++)
		{
			cout << " ";
		}
		cout << "* ";
		for (int j = 0; j < d - 1; j++)
		{
			cout << " ";
		}
		cout << "*" << endl;
	}
	//нижние диагонали
	for (int i = 0; i < d - 1; i++)
	{
		cout << "* ";
		for (int j = 0; j < n + 2; j++)
		{
			cout << " ";
		}
		cout << "*";
		for (int j = 1; j < d - i; j++)
		{
			cout << " ";
		}
		cout << "*" << endl;
	}
	//нижние грани
	for (int i = 0; i < n; i++)
	{
		cout << "* ";
	}
	return 0;
}