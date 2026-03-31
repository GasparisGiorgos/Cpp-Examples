#include <iostream>

using namespace std;

class IntArray {
private:
    int* data;
    int size;

public:
    // Constructor: memory for 'n' integers and sets them to 0
    IntArray(int n) {
        size = n;
        data = new int[size]; // brackets for an array
        
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    ~IntArray() {
        cout << "Destroying array..." << endl;
        delete[] data; // delete[] (with brackets) for arrays
    }

    void set(int index, int value) {
        // Quick safety check to make sure the index actually exists
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    int get(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        return 0; 
    }

    void print() {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int sum() {
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += data[i];
        }
        return total;
    }
};

int main() {
    int arraySize;
    
    cout << "How many numbers do you want in your array?: ";
    cin >> arraySize;

    IntArray myArray(arraySize);

    cout << "Please enter " << arraySize << " numbers:" << endl;
    for (int i = 0; i < arraySize; i++) {
        int userInput;
        cin >> userInput;
        myArray.set(i, userInput);
    }

    cout << "\n--- Results ---" << endl;

    myArray.print();
    cout << "Sum = " << myArray.sum() << endl;

    return 0;
}