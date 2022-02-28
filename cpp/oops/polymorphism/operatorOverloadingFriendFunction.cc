#include <iostream>

using namespace std;

class Complex
{
private:
	int real;
	int img;
public:
	Complex(int r=0, int i=0)
	{
		real=r;
		img=i;
	}
	void display(void)
	{
		cout<<real<<"+i"<<img<<endl;
	}

	friend Complex operator+(Complex c1, Complex c2);
};

Complex operator+(Complex c1, Complex c2)
{
	Complex c3;
	c3.real=c1.real+c2.real;
	c3.img=c1.img+c2.img;
	return c3;
}

int main()
{
	Complex a1(2,3),a2(3,4),a3;

	a3=a1+a2;
	a3.display();

	return 0;
}