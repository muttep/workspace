#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream ifs("my.txt");
	string s1,s2;
	int num;

	ifs>>s1>>num>>s2;
	ifs.close();

	cout<<s1<<endl;
	cout<<num<<endl;
	cout<<s2<<endl;

	return 0;
}