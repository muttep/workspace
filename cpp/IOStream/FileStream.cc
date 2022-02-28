#include <iostream>
#include <fstream>
//#include <string>

using namespace std;

class Student
{
public:
	string name;
	int roll;
	string branch;

	friend ofstream & operator<<(ofstream &ofs, Student &s);
	friend ifstream & operator>>(ifstream &ifs, Student &s);
};

ofstream & operator<<(ofstream &ofs, Student &s)
{
	ofs<<s.name<<endl;
	ofs<<s.roll<<endl;
	ofs<<s.branch<<endl;

	return ofs;
}

ifstream & operator>>(ifstream &ifs, Student &s)
{
	ifs>>s.name>>s.roll>>s.branch;

	return ifs;
}

int main()
{
	Student s1,s2;

	s1.name="Raju111";
	s1.roll=10;
	s1.branch="ECE1";

	ofstream ofs("my.txt", ios::trunc);
	ofs<<s1;

	ofs.close();

	ifstream ifs("my.txt");
	ifs>>s2;

	cout<<s2.name<<endl;
	cout<<s2.roll<<endl;
	cout<<s2.branch<<endl;

	ifs.close();

	return 0;
}