#include <iostream>

using namespace std;

class Counter {
private:
    int* value; // Pointer to our dynamic integer

public:
    Counter() {
        cout << "Constructing..." << endl;
        value = new int; // Grab some memory
        *value = 0;      // Start at zero
    }

    ~Counter() {
        cout << "Destructing..." << endl;
        delete value;    // Clean up so we don't leak memory
    }

    void set_value(int x) {
        *value = x;
    }

    int get_value() {
        return *value;
    }

    void increase() {
        (*value)++; 
    }

    void print() {
        cout << "Value = " << *value << endl;
    }
};

int main() {
    Counter myCounter; 
    myCounter.print();

    int startNum;
    cout << "\nEnter a starting number: ";
    cin >> startNum;

    myCounter.set_value(startNum);

    cout << "Increasing twice..." << endl;
    myCounter.increase();
    myCounter.increase();

    myCounter.print();

    // The destructor will automatically fire right after this line
    return 0; 
}