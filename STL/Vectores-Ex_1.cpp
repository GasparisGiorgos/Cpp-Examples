#include <iostream>
#include <vector>

int main() {

    // Create a vercotor consisting of intigers
    std::vector<int> numbers;

    std::cout << "Enter 5 ingegers: " << std::endl;
    
    for (int i = 0; i < 5; i++) {

        int num;
        std::cin >> num;
        numbers.push_back(num);

    }

    std::cout << "The numbers you entered are: " << std::endl;
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << std::endl;
    }

    
}