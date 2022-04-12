#include <iostream>

using namespace std;

class car	// It is called Abstact class, as here pure virtual function present. We can not create the object for the Abstract class.
{
public:
	virtual void display()=0;	// It is called pure virtual function.
};

class Innova: public car
{
public:
	void display()
	{
		cout<<"Innova called"<<endl;
	}
};

class Swift: public car
{
public:
	void display()
	{
		cout<<"Swift called"<<endl;
	}
};

int main()
{
	car *p = new Innova;
	p->display();

	p=new Swift();
	p->display();

	return 0;
}