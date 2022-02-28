#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream ofs("my.txt", ios::trunc);
	ofs<<"Hello how are you..."<<endl;
	ofs<<"20"<<endl;
	ofs<<"Thank you";

	ofs.close();

	return 0;
}