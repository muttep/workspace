/*
Youtube video : https://www.youtube.com/watch?v=XyNWEWUSa5E (and) https://www.youtube.com/watch?v=tv54FY48Vio&list=PLliXPok7ZonlZJuAN0hvUnf5ovFepjxU0&index=3
code link : https://github.com/cppnuts-yt/designpattern/tree/master/Factory%20Design%20Pattern
*/

#include <iostream>

#include "toyFactory.cpp"

using namespace std;

int main()
{
	int toyType;

	while(1) {
		cout<<"Enter the toy type <1-car, 2-bike, 3-flight, 0-exit> : ";
		cin>>toyType;

		if(!toyType)
			break;

		Toy *t = ToyFactory::CreateToy(toyType);

		if(t) {
			t->showProduct();
			delete t;
		}

	}

	cout<<"Exit..."<<endl;

	return 0;
}