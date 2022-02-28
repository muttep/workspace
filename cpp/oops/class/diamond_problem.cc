#include <iostream>

using namespace std;

class person
{
public:
    person() {
        cout<<"Person default constructor"<<endl;
    }
	person(int x) {
		cout<<"Person class called"<<endl;
	}	
};

class father : virtual public person
{
public:
	father(int x):person(x) {
		cout<<"father class called"<<endl;
	}
};

class mother : virtual public person
{
public:
	mother(int x):person(x) {
		cout<<"Mother class called"<<endl;
	}
};

class child : public father, public mother
{
public:
	child(int x):father(x),mother(x) {
		cout<<"Child calss called"<<endl;
	}
};


int main()
{
	child c(30);
    cout<<"done"<<endl;
    person p(1);    // If need to call perameterized constructur explicitly. Call with the objet

	return 0;
}