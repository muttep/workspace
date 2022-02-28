#include <iostream>

using namespace std;

class Rectangle
{
private:
	int length;
	int breadth;

public:
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
	Rectangle r1;

	r1.setBredth(10);
	r1.setLength(5);

	cout<<"Area : "<<r1.area()<<endl;
	cout<<"Breadth : "<<r1.getBreadth()<<endl;

	return 0;
}