#include <iostream>

int main() {
    
    int choice1 , choice2;
    
    std::cout << "give 2 numbers" << std::endl;
    std::cout << "number 1: ";
        std::cin >> choice1;
    std::cout << "number 2: ";
        std::cin >> choice2;
    
        if (choice1 == 0 || choice2 == 0){
            
            std::cout << "wrong data" << std::endl;
        } else  {
            std::cout << "the addition of them is: " << choice1 + choice2 << std::endl;
    } 
}