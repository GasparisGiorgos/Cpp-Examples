#include <iostream>

using namespace std;

class Animal {
public:
    // Εικονική συνάρτηση
    virtual void makeSound() {
        cout << "The animal makes a sound" << endl;
    }
};
class Dog : public Animal {
public:
    // typo in the method and overide will hit
    void makeSound() override { // override: καλή πρακτική για ασφάλεια
        cout << "The dog barks: Woof! Woof!" << endl;
    }
};
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "The cat meows: Meow!" << endl;
    }
};

int main() {
    Animal* myAnimal; // Δείκτης της βασικής κλάσης
    Dog myDog;
    Cat myCat;
    // Ο δείκτης δείχνει στον Σκύλο
    myAnimal = &myDog;
    myAnimal->makeSound(); // Θα εκτελεστεί το Woof! λόγω virtual
    // Ο ίδιος δείκτης δείχνει στη Γάτα
    myAnimal = &myCat;
    myAnimal->makeSound(); // Θα εκτελεστεί το Meow!
    return 0;
}