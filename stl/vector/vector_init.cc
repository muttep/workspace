#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
	vector<int> var{1, 2, 3};
	//vector<int> :: iterator i;

	cout << "Vector elements are : ";
	for (auto i=var.begin(); i!=var.end(); i++)
		cout << *i << " ";
	cout <<endl;

	for (int i=10; i<=30; i+=10)
		var.push_back(i);

	cout << "Vector elements after push_back() : ";
	for (auto i=var.begin(); i!=var.end(); i++)
		cout << *i << " ";
	cout <<endl;

	cout << "Change vector elements : ";
	for (auto i=var.begin(); i!=var.end(); i++) {
		*i = *i-1;
	}

	for (auto i=var.cbegin(); i!=var.cend(); i++)
		cout << *i << " ";
	cout <<endl;

	cout << "rbegin() and rend() : ";
	for (auto i=var.rbegin(); i!=var.rend(); i++)
		cout << *i << " ";
	cout <<endl;

	cout << "Size : " << var.size() << endl;
	cout << "Capacity : " << var.capacity() << endl;
	cout << "max_size : " << var.max_size() << endl;

	var.resize(4);

	cout << "Size : " << var.size() << endl;

	var.assign( 29, 30);

	cout << "After assign() : ";
	for (auto i=var.begin(); i!=var.end(); i++)
		cout << *i << " ";
	cout <<endl;

	return 0;
}
