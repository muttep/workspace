#include <iostream>
#include "logger.h"

using namespace std;

Logger* Logger::loggerInstance=nullptr;
int Logger::ctr=0;
mutex Logger::mtx;

Logger::Logger()
{
	ctr++;
	cout<<"New instance created. No of instances "<<ctr<<endl;
}

void Logger::Log(string msg)
{
	cout<<msg<<endl;
}

Logger* Logger::getInstance()
{
	if(loggerInstance == nullptr) {
		mtx.lock();
			if(loggerInstance == nullptr) {
				loggerInstance=new Logger();
			}
		mtx.unlock();
	}
	return loggerInstance;
}