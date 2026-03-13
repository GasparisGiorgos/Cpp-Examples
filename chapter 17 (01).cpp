#include <iostream>
#include <string>

float radius, side;

void Pointer_to_BASE_class();
void Virtual_methods();
void Abstract_classes();
void Multiple_inheritance();
void multiple_virtual_constr();

int main() {

    using namespace std;

    int choice;

    do {
        cout << "\n================================" << endl;
        cout << "   CHOOSE A SECTION TO RUN" << endl;
        cout << "================================" << endl;
        cout << "1. Pointer to BASE class" << endl;
        cout << "2. virtual methods" << endl;
        cout << "3. Abstract classes" << endl;
        cout << "4. Multiple Inheritance" << endl;
        cout << "5. Multiple Inheritance and construction" <<endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "--------------------------------\n" << endl;

        switch (choice) {
            case 1: Pointer_to_BASE_class(); break;
            case 2: Virtual_methods(); break;
            case 3: Abstract_classes(); break;
            case 4: Multiple_inheritance(); break;
            case 5: multiple_virtual_constr(); break;
            case 0: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}



void Pointer_to_BASE_class() {

    int input_width, input_hight;


    class polygon {
        public:
            float width, hight;
            void set_values (float a, float B) {width = a; hight = B;}
            void show_area() {std::cout << "Polygon" << std::endl; }
    };


    class rectangle : public polygon {
        public:
        float area() {return width * hight;}
            void show_area() {std::cout << "Area of rectangle: " << area() << std::endl;}
    };


    class triangle : public polygon {
        public:
            float area() {return width * hight / 2;}
            void show_area() {std::cout << "Area of triangle: " << area() << std::endl;}
    };

    rectangle rect;
    triangle trgl;

    polygon *ptr = &rect;
    polygon *ptr2 = &trgl;
    polygon *ptr1 = &rect;
    
    std::cout << "Give values for width: ";
    std::cin >> input_width;
    std::cout << "Give values for hight: ";
    std::cin >> input_hight;

    ptr1->set_values(input_width, input_hight);
    ptr2->set_values(input_width, input_hight);

    rect.show_area();
    trgl.show_area();
}


void Virtual_methods() {
    class polygon {
        public:
            int width, hight;
            void set_values (int a, int B) {width = a; hight = B;}
            virtual void show_area() = 0; // pure virtual function
            virtual float area() = 0; // pure virtual function
    };

    class rectangle : public polygon {
        public:
            rectangle (float w, float h) {width = w; hight = h;}
            float area() {return width * hight;}
            void show_area() {
                std::cout << "Virtual method called for rectangle" << std::endl;
                std::cout << "Area of rectangle: " << area() << std::endl; 
            }
    };

    class triangle : public polygon {
        public: 
            triangle (float w, float h) {set_values(w, h);}
            float area() {return width * hight / 2;}
            void show_area() {
                std::cout << "Virtual method called for triangle" << std::endl;
                std::cout << "Area of triangle: " << area() << std::endl; 
            }
    };


    std::cout << "Give values for width: ";
    float input_width;
    std::cin >> input_width;
    std::cout << "Give values for hight: ";
    float input_hight;
    std::cin >> input_hight;
    std::cout << std::endl;

    rectangle rect(input_width, input_hight);
    triangle trgl(input_width, input_hight);

    polygon *ptr = &rect;
    polygon *ptr2 = &trgl;

    ptr->show_area(); // Calls rectangle's area() through the base class pointer
    std::cout << "Virtual Method called through base class pointer for rectangle" << std::endl;
    std::cout << std::endl;
    ptr2->show_area(); // Calls triangle's area() through the base class pointer
    std::cout << "Virtual Method called through base class pointer for triangle" << std::endl;
    std::cout << std::endl;
}


void Abstract_classes() {

    float radius, side;
    radius = 0.0f;
    side = 0.0f;

    
    class shape {
        public:
            virtual void draw() = 0; // pure virtual function
            virtual void show() {std::cout << "This is a shape." << std::endl;}
    };

    class circle : public shape {
        public:

        float radius; // Declare radius as a member variable
        
            void area() {std::cout << "Area of circle: " << 3.14 * radius * radius << std::endl;}
            void draw() {std::cout << "Drawing a circle." << std::endl;}
            void show() {area();} // Calls the area() function
    };

    class square : public shape {
        public:

        float side; // Declare side as a member variable
            void area() {std::cout << "Area of square: " << side * side << std::endl;}
            void draw() {std::cout << "Drawing a square." << std::endl;}
            void show() {area();} // Calls the area() function
    };

    circle c;
    square s;

    std::cout << "Give Radius for circle: ";
            std::cin >> c.radius;
    std::cout << "Give side length for square: ";
            std::cin >> s.side;
    std::cout << std::endl;

    shape *ptr = &c;
    shape *ptr2 = &s;

    ptr->show(); // Calls circle's area() through the base class pointer
        std::cout << "Abstract class method called through base class pointer for circle" << std::endl;
            std::cout << std::endl;

    ptr2->show(); // Calls square's area() through the base class pointer
        std::cout << "Abstract class method called through base class pointer for square" << std::endl;
            std::cout << std::endl;
}

void Multiple_inheritance() {

    class Alpha {
        int Variable_A;
    public:
        void set_A(int x) {Variable_A=x;}
        void show_A() {std::cout << "Variable_A= " << Variable_A << std::endl;}
    };


    class Beta {
        int Variable_B;
    public:
        void set_B(int x) {Variable_B=x;}
        void show_B() {std::cout << "Variable_B= " << Variable_B << std::endl;}
    };


    class Alpha_Beta: public Alpha, public Beta {
        public:
            void show_AB() {std::cout << "Object AB" << std::endl;}
    };


    int temp_value_A, temp_value_B;
    Alpha_Beta Object;

    std::cout <<"Give Value to Variable_A: ";
        std::cin >> temp_value_A;
        Object.set_A(temp_value_A);
    
    std::cout <<"Gve value to Variable_B: ";
        std::cin >> temp_value_B;
        Object.set_B(temp_value_B);
    

    std::cout << "\n------PRINTING VALUES------" << std::endl;
    Object.show_A();
    Object.show_B();
    Object.show_AB();
}


void multiple_virtual_constr(){

// Base Class A
class Alpha {
public:
    int var_a;
    
    Alpha(int a) {
        var_a = a;
        std::cout << "Constructor A called. var_a = " << var_a << std::endl;
    }
    
    virtual ~Alpha() {
        std::cout << "Destructor A called." << std::endl;
    }
};

// Base Class B
class Beta {
public:
    int var_b;
    
    Beta(int b) {
        var_b = b;
        std::cout << "Constructor B called. var_b = " << var_b << std::endl;
    }
    
    virtual ~Beta() {
        std::cout << "Destructor B called." << std::endl;
    }
};

// Derived Class AB inheriting from both A and B
class Alpha_Beta : public Alpha, public Beta {
public:
    int total_sum;
    int var_ab;

    Alpha_Beta(int a, int b, int ab) : Alpha(a), Beta(b) {
        var_ab = ab;
        // AB "inherits" access to var_a and var_b
        total_sum = var_a + var_b + var_ab; 
        std::cout << "The combined sum is: " << total_sum << std::endl;
    }

        ~Alpha_Beta() {
        std::cout << "Destructor AB called." << std::endl;
    }

};

    int input_a, input_b, input_ab;

    std::cout << "Enter a value for var_a: ";
    std::cin >> input_a;

    std::cout << "Enter a value for var_b: ";
    std::cin >> input_b;

    std::cout << "Enter a value for var_ab: ";
    std::cin >> input_ab;

    std::cout << "\n--- Creating object of AB ---" << std::endl;
    
    // 2. Create the object inside a scoped block using the user's variables
        Alpha_Beta my_object(input_a, input_b, input_ab);
  
    
    std::cout << "--- Object has been destroyed ---" << std::endl;

};