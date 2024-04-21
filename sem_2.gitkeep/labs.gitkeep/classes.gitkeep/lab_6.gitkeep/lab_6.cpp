#include <iostream>
#include "list.h"
using namespace std;

void main()
{
	List a(5); 
	cout<<a<<"\n";
	cin>>a;
	cout<<a<<"\n";
	a[2] = 100;
	cout<<a<<"\n";
	List b(10);
	cout<<b<<"\n";
	b = a;
	cout<<b<<"\n";
	List c(10);
	c=b+100;
	cout<<c<<"\n";
	cout << "\nthe length of a=" << a() << endl;

}
