#include <iostream>

int main() {
    
    std::string name;

    std::cout << "give name: ";
        std::cin >> name;

    if (name[0]== 'C') {
        std::cout << "correct";
    } else {
        std::cout << "wrong";
    }
}