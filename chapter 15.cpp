#include <iostream>
#include <string>

class rectangle {
private:
    float length;
    float width;

public:
    std::string colour;
    
    // Constructors
    rectangle(float a, float b);
    rectangle();
    
    void set_ab(float a, float b);
    float area();
    void info();

    // 1. Arithmetic Operators
    rectangle operator+(const rectangle& other);
    rectangle operator-(const rectangle& other); 

    // 2. Comparison Operators
    bool operator==(const rectangle& other);     
    bool operator<(const rectangle& other);      

    // 3. Unary Operator
    void operator++();                           
};

// --- Definitions Outside the Class ---

void rectangle::set_ab(float a, float b) {
    length = a;
    width = b;
}

float rectangle::area() {
    return length * width;
}

void rectangle::info() {
    std::cout << "Length: " << length << " | Width: " << width << " | Colour: " << colour << std::endl; 
}

rectangle::rectangle(float a, float b) {
    length = a;
    width = b;
    colour = "";
}

rectangle::rectangle() {
    length = 0.0;
    width = 0.0;
    colour = "Not Given";
}

// 1. Arithmetic Overloads
rectangle rectangle::operator+(const rectangle& other) {
    float newLength = this->length + other.length;
    float newWidth = this->width + other.width;
    rectangle combinedRect(newLength, newWidth);
    combinedRect.colour = "Mixed Colour";
    return combinedRect;
}

rectangle rectangle::operator-(const rectangle& other) {
    float newLength = this->length - other.length;
    float newWidth = this->width - other.width;
    
    // Prevent negative dimensions
    if (newLength < 0) newLength = 0;
    if (newWidth < 0) newWidth = 0;

    rectangle subRect(newLength, newWidth);
    subRect.colour = "Subtracted Colour";
    return subRect;
}

// 2. Comparison Overloads
bool rectangle::operator==(const rectangle& other) {
    return (this->length == other.length && this->width == other.width);
}

bool rectangle::operator<(const rectangle& other) {
    float myArea = this->length * this->width;
    float otherArea = other.length * other.width;
    return myArea < otherArea;
}

// 3. Unary Overload
void rectangle::operator++() {
    this->length += 1.0;
    this->width += 1.0;
}

// --- Main Program ---
int main() {
    float len1, wid1, len2, wid2;
    std::string col1, col2;

    // --- GET USER INPUT ---
    std::cout << "--- Create Rectangle 1 ---" << std::endl;
    std::cout << "Enter length: ";
    std::cin >> len1;
    std::cout << "Enter width: ";
    std::cin >> wid1;
    std::cout << "Enter colour: ";
    std::cin >> col1;

    rectangle rect1(len1, wid1);
    rect1.colour = col1;

    std::cout << "\n--- Create Rectangle 2 ---" << std::endl;
    std::cout << "Enter length: ";
    std::cin >> len2;
    std::cout << "Enter width: ";
    std::cin >> wid2;
    std::cout << "Enter colour: ";
    std::cin >> col2;

    rectangle rect2(len2, wid2);
    rect2.colour = col2;

    // --- TEST OPERATORS WITH USER INPUT ---
    
    std::cout << "\n======================================" << std::endl;
    std::cout << "       TESTING YOUR OPERATORS         " << std::endl;
    std::cout << "======================================" << std::endl;

    std::cout << "\n--- 1. Testing Arithmetic (+ and -) ---" << std::endl;
    rectangle addedRect = rect1 + rect2; 
    std::cout << "rect1 + rect2 = ";
    addedRect.info();

    rectangle subRect = rect1 - rect2;
    std::cout << "rect1 - rect2 = ";
    subRect.info();

    std::cout << "\n--- 2. Testing Comparison (== and <) ---" << std::endl;
    if (rect1 == rect2) {
        std::cout << "-> rect1 and rect2 have the EXACT same dimensions!" << std::endl;
    } else {
        std::cout << "-> rect1 and rect2 are different sizes." << std::endl;
    }

    if (rect1 < rect2) {
        std::cout << "-> rect1 has a SMALLER area than rect2." << std::endl;
    } else {
        std::cout << "-> rect1 is NOT smaller than rect2." << std::endl;
    }

    std::cout << "\n--- 3. Testing Unary (++) ---" << std::endl;
    std::cout << "rect1 BEFORE incrementing: ";
    rect1.info();
    
    ++rect1; // Automatically adds 1 to length and width
    
    std::cout << "rect1 AFTER incrementing (++): ";
    rect1.info();

    return 0;
}   