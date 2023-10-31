#include <iostream>
#include <thread>

using namespace std;

void work()
{
    for(int i=0; i<10; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout<<"Loop: "<<i<<endl;
    }
}

int main()
{
    // work();
    thread t1(work);
    thread t2(work);

    t1.join();
    t2.join();

    return 0;
}