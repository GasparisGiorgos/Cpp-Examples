#include <iostream>

int main() {

    int a , b , c;;

    std::cout << "give the first number: ";
        std::cin >> a;
    std::cout << "give the second number: ";
        std::cin >> b;
    std::cout << "give the third number: ";
        std::cin >> c;

    std::cout << "the sum of" << a << ", " << b << ", " << c << " is: " << a + b + c << std::endl;
    std::cout << "the multiplication of" << a << ", " << b << ", " << c << " is: " << a * b * c << std::endl;
    std::cout << "the average of" << a << ", " << b << ", " << c << " is: " << (a + b + c) / 3.0 << std::endl;

    return 0;
}