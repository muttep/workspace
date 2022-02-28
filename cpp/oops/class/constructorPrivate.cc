#include <iostream>

using namespace std;

class PrivateClass
{
private:
	int a;	
public:
	PrivateClass() {
		a=1;
	}
	void setdata(int x) {
		a=x;
	}
	int getData(void) {
		return a;
	}
};

int main()
{
	PrivateClass *p1=new PrivateClass;

	//p1->a=10;	not allowed as a is a private member
	// p1->setdata(10);
	cout<<"a : "<<p1->getData()<<endl;

	return 0;
}