#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Mutex for synchronization

void printOddNumbers(int limit) {
    for (int i = 1; i <= limit; i += 2) {
        // std::unique_lock<std::mutex> lock(mtx); // Lock the mutex to ensure synchronization
        std::cout << "Odd: " << i << std::endl;
        // lock.unlock(); // Unlock the mutex
    }
}

void printEvenNumbers(int limit) {
    for (int i = 2; i <= limit; i += 2) {
        // std::unique_lock<std::mutex> lock(mtx); // Lock the mutex to ensure synchronization
        std::cout << "Even: " << i << std::endl;
        // lock.unlock(); // Unlock the mutex
    }
}

int main() {
    const int limit = 10; // Define the limit for numbers to be printed

    // Create two threads and pass the functions along with their arguments
    std::thread t1(printOddNumbers, limit);
    std::thread t2(printEvenNumbers, limit);

    // Wait for the threads to finish their execution
    t1.join();
    t2.join();

    return 0;
}
