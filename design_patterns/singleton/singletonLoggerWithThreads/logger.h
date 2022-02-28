#ifndef logger_h
#define logger_h

#include <mutex>

using namespace std;

class Logger
{
private:
	static Logger* loggerInstance;
	static int ctr;
	static mutex mtx;
	Logger();
	Logger(const Logger &);
	Logger operator=(const Logger &);
public:
	static Logger* getInstance();
	void Log(string msg);
};

#endif