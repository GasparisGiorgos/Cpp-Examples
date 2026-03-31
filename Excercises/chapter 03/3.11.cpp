#include <iostream>

int main() {
    int a, b, c , max;
    std::cout << "give 3 integers: " << std::endl;
    std::cout << "a: "; 
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;

    if (a > b && a > c) {
        max = a;
    } else if (b > c) {
        max = b;
    } else {
        max = c;
    }

    std::cout << "Max is: " << max << std::endl;
    
    return 0;

}