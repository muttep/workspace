#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool isOdd = true; // Indicates whether the next number to be printed is odd or even
const int limit = 10; // Define the limit for numbers to be printed

void printNumbers(bool odd) {
    for (int i = odd ? 1 : 2; i <= limit; i += 2) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [odd, i] { return (i % 2 == 1) == odd; });
        std::cout << i << " "; // Print the number
        isOdd = !odd; // Switch the turn
        lock.unlock();
        cv.notify_one(); // Notify the other thread to print
    }
}

int main() {
    std::thread t1(printNumbers, true); // Thread for odd numbers
    std::thread t2(printNumbers, false); // Thread for even numbers

    t1.join();
    t2.join();

    std::cout << std::endl;
    return 0;
}
