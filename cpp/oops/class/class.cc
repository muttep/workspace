#include <iostream>

using namespace std;

class Rectangle {
public:
	int length;
	int breadth;

	int area(void) {
		return length * breadth;
	}

	int perimeter(void) {
		return 2*(length+breadth);
	}
};

int main()
{
	Rectangle r1;

	r1.length = 10;
	r1.breadth = 5;

	cout << "Area : " << r1.area() << endl;
	cout << "Perimeter : " << r1.perimeter() << endl;

	return 0;
}