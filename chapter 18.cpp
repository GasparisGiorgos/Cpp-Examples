#include <iostream>
#include <string>

float radius, side;

void formated_IO();

int main() {

    using namespace std;

    int choice;

    do {
        cout << "\n================================" << endl;
        cout << "   CHOOSE A SECTION TO RUN" << endl;
        cout << "================================" << endl;
        cout << "1. Formated I/O " << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "--------------------------------\n" << endl;

        switch (choice) {
            case 1: formated_IO(); break;
            case 0: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}

void formated_IO() {

    bool isConnected = true;
    int memoryAddress = 4095;
    int elevation = 142;
    double roundTarget = 100.0;

    std::cout << "--- Network Status ---\n";

    // Boolean Alpha (boolalpha)
    // Prints "true" or "false" instead of "1" or "0"
    std::cout.setf(std::ios_base::boolalpha);
    std::cout << "Connected: " << isConnected << '\n';

    // Show Base and Uppercase (showbase, uppercase)
    // showbase adds "0x" for hex (or "0" for octal)
    // uppercase makes the "0x" -> "0X" and "a-f" -> "A-F"
    std::cout.setf(std::ios_base::showbase);
    std::cout.setf(std::ios_base::uppercase);
    std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
    std::cout << "Address:   " << memoryAddress << '\n';

    // Reset back to decimal before the next integer prints
    std::cout.setf(std::ios_base::dec, std::ios_base::basefield);

    std::cout << "\n--- Telemetry ---\n";

    //Show Positive Sign (showpos)
    // Forces a '+' sign in front of positive numbers
    std::cout.setf(std::ios_base::showpos);
    std::cout << "Elevation: " << elevation << " meters\n";

    // Turn off showpos so it doesn't affect our floating point number
    std::cout.unsetf(std::ios_base::showpos);

    // 5. Show Point (showpoint)
    // Forces the decimal point to print, even if the number is a whole number like 100.0
    std::cout.setf(std::ios_base::showpoint);
    std::cout << "Target:    " << roundTarget << '\n';
    
}