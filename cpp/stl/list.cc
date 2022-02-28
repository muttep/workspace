#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> v={1,2,3,4,5};

	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	cout<<"After adding elements at end : ";

	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;

	v.pop_back();
	cout<<"After deleting the lap element : ";
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}