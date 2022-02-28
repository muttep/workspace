#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> v={1,2,3,4,5};

	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;

	v.push_front(10);
	v.push_front(20);
	v.push_front(30);
	cout<<"After adding elements at end : ";

	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;

	v.pop_front();
	cout<<"After deleting the lap element : ";
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}