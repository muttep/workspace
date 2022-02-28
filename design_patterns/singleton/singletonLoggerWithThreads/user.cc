/*
Source : https://www.youtube.com/watch?v=oeQWxhlnCHM
*/

/*
	Threads consept is available from c++11, so need to add teh -std=c++11 flag for compilation and for -pthread for threads.
	Copile command : g++ -std=c++11 -pthread -o singleton *.cc		// Note : Put all files in same directory
*/

#include <iostream>
#include <thread>
#include "logger.h"

using namespace std;

void user1logs()
{
	Logger* logger1=Logger::getInstance();
	logger1->Log("This message is from user 1");
}

void user2logs()
{
	Logger* logger2=Logger::getInstance();
	logger2->Log("This message is from user 2");
}


int main()
{
	thread t1(user1logs);
	thread t2(user2logs);
	
	t1.join();
	t2.join();

	return 0;
}