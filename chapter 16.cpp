#include <iostream>
#include <string>

// 1. BASE CLASS (The Parent)
class Vehicle {
protected: 
    std::string brand; 

public:
    Vehicle(std::string b);
    void startEngine();
};



// 2. DERIVED CLASS (The Child)
// "class Car : public Vehicle" means Car inherits everything from Vehicle
class Car : public Vehicle {
private:
    std::string model;

public:
    Car(std::string b, std::string m);
    void showDetails();
};



// --- Definitions Outside the Class ---

// Base Class Definitions
Vehicle::Vehicle(std::string b) : brand(b) {
}

void Vehicle::startEngine() {
    std::cout << "The " << brand << " engine is starting... Vroom!" << std::endl;
}

// Derived Class Definitions
Car::Car(std::string b, std::string m) : Vehicle(b), model(m) {
}

void Car::showDetails() {
    std::cout << "Car Brand: " << brand << " | Model: " << model << std::endl;
}

// --- Main Program ---
int main() {
    std::string inputBrand;
    std::string inputModel;

    std::cout << "--- Create Your Car ---" << std::endl;
    std::cout << "Enter the car brand (e.g., Toyota): ";
    std::cin >> inputBrand;
    std::cout << "Enter the car model (e.g., Corolla): ";
    std::cin >> inputModel;

    std::cout << "\n--- Building the Car ---" << std::endl;
    
    Car myCar(inputBrand, inputModel);

    myCar.showDetails();

    myCar.startEngine();

    return 0;
}