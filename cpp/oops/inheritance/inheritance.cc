#include <iostream>

using namespace std;

class Base
{
public:
	int x;
	Base(int x1=0)
	{
		x=x1;
	}
	void display() {
		cout<<"Base class x = "<<x<<endl;
	}
};

class Derived:public Base
{
public:
	int y;
	Derived(int y1)
	{
		y=y1;
	}
	void show() {
		cout<<"Derived class y = "<<y<<endl;
	}
};

int main()
{
	Base b(10);
	b.display();

	Derived d(20);
	d.show();
	d.display();

	return 0;
}