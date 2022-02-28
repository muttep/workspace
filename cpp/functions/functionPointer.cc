#include <iostream>

using namespace std;

int add(int a, int b)
{
	return a+b;
}

int main()
{
#if 0	
	int (*fp)(int,int);		// Function pointer decleration
	fp=add;					// Initialization
	int r=(*fp)(10,20);		// Function call
	cout<<r<<endl;
#endif

	int (*fp)(int,int) = add;	// Decleration come initialization
	int r=(*fp)(10,20);			// Call
	cout<<r<<endl;

	return 0;
}