#include <iostream>
#include <cmath>
#include <string>


void checkCharType();
void variableDemo();
void checkOrder();
void nameSurnameInput();
void mathOperations();
void simpleArithmetic();
void typeCasting();
void FunctionOverloading();
void static_test();




    void test (int x);
    void test (float z);
    void test (std::string s);

    

    void test (int x) {
        using namespace std;

        cout << "Integer: " << x << endl;
    }

    void test (float x) {
        using namespace std;
        cout << "Float: " << x << endl;
    }

    void test (std::string s) {
        using namespace std;
        cout << "String: " << s << endl;
    }


int main() {

    using namespace std;

    int choice;

    do {
        cout << "\n================================" << endl;
        cout << "   CHOOSE A SECTION TO RUN" << endl;
        cout << "================================" << endl;
        cout << "1. ASCII & Character Type Check" << endl;
        cout << "2. String/Char Variable" << endl;
        cout << "3. Check if Numbers are Ordered" << endl;
        cout << "4. Name and Surname Input" << endl;
        cout << "5. Power and Square Root" << endl;
        cout << "6. Simple Arithmetic (a+b)*c" << endl;
        cout << "7. Float to Int Type Casting" << endl;
        cout << "8. Function Overloading " << endl;
        cout << "9. Static Variable " << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "--------------------------------\n" << endl;

        switch (choice) {
            case 1: checkCharType(); break;
            case 2: variableDemo(); break;
            case 3: checkOrder(); break;
            case 4: nameSurnameInput(); break;
            case 5: mathOperations(); break;
            case 6: simpleArithmetic(); break;
            case 7: typeCasting(); break;
            case 8: FunctionOverloading(); break;
            case 9: static_test(); break;
            case 0: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}



void checkCharType() {
    
    std::string name;
    char key;
    bool is_capital = false;

    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Press any key: ";
    std::cin >> key;

    int ascii_code = key;
    if (key >= 'A' && key <= 'Z') is_capital = true;

    std::cout << "Hello " << name << std::endl;
    std::cout << "ASCII code: " << ascii_code << std::endl;

    if (is_capital) {
        std::cout << "Type: Capital Letter" << std::endl;
    } else if (key >= 'a' && key <= 'z') {
        std::cout << "Type: Small Letter" << std::endl;
    } else if (key >= '0' && key <= '9') {
        std::cout << "Type: Number" << std::endl;
    } else {
        std::cout << "Type: Special Symbol" << std::endl;
    }
}

void variableDemo() {

    using namespace std;

    string number = "five";
    char number_number = '3';
    number_number = 65; // This will print 'A' due to ASCII 65

    cout << "String value: " << number << endl;
    cout << "Char value (ASCII 65): " << number_number << endl;
}

void checkOrder() {
    
    float a, b, c;
    std::cout << "Give values for a, b, and c: ";
    std::cin >> a >> b >> c;

    bool ordered = (a <= b && b <= c);
    if (ordered) {
        std::cout << "The numbers were given in the correct order." << std::endl;
    } else {
        std::cout << "The numbers were NOT given in the correct order." << std::endl;
    }
}

void nameSurnameInput() {
    using namespace std;
    string str1, str2;
    cout << "Give name: ";
    cin >> str1;
    cout << "Give surname: ";
    cin >> str2;
    cout << "Stored: " << str1 << " " << str2 << endl;
}

void mathOperations() {

    double c, t;
    int a = 4, b = 5;
    c = pow(a, b);
    std::cout << "The power of " << a << "^" << b << " is: " << c << std::endl;
    t = sqrt(200.0);
    std::cout << "Square root of 200 is: " << t << std::endl;
}

void simpleArithmetic() {
    using namespace std;
    int a = 12, b = 15, c = 20;
    cout << "(a + b) * c = " << (a + b) * c << endl;
}

void typeCasting() {
    
    using namespace std;

    float num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    

    cout << "The numbers as floats: " << num1 << ", " << num2 << ", " << num3 << endl;
    cout << "The numbers as integers: " << (int)num1 << ", " << (int)num2 << ", " << (int)num3 << endl;
}

void FunctionOverloading() {
        int x;
        float z;
        std::string s;

    std::cout << "Enter and Intiger: " << std::endl;
        std::cin >> x;
    std::cout << "Enter and Float: " << std::endl;
        std::cin >> z;
    std::cout << "Enter and String: " << std::endl;
        std::cin >> s;

    test(x);
    test(z);
    test(s);
    
    std::cout << "Function overloading demo complete." << std::endl;
}

void static_test(){
int i = 0;
static int x = 0;

for (i=1; i <= 5; i++) {
    std::cout << "This is a static variable demo. Value: " << x << std::endl;
    x++;
}

std::cout << "Final value of static variable x: " << x << std::endl;
}