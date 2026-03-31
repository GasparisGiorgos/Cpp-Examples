#include <iostream>
#include <algorithm> // for std::max

int main() {

    int ex_1, ex_2, ex_3 , max1 , max2;

    std::cout << "give grade of first exercise: " << std::endl;
        std::cin >> ex_1;
    std::cout << "give grade of second exercise: " << std::endl;
        std::cin >> ex_2;
    std::cout << "give grade of third exercise: " << std::endl;
        std::cin >> ex_3;

    max1 = std::max({ex_1, ex_2, ex_3});

    if (max1 == ex_1) {
        max2 = std::max(ex_2, ex_3);
    } else if (max1 == ex_2) {
        max2 = std::max(ex_1, ex_3);
    } else {
        max2 = std::max(ex_1, ex_2);
    }

    std::cout << "the average of the two higheest grades is: " << (max1 + max2) / 2.0 << std::endl;

    return 0;
}