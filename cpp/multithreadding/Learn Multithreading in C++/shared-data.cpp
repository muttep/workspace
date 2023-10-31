#if 0
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    int count = 0;
    // const int ITERATIONS =1000;
    const int ITERATIONS =1E6;      // 1 million

    thread t1([&count](){
        for(int i=0; i<ITERATIONS; i++)
        {
            // count++;
            ++count;
        }
    });

    thread t2([&count](){
        for(int i=0; i<ITERATIONS;i++)
        {
            // count++;
            ++count;
        }
    });

    // cout<<"count: "<<count<<endl;

    t1.join();
    t2.join();

    cout<<"count: "<<count<<endl;

    return 0;
}
#endif

#if 0
#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

int main()
{
    // int count = 0;
    atomic<int> count = 0;
    // const int ITERATIONS =1000;
    const int ITERATIONS =1E6;      // 1 million

    thread t1([&count](){
        for(int i=0; i<ITERATIONS; i++)
        {
            // count++;
            ++count;
        }
    });

    thread t2([&count](){
        for(int i=0; i<ITERATIONS;i++)
        {
            // count++;
            ++count;
        }
    });

    // cout<<"count: "<<count<<endl;

    t1.join();
    t2.join();

    cout<<"count: "<<count<<endl;

    return 0;
}
#endif

#if 0
#include <iostream>
#include <thread>
// #include <atomic>

using namespace std;

int main()
{
    int count = 0;
    // atomic<int> count = 0;
    // const int ITERATIONS =1000;
    const int ITERATIONS =1E6;      // 1 million

    auto func = [&count](){
        for(int i=0; i<ITERATIONS; i++)
        {
            // count++;
            ++count;
        }
    };

    thread t1(func);
    thread t2(func);

    // cout<<"count: "<<count<<endl;

    t1.join();
    t2.join();

    cout<<"count: "<<count<<endl;

    return 0;
}
#endif

#if 1
#include <iostream>
#include <thread>
// #include <atomic>

using namespace std;

int main()
{
    int count = 0;
    // atomic<int> count = 0;
    // const int ITERATIONS =1000;
    const int ITERATIONS =1E6;      // 1 million

    auto func = [&](){
        for(int i=0; i<ITERATIONS; i++)
        {
            // count++;
            ++count;
        }
    };

    thread t1(func);
    thread t2(func);

    // cout<<"count: "<<count<<endl;

    t1.join();
    t2.join();

    cout<<"count: "<<count<<endl;

    return 0;
}
#endif