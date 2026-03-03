#include <iostream>
using namespace std;

class Box;

// Friend Class declaration
class BoxInspector {
public:
    void printSecretWeight(Box b);
};

// Main Class
class Box {
private:
    int weight; 

public:
    Box(int w); 
    void showWeight(); 

    // Friend declarations
    friend Box combineBoxes(Box b1, Box b2);
    friend class BoxInspector;
};

// --- Definitions Outside the Class ---

Box::Box(int w) { 
    weight = w; 
}

void Box::showWeight() {
    cout << "Box weight: " << weight << " kg" << endl;
}

void BoxInspector::printSecretWeight(Box b) {
    cout << "Inspector sees weight: " << b.weight << " kg" << endl;
}

Box combineBoxes(Box b1, Box b2) {
    int totalWeight;

    totalWeight = b1.weight + b2.weight; 
    Box newBox(totalWeight); 
    return newBox; 
}

// --- Main Program ---

int main() {
    int inputWeight1, inputWeight2;

    // 1. User Input
    cout << "Enter the weight for Box A: ";
    cin >> inputWeight1;
    cout << "Enter the weight for Box B: ";
    cin >> inputWeight2;

    // Create boxes using the user's input
    Box boxA(inputWeight1);
    Box boxB(inputWeight2);

    cout << "\n--- Pass by Value & Return Object ---" << endl;
    Box boxC = combineBoxes(boxA, boxB);
    boxC.showWeight(); 

    cout << "\n--- Friend Class ---" << endl;
    BoxInspector inspector;
    inspector.printSecretWeight(boxC); 

    cout << "\n--- Object Pointers ---" << endl;
    Box* ptr = &boxC; 
    ptr->showWeight(); 

    return 0;
}