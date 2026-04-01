#include <iostream>


int main() {

    int liters, price;

    std::cout << "give liters: ";
        std::cin >> liters;

    int cost = liters;
    int amount_to_be_paid = 0;

    while (amount_to_be_paid < cost) {
        amount_to_be_paid += 50;
    }


    int change = amount_to_be_paid - cost;

    int bills_20 = change / 20;
    change = change % 20;

    int bills_10 = change / 10;
    change = change % 10;

    int bills_5 = change / 5;
    change = change % 5;

    int coins2 = change / 2;
    change = change % 2;

    int coins1 = change;


    std::cout << "cost: " << cost << std::endl;
    std::cout << "amount to be paid: " << amount_to_be_paid << std::endl;

    std::cout << "change: " << change << std::endl;
    std::cout << "bills of 20: " << bills_20 << std::endl;
    std::cout << "bills of 10: " << bills_10 << std::endl;
    std::cout << "bills of 5: " << bills_5 << std::endl;
    std::cout << "2-euro coins: " << coins2 << "\n";
    std::cout << "1-euro coins: " << coins1 << "\n";
}