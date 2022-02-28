#include <iostream>

using namespace std;

void swap(int a, int b)		// Swapping wont with with this function, means in call by value as it is the function call, updated values wont be coped back to main variables.
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