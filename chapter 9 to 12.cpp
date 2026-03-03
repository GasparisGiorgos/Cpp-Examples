#include <iostream>

void pointer();
void pointerArithmetic();
void pointer_in_pointer();
void pointer_functions();
void one_dimentional_array();
void two_dimentional_array();
void two_dimentional_array_with_structs();
void structs_and_unions();
void enums_and_typedefs();
void dynamic_memory_allocation_in_pointers();
void advanced_dynamic_memory_allocation_in_pointers();


// Function to swap two integers using pointers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
// end of swap function

int main() {

    using namespace std;

    int choice;

    do {
        cout << "\n================================" << endl;
        cout << "   CHOOSE A SECTION TO RUN" << endl;
        cout << "================================" << endl;
        cout << "1.pointers" << endl;
        cout << "2 pointer arithmetic" << endl;
        cout << "3 pointer in pointer" <<endl;
        cout << "4 dynamic memory allocation in pointers" << endl;\
        cout << "5 pointer functions" << endl;
        cout << "6 advanced dynamic memory allocation in pointers" << endl;
        cout << "7 one dimentional array" << endl;
        cout << "8 two dimentional array" << endl;
        cout << "9 two dimentional array with structs" << endl;
        cout << "10 structs and unions" << endl;
        cout << "11 enums and typedefs" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "--------------------------------\n" << endl;

        switch (choice) {
            case 1: pointer(); break;
            case 2: pointerArithmetic(); break;
            case 3: pointer_in_pointer(); break;
            case 4: dynamic_memory_allocation_in_pointers(); break;
            case 5: pointer_functions(); break;
            case 6: advanced_dynamic_memory_allocation_in_pointers(); break;
            case 7: one_dimentional_array(); break;
            case 8: two_dimentional_array(); break;
            case 9: two_dimentional_array_with_structs(); break;
            case 10: structs_and_unions(); break;
            case 11: enums_and_typedefs(); break;
            case 0: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}

void pointer() {

    const char *bpoint;
    int a, b, *c;
    
    c = &a;
    a = 10;

    bpoint= "pointer A.\n";
    std::cout << "pointer: " << b << std::endl;

    std::cout << "\nValue of a: " << a << std::endl;
        std::cout << "Address of a: " << &a << std::endl;
            std::cout << "Value of c (address of a): " << c << std::endl;
                std::cout << "Value pointed to by c (value of a): " << *c << std::endl;
}

void pointerArithmetic() {

int *ptr, b;

ptr = &b;

b = 20; 
std::cout << "\nValue of b: " << b << std::endl;
    std::cout << "Address of b: " << &b << std::endl;
        std::cout << "Value of ptr (address of b): " << ptr << std::endl;
            std::cout << "Value pointed to by ptr (value of b): " << *ptr << std::endl;

ptr = ptr + 1;
std::cout << "\nAfter incrementing pointer:" << std::endl;
    std::cout << "Value of ptr (address after increment): " << ptr << std::endl;
        std::cout << "Value pointed to by ptr (undefined behavior): " << *ptr << std::endl;

++ptr;
std::cout << "\nAfter incrementing pointer again:" << std::endl;
    std::cout << "Value of ptr (address after second increment): " << ptr << std::endl;
        std::cout << "Value pointed to by ptr (undefined behavior): " << *ptr << std::endl;
}


void pointer_in_pointer(){

    int a;
    int *ptr1 = &a;
    int **ptr2 = &ptr1;

    std::cout << "Give Value of a: ";
    std::cin >> a;

    std::cout << "\nvalue of a:" << a << std::endl;
        std::cout << "address of a:" << &a << std::endl;
            
    std::cout << "value of ptr1:" << ptr1 << std::endl;
        std::cout << "value pointed to by ptr1 (value of a):" << *ptr1 << std::endl;
    
    std::cout << "value of ptr2:" <<ptr2 << std::endl;
        std::cout << "value pointed by ptr2 (adress of ptr1):" << *ptr2 << std::endl;
            std::cout << "value pointed by value, pointed by ptr2 (value of a):" << **ptr2 << std::endl;

}


void pointer_functions() {

    int a, b;

    std::cout << "Enter value of a: ";
        std::cin >> a;
    std::cout << "Enter value of b: ";
        std::cin >> b;

        std::cout << "Before swap: a=" << a << std::endl;
        std::cout << "Before swap: b=" << b << std::endl;

    swap(&a, &b);

        std::cout << "After swap: a=" << a << std::endl;
        std::cout << "After swap: b=" << b << std::endl;
}

void dynamic_memory_allocation_in_pointers() {

    int *ptr = new int;
    std::cout << "Enter an integer: ";
        std::cin >> *ptr;

        std::cout << "\nMemory allocated at address: " << ptr << std::endl;
            std::cout << "Value stored at allocated memory: " << *ptr << std::endl;
    
    std::cout << "The value you entered is: " << *ptr << std::endl;
        delete ptr;
}

void one_dimentional_array() {

    int arr[5];

    std::cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++) {
        std::cout << "Give value for element " << i << ": ";
        std::cin >> arr[i];
    }

    std::cout << "\n Your array: ";
    std::cout << "\n-------------------" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n-------------------" << std::endl;
    std::cout << std::endl;
}

void advanced_dynamic_memory_allocation_in_pointers() {

    int size;
    std::cout << "Enter the size of the array: ";
        std::cin >> size;

    int *arr = new int[size];

    std::cout << "Enter " << size << " integers: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Give value for element " << i << ": ";
        std::cin >> arr[i];
    }

    std::cout << "\nYour array: " << std::endl;
    std::cout << "-------------------" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n-------------------" << std::endl;
    std::cout << std::endl;

    delete[] arr;
}

