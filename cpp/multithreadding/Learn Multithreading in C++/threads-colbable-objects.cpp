#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class App
{
private:
    int count=0;
    mutex mtx;
public:
    void operator()()
    {
        for(int i=0; i<1E6; i++)
        {
            lock_guard<mutex> guard(mtx);
            count++;
        }
    }

    int getCount()
    {
        return count;
    }

};

int main()
{
    App app;

    thread t1(app);
    thread t2(app);

    t1.join();
    t2.join();

    cout<<"count: "<<app.getCount()<<endl;

    return 0;
}