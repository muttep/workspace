#include <iostream>

using namespace std;

class Toy {
protected:
	string name;
	float price;

public:
	virtual void prepareParts()=0;
	virtual void combineParts()=0;
	virtual void assembleParts()=0;
	virtual void applyLabel()=0;
	virtual void showProduct()=0;

};

class Car : public Toy {
public:
	void prepareParts() {
		cout<<"Preparing car parts"<<endl;
	}

	void combineParts() {
		cout<<"Combining car parts"<<endl;
	}

	void assembleParts() {
		cout<<"Assembling car parts"<<endl;
	}

	void applyLabel() {
		cout<<"Applying car label"<<endl;
		name="car";
		price=10.10;
	}

	void showProduct() {
		cout<<"Name : "<<name<<"\t"<<"Price : "<<price<<endl<<endl;
	}
};

class Bike : public Toy {
public:
	void prepareParts() {
		cout<<"Preparing bike parts"<<endl;
	}

	void combineParts() {
		cout<<"Combining bike parts"<<endl;
	}

	void assembleParts() {
		cout<<"Assembling bike parts"<<endl;
	}

	void applyLabel() {
		cout<<"Applying bike label"<<endl;
		name="bike";
		price=20.20;
	}

	void showProduct() {
		cout<<"Name : "<<name<<"\t"<<"Price : "<<price<<endl<<endl;
	}
};

class Flight : public Toy {
public:
	void prepareParts() {
		cout<<"Preparing flight parts"<<endl;
	}

	void combineParts() {
		cout<<"Combining flight parts"<<endl;
	}

	void assembleParts() {
		cout<<"Assembling flight parts"<<endl;
	}

	void applyLabel() {
		cout<<"Applying flight label"<<endl;
		name="flight";
		price=30.30;
	}

	void showProduct() {
		cout<<"Name : "<<name<<"Price : "<<price<<endl<<endl;
	}
};