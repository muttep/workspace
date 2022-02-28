#include <iostream>

#include "object.cpp"

using namespace std;

class ToyFactory {
public:
	static Toy * CreateToy(int toyType) {
		
		Toy *toy = NULL;

		switch(toyType) {
			case 1 : {
					toy = new Car;
					break;
			}
			case 2 : {
					toy = new Bike;
					break;
			}
			case 3 : {
					toy = new Flight;
					break;
			}

			default : {
				cout<<"Invalid toy type. Please enter right toy type : "<<endl;
				return NULL;
			}
		}

		toy->prepareParts();
		toy->combineParts();
		toy->assembleParts();
		toy->applyLabel();
		toy->showProduct();

		return toy;
	}
};