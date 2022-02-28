#include <iostream>

using namespace std;

class Rectangle
{
private:
	int length;
	int breadth;

public:
// Constructor
	Rectangle() {		// Non parameterized constructor
		length = 1;
		breadth = 1;
	}

	Rectangle(int l=1, int b=1) {	// Parameterized constructor
		setLength(l);
		setBredth(b);
	}

	Rectangle(Rectangle &r) {		// Copy constructor
		length=r.length;
		breadth=r.breadth;
	}

//Property functions
	/* Mutators */
	void setLength(int l) {
		if (l < 0)
			length = 1;
		else
			length = l;
	}
	void setBredth(int b) {
		if(b < 0)
			breadth = 1;
		else
			breadth = b;
	}

	/* Accesors */
	int getLength() {
		return length;
	}
	int getBreadth() {
		return breadth;
	}

	int area() {
		return length*breadth;
	}
	int perimeter() {
		return 2*(length+breadth);
	}
};

int main()
{
	Rectangle r1(10,5);
	Rectangle r2(r1);


	cout<<"R1 Area : "<<r1.area()<<endl;
	cout<<"R1 Breadth : "<<r1.getBreadth()<<endl<<endl;

	cout<<"R2 Area : "<<r1.area()<<endl;
	cout<<"R2 Breadth : "<<r1.getBreadth()<<endl;

	return 0;
}