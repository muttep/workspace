#include <iostream>

using namespace std;

void swap(int &a, int &b)		// This function will act as a "inline" function. Compiler will replace the code at function call it self for "Call by reference functions".
{
	int t;

	t=a;
	a=b;
	b=t;
}

int main()
{
	int a=10, b=20;

	swap(a,b);

	cout<<a<<" "<<b<<endl;

	return 0;
}