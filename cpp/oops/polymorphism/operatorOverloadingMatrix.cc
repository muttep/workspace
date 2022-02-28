#include <iostream>

using namespace std;

class Matrix
{
private:
	int m[3][3];
public:
	void accept();
	void display();
	void operator+(Matrix x);
};

void Matrix::accept(void)
{
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			//cout<<" ";
			cin>>m[i][j];
		}
		cout<<endl;
	}
}

void Matrix::display(void)
{
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			cout<<" "<<m[i][j];
		}
		cout<<endl;
	}
}

void Matrix::operator+(Matrix a)
{
	int tmp[3][3];

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			tmp[i][j]=m[i][j]+a.m[i][j];
		}
	}

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			cout<<" "<<tmp[i][j];
		}
		cout<<endl;
	}
}


int main()
{
	Matrix m1,m2,m3;

	cout<<"Enter matrix m1[3][3] elements : "<<endl;
	m1.accept();
	m1.display();
	cout<<"Enter matrix m2[3][3] elements : "<<endl;
	m2.accept();
	m2.display();
	cout<<"Result matrix m3[3][3] elements : "<<endl;
	m1+m2;

	return 0;
}