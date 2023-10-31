#include <iostream>
#include <stdexcept>

int main() {
    try {
        int numerator, denominator, result;
        
        std::cout << "Enter numerator: ";
        std::cin >> numerator;
        
        std::cout << "Enter denominator: ";
        std::cin >> denominator;
        
        if (denominator == 0) {
            throw std::runtime_error("Division by zero is not allowed.");
        }
        
        result = numerator / denominator;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
