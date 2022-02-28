#include <iostream>

using namespace std;

class emp {
private:
	int a;
	int b;
	int *p;

	// emp& operator=(const emp &e);
	// emp& operator=(const emp &e) {
	// 	cout<<"Operrator = overloading"<<endl;
	// 	if(this != &e) {
	// 		// p=new int;
	// 		*p=*(e.p);
	// 	}
	// 	return *this;
	// }

public:
	emp() {
		cout<<"Default constructor called"<<endl;
	}

	emp(int x) {
		cout<<"Single Perameterized constructor called : "<<x<<endl;

		p=new int(x);
		// *p=x;		
	}
	emp(int x, int y, int z) {
		cout<<"Three perameterized constructor called"<<endl;
		a=x;
		b=y;
		p=new int;
		*p=z;		// Shallow copy both source and operend address are same
	}

	void display() {
		cout<<"a : "<<a<<endl;
		cout<<"b : "<<b<<endl;
		cout<<"p : "<<p<<endl;
		cout<<"*p : "<<*p<<endl<<endl;
	}
#if 1
	emp(const emp &e) {
		cout<<"Copy constructor called"<<endl;
		a=e.a;
		b=e.b;
		p=new int;
		*p=*e.p;		// Deep copy, both members address are different
	}
#endif

	~emp() {
		cout<<"Calling disctructor"<<endl;
		delete[] p;
	}

	emp& operator=(const emp &e);

	// emp& operator=(const emp &e) {
	// 	cout<<"Operrator = overloading"<<endl;
	// 	if(this != &e) {
	// 		// p=new int;
	// 		*p=*(e.p);
	// 	}
	// 	return *this;
	// }

	void setA(int x) {
		a=x;
	}

	void setB(int x) {
		b=x;
	}

	void setP(int x) {
		p=new int(x);
		*p=x;
	}
};

emp& emp::operator=(const emp &e) {
	cout<<"Operrator = overloading"<<endl;
	if(this != &e) {
		// p=new int;
		*p=*(e.p);
		a=e.a;
		b=e.b;
	}
	return *this;
}


int main ()
{
	// emp e=1;
	emp e(1);

	emp e1(10,20,30);
	cout<<"Display e1"<<endl;
	e1.display();

	cout<<"----"<<endl;

	emp e2=e1;
	cout<<"Display e2"<<endl;
	e2.display();

	e1.setA(11);
	e1.setB(22);
	e1.setP(33);

	cout<<"Display after e1 modification"<<endl;
	e1.display();

	cout<<"Display after e2 modification"<<endl;
	e2.display();


	cout<<"After copy constructor"<<endl;
	// emp e3(e2);
	// emp e3=e2;
	// emp e3;
	// e3=e2;
	// cout<<"Display e3"<<endl;
	// e3.display();

	emp e3(100,200,300);
	emp e4(1,2,3);
	e4=e3;
	cout<<"Display e4"<<endl;
	e4.display();
	e3.setP(555);
	cout<<"Display e3"<<endl;
	e3.display();

	cout<<"Display e4"<<endl;
	e4.display();

	return 0;
}