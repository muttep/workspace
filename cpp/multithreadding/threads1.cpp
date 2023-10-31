#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void thread1()
{
	while(1) {
		for(int i=11; i<=15; i++) {
			std::unique_lock<std::mutex> lock(mtx);
			std::cout<<"Thread1 "<<i<<std::endl;
			lock.unlock();
			std::this_thread::sleep_for(std::chrono::seconds(1));
			
		}
	}

}

void thread2()
{
	while(1) {
		for(int i=21; i<=25; i++) {
			std::unique_lock<std::mutex> lock(mtx);
			std::cout<<"Thread2 "<<i<<std::endl;
			lock.unlock();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
}

int main()
{
	std::thread t1(thread1);
	std::thread t2(thread2);

	t1.join();
	t2.join();

	return 0;
}