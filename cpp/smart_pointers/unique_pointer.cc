#include <iostream>
#include <memory>

using namespace std;

class Rectangle {
	int length;
	int breadth;

public:
	Rectangle(int l, int b) {
		length=l;
		breadth=b;
	}

	int area() {
		return length*breadth;
	}
};

int main()
{
	unique_ptr<Rectangle> P1(new Rectangle(10,5));
	cout<<"P1 area : "<<P1->area()<<endl;

	unique_ptr<Rectangle> P2;
	P2=move(P1);
	cout<<"P2 area : "<<P2->area()<<endl;
	cout<<"P1 area : "<<P1->area()<<endl;	// Not printing from here
	cout<<"P2 area : "<<P2->area()<<endl;

	// unique_ptr<Rectangle> P2(P1);	// Compilation issue


	return 0;
}