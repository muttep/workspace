#include <iostream>

using namespace std;

class Rectangle
{
private:
	int length;
	int breadth;

public:
// Constructor
	Rectangle();
	Rectangle(int l=1, int b=1);
	Rectangle(Rectangle &r);

//Property functions
	/* Mutators */
	void setLength(int l);
	void setBredth(int b);

	/* Accesors */
	int getLength() { return length;}
	int getBreadth() { return breadth;}

	int area();
	int perimeter();
	bool isSquare();

	~Rectangle();
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

Rectangle::Rectangle() {
	length = 1;
	breadth = 1;
}
Rectangle::Rectangle(int l, int b) {
	setLength(l);
	setBredth(b);
}
Rectangle::Rectangle(Rectangle &r) {
	length=r.length;
	breadth=r.breadth;
}
int Rectangle::area() {
	return length*breadth;
}
int Rectangle::perimeter() {
	return 2*(length+breadth);
}
bool Rectangle::isSquare() {
	return length==breadth;
}
void Rectangle::setLength(int l) {
	if (l < 0)
		length = 1;
	else
		length = l;
}
void Rectangle::setBredth(int b) {
	if(b < 0)
		breadth = 1;
	else
		breadth = b;
}
Rectangle::~Rectangle(){
	cout<<"Rectangle distroyed"<<endl;
}