void two_dimentional_array() {

    int arr[4][3];

    std::cout << "Enter 24 integers for an 4x3 matrix: " << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "Give value for element [" << i << "][" << j << "]: ";
            std::cin >> arr[i][j];
        }
    }

    std::cout << "\nYour 4x3 matrix: " << std::endl;
    std::cout << "-------------------" << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    std::cout << std::endl;
}

void two_dimentional_array_with_structs() {

    struct Student {
        std::string name;
        int age;
        int grade;
    };

    Student students[2][3];

    std::cout << "Enter details for 6 students (2x3 matrix): " << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "Student [" << i << "][" << j << "] Name: ";
            std::cin >> students[i][j].name;
            std::cout << "Student [" << i << "][" << j << "] Age: ";
            std::cin >> students[i][j].age;
            std::cout << "Student [" << i << "][" << j << "] Grade: ";
            std::cin >> students[i][j].grade;
        }
    }

    std::cout << "\nStudent Details: " << std::endl;
    std::cout << "-------------------" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "Student [" << i << "][" << j << "] Name: ";
            std::cout << students[i][j].name;
            std::cout << ", Age: ";
            std::cout << students[i][j].age;
            std::cout << ", Grade: ";
            std::cout << students[i][j].grade;
            std::cout << std::endl;
        }
    }
    std::cout << "-------------------" << std::endl;
    std::cout << std::endl;
}

void structs_and_unions() {

    struct Point {
        int x;
        int y;
    };

    union Data {
        int i;
        float f;
        char str[20];
    };

    std::cout << "do you want to make a struct or a union? (1 for struct, 2 for union): ";
    int choice;
    std::cin >> choice;

    switch (choice) { 
    case 1: {
        Point p;
        std::cout << "Enter x and y coordinates: ";
        std::cout << "\nx: ";
            std::cin >> p.x;
        std::cout << "\ny: ";
            std::cin >> p.y;

        std::cout << "\nPoint coordinates: (" << p.x << ", " << p.y << ")" << std::endl;
    break;
    }
    case 2: {
        std::cout << "\nNote: Since it's a union, only the last assigned value is valid." << std::endl;

        Data data;
        std::cout << "Enter an integer: ";
            std::cin >> data.i;
        std::cout << "You entered integer: " << data.i << std::endl;
        std::cout << "Current union state - Integer: " << data.i << ", Float: " << data.f << ", String: " << data.str << std::endl;

        std::cout << "Enter a float: ";
            std::cin >> data.f;
        std::cout << "You entered float: " << data.f << std::endl;
            std::cout << "\nNote: The integer value may not be valid due to union behavior." << std::endl;
            std::cout << "Current union state - Integer: " << data.i << ", Float: " << data.f << ", String: " << data.str << std::endl;

        std::cout << "Enter a string: ";
            std::cin >> data.str;
        std::cout << "You entered string: " << data.str << std::endl;

        std::cout << "\nNote: The integer and float values may not be valid after entering the string due to union behavior." << std::endl;
        std::cout << "Current union state - Integer: " << data.i << ", Float: " << data.f << ", String: " << data.str << std::endl;
    break;
    }
    default:
        std::cout << "Invalid choice!" << std::endl;
    break;
    }
}

void enums_and_typedefs() {

    enum Color { RED, GREEN, BLUE };

    typedef struct {
        std::string name;
        int age;
    } Person;

    std::cout << "Choose a color (0 for RED, 1 for GREEN, 2 for BLUE): ";
    int colorChoice;
    std::string colorName;

        std::cin >> colorChoice;
    
    switch (colorChoice) {
        case RED: 
            std::cout << "You selected RED." << std::endl; 
            colorName = "RED"; 
            break;
        case GREEN: 
            std::cout << "You selected GREEN." << std::endl; 
            colorName = "GREEN"; 
            break;
        case BLUE: 
            std::cout << "You selected BLUE." << std::endl; 
            colorName = "BLUE"; 
            break;
        default: 
            std::cout << "Invalid color choice!" << std::endl; 
            colorName = "UNKNOWN"; 
            break;
    }


    Person person;
    std::cout << "Enter name: ";
    std::cin >> person.name;
    std::cout << "Enter age: ";
    std::cin >> person.age;

    std::cout << "Person Details - Name: " << person.name << ", Age: " << person.age << ", selected color: " << colorName << std::endl;
}