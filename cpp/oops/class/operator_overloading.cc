#include <iostream>

using namespace std;

class Complex {
	int real, imag;
public:
	Complex(int r=0, int i=0) {
		real=r;
		imag=i;
	}

	Complex operator+(const Complex &obj) {
		Complex res;
		res.real=real+obj.real;
		res.imag=imag+obj.imag;
		return res;
	}

	void display() {
		cout<<real<<" + i"<<imag<<endl;
	}
};

int main()
{
	Complex c1(2,3),c2(3,2);
	Complex c3=c1+c2;
	c3.display();

	return 0;
}