#include <iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		cout<<"Non param Base"<<endl;
	}
	Base(int x)
	{
		cout<<"Param Base : "<<x<<endl;
	}
};

class Derived:public Base
{
public:
	Derived()
	{
		cout<<"Non param Derived"<<endl;
	}
	Derived(int y)
	{
		cout<<"Param Derived : "<<y<<endl;
	}

	Derived(int x, int y):Base(x)
	{
		cout<<"Param Derived : "<<y<<endl;
	}
};

int main()
{
	Derived d1;
	cout<<endl;
	Derived d2(10);
	cout<<endl;
	Derived d3(10,20);
	cout<<endl;

	return 0;
}