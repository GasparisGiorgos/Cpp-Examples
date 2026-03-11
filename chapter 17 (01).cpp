#include <iostream>
#include <string>


void Pointer_to_BASE_class();
void Virtual_methods();
void Abstract_classes();

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
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "--------------------------------\n" << endl;

        switch (choice) {
            case 1: Pointer_to_BASE_class(); break;
            case 2: Virtual_methods(); break;
            case 3: Abstract_classes(); break;
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

    class shape {
        public:
            virtual void draw() = 0; // pure virtual function
            void show() {std::cout << "This is a shape." << std::endl;}
    };

    class circle : public shape {
        public:
            void area() {std::cout << "Area of circle: " << 3.14 * 5 * 5 << std::endl;}
            void draw() {std::cout << "Drawing a circle." << std::endl;}
            void show() {area();} // Calls the area() function
    };

    class square : public shape {
        public:
            void area() {std::cout << "Area of square: " << 5 * 5 << std::endl;}
            void draw() {std::cout << "Drawing a square." << std::endl;}
            void show() {area();} // Calls the area() function
    };

    std::cout << "Give Radius for circle: ";
        float radius;
            std::cin >> radius;
    std::cout << "Give side length for square: ";
        float side;
            std::cin >> side;
    std::cout << std::endl;

    circle c;
    square s;

    shape *ptr = &c;
    shape *ptr2 = &s;

    ptr->show(); // Calls circle's area() through the base class pointer
        std::cout << "Abstract class method called through base class pointer for circle" << std::endl;
            std::cout << std::endl;

    ptr2->show(); // Calls square's area() through the base class pointer
        std::cout << "Abstract class method called through base class pointer for square" << std::endl;
            std::cout << std::endl;
}