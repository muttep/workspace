#include <iostream>

using namespace std;

int add(int a=0, int b=0, int c=0)
{
	return a+b+c;
}

int maximum(int a=0, int b=0, int c=0)
{
	return a>b && a>c ? a:(b>c ? b:c);
}

int main()
{
	cout<<add()<<endl;
	cout<<add(10)<<endl;
	cout<<add(10,20)<<endl;
	cout<<add(10,20,30)<<endl;
	cout<<endl;

	cout<<maximum()<<endl;
	cout<<maximum(1)<<endl;
	cout<<maximum(2,1)<<endl;
	cout<<maximum(4,2,8)<<endl;

	return 0;
}