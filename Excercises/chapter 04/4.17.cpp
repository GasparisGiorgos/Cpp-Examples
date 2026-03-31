#include <iostream>

int main(){

    std::cout << "1-Print the word 'Hello'" << std::endl;
    std::cout << "2-Print the number 2" <<std::endl;
    std::cout << "3-Prin 'bye bye'" <<std::endl;
    std::cout << "4-Do nothing" <<std::endl;
    std::cout << "Give choice: ";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: std::cout << "Hello" << std::endl; break;
        case 2: std::cout << "2" << std::endl; break;
        case 3: std::cout << "bye bye" << std::endl; break;
        case 4: break;
        default: std::cout << "wrong choice" << std::endl; break;
    }
}