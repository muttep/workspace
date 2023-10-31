#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
#if 0
void work(int &count, mutex &mtx)
{
    for(int i=0; i<1E6; i++)
    {
        mtx.lock();
        count++;
        mtx.unlock();
    }
}
#endif

#if 1
void work(int &count, mutex &mtx)
{
    for(int i=0; i<1E6; i++)
    {
        lock_guard<mutex> guard(mtx);
        count++;
        
    }
}
#endif

#if 0
void work(int &count, mutex &mtx)
{
    for(int i=0; i<1E6; i++)
    {
        unique_lock<mutex> guard(mtx);
        count++;
        
    }
}
#endif

int main()
{
    int count=0;
    mutex mtx;

    thread t1(work, ref(count), ref(mtx));
    thread t2(work, ref(count), ref(mtx));

    t1.join();
    t2.join();

    cout<<"count: "<<count<<endl;

    return 0;
}