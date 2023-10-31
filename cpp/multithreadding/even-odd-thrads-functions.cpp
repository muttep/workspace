#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int counter = 1;
const int limit = 10; // Define the limit for numbers to be printed

void printOdd() {
    while (counter <= limit) {
        // std::unique_lock<std::mutex> lock(mtx);
        if (counter % 2 != 0) {
            std::cout << "Odd: " << counter << std::endl;
            counter++;
        }
        // lock.unlock();
    }
}

void printEven() {
    while (counter <= limit) {
        // std::unique_lock<std::mutex> lock(mtx);
        if (counter % 2 == 0) {
            std::cout << "Even: " << counter << std::endl;
            counter++;
        }
        // lock.unlock();
    }
}

int main() {
    std::thread t1(printOdd); // Thread for printing odd numbers
    std::thread t2(printEven); // Thread for printing even numbers

    t1.join();
    t2.join();

    return 0;
}
