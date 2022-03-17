#include <iostream>

using namespace std;
#if 0
class smartPtr{
private:
	int *ptr;
public:
	explicit smartPtr(int *p=NULL) {
		ptr=p;
	}

	~smartPtr() {
		delete ptr;
	}

	int& operator*() {
		return *ptr;
	}
};

int main()
{
	smartPtr ptr(new int());
	*ptr=200;
	cout<<*ptr<<endl;

	return 0;
}
#else

template <class T>
class smartPtr {
private:
	T *ptr;
public:
	explicit smartPtr(T *p=NULL) {
		ptr=p;
	}

	~smartPtr() {
		delete ptr;
	}

	T& operator*() {
		return *ptr;
	}

	T* operator->() {
		return &ptr;
	}
};

int main()
{
	smartPtr<int> ptr(new int());
	*ptr=200;
	cout<<*ptr<<endl;

	return 0;
}

#endif