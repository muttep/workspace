/*
1. Constructor with no arguments
2. Constructor with only one argument
3. Copy constructor
4. Move constructor
*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class myStringClass
{
	char *str;
public:
	myStringClass();	// Constructor with no arguments
	myStringClass(char *val);	//Constructor with only one argument
	myStringClass(const myStringClass& source);		// copy constructor
	myStringClass(myStringClass&& source);		// Move constructor

	~myStringClass() {
		delete str;
	}
};

myStringClass::myStringClass() : str{nullptr}		// Constructor with no arguments
{
	cout<<"Constructor with no arguments called"<<endl;
	str=new char;
	str[0]='\0';
}

myStringClass::myStringClass(char *val)		//Constructor with only one argument
{
	cout<<"Constructor with only one argument called"<<endl;

	if(val==nullptr) {
		str=new char;
		str[0]='\0';
	} else {
		str=new char[strlen(val)+1];
		strcpy(str,val);
		str[strlen(val)]='\0';

		cout<<"The string passed is : "<<str<<endl;
	}
}

myStringClass::myStringClass(const myStringClass& source)		// copy constructor
{
	cout<<"Copy constructor"<<endl;
	str=new char[strlen(source.str)+1];
	strcpy(str,source.str);
	str[strlen(source.str)]='\0';
}

myStringClass::myStringClass(myStringClass&& source)		// Move constructor
{
	cout<<"Move constructor"<<endl;
	str=source.str;
	source.str=nullptr;
}

int main()
{
	myStringClass a;	// Constructor with no arguments
	cout<<endl;

	char tmp[]="Hello...!!!";

	myStringClass b{tmp};	//Constructor with only one argument
	cout<<endl;

	myStringClass c{a};		// copy constructor
	cout<<endl;

	// cout<<"Here"<<endl;
	myStringClass d{myStringClass{tmp}};		// Move constructor
	cout<<endl;

	vector<myStringClass> vec;
	vec.push_back(myStringClass{ tmp });
	cout<<endl;
	vec.push_back(myStringClass{ tmp });
	cout<<endl;

	return 0;
}
