#include <iostream>

using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
    // Constructor: sets up the rectangle when it is created
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    // Calculates and returns the area
    int area() {
        return width * height;
    }

    // Prints the width and height
    void print() {
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
    }
};

int main() {
    int inputWidth;
    int inputHeight;

    // 1. Get the dimensions from the user
    cout << "Please enter the width: ";
    cin >> inputWidth;
    
    cout << "Please enter the height: ";
    cin >> inputHeight;

    cout << "\n--- Rectangle Info ---" << endl;

    // 2. Dynamically create the object using 'new'
    // This gives us a POINTER to the rectangle, not the rectangle itself.
    Rectangle* myRectangle = new Rectangle(inputWidth, inputHeight);

    // 3. Print the info and the area
    // Because myRectangle is a pointer, we must use the arrow -> instead of a dot .
    myRectangle->print();
    cout << "Area: " << myRectangle->area() << endl;

    // 4. Free the memory! (Very important)
    delete myRectangle;

    return 0;
}