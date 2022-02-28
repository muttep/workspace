#include <iostream>

using namespace std;

int add(int a, int b)
{
	return a+b;
}
int add(int a, int b, int c)
{
	return a+b+c;
}
float add(float a, float b)
{
	return a+b;
}

int main()
{
	cout<<add(10,20)<<endl;
	cout<<add(10,20,30)<<endl;
	cout<<add(10.5f,20.6f)<<endl;

	return 0;
}