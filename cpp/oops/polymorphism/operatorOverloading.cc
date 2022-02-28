#include <iostream>

using namespace std;

class Complex
{
public:
	int real;
	int img;
//public:
	Complex operator+(Complex c) {
		Complex tmp;

		tmp.real = real+c.real;
		tmp.img = img+c.img;

		return tmp;
	}

	Complex operator-(Complex c) {
		Complex tmp;

		tmp.real = real-c.real;
		tmp.img = img-c.img;

		return tmp;
	}
};

int main()
{
	Complex c1,c2,c3;

	c1.real=2; c1.img=3;
	c2.real=3; c2.img=4;

	c3 = c1+c2;

	cout<<"Addition result : "<<c3.real<<"+i"<<c3.img<<endl<<endl;

	c3 = c2-c1;
	cout<<"Subtraction result : "<<c3.real<<"+i"<<c3.img<<endl;

	return 0;
}