#include <iostream>

using namespace std;

// Normal function definitions
#if 0
int maximum(int a, int b)
{
	return a>b ? a:b;
}
float maximum(float a, float b)
{
	return a>b ? a:b;
}
#endif

template<class T>
T maximum(T a, T b)
{
	return a>b ? a:b;
}

int main()
{
	cout<<maximum(3,4)<<endl;
	cout<<maximum(5.4,2.3)<<endl;

	return 0;
}