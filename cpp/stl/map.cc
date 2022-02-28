#include <iostream>
#include <map>

using namespace std;


int main()
{
	map<int, string> m;

	m.insert(pair<int, string> (1,"Raju"));
	m.insert(pair<int, string> (2,"Ravi"));
	m.insert(pair<int, string> (3,"Ranga"));

	map<int,string>::iterator itr;

	for(itr=m.begin(); itr!=m.end(); itr++) {
		cout<<itr->first<<" "<<itr->second<<endl;
	}
	cout<<endl;

	map<int,string>::iterator itr2;
	itr2=m.find(2);
	cout<<"Found : ";
	cout<<itr2->first<<" "<<itr2->second<<endl;

	return 0;
}