#include <iostream>

using namespace std;

class Rectangle
{
public:
	int length;
	int breadth;

	int area() {
		return length*breadth;
	}

	int perimeter() {
		return 2*(length+breadth);
	}
};

int main()
{
#if 0
	Rectangle r1;		// Store in Stack
	Rectangle *ptr;		// Store in heap

	ptr = &r1;

	//r1.length = 10;
	//r1.breadth = 5;
#endif

	Rectangle *ptr = new Rectangle;		// Store in heap. It is creating object in heap dynamically.

	ptr->length = 10;
	ptr->breadth = 5;

	cout <<"Area : " << ptr->area() <<endl;
	cout <<"Perimeter : " <<ptr->perimeter() <<endl;

	return 0;
}