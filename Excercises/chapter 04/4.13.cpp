#include <iostream>

int main() {

    double num1, num2;

    std::cout << "give number 1: ";
        std::cin >> num1;
    std::cout << "\ngive number 2: ";
        std::cin >> num2;

    std::cout << "\n     " << num1;
    std::cout << "\n x   " << num2;
    std::cout << "\n============";
    std::cout << "\n     " << num1 * num2;    
}