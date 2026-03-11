#include <iostream>
#include <string>


void Pointer_to_BASE_class();
void Virtual_methods();

int main() {

    using namespace std;

    int choice;

    do {
        cout << "\n================================" << endl;
        cout << "   CHOOSE A SECTION TO RUN" << endl;
        cout << "================================" << endl;
        cout << "1. Pointer to BASE class" << endl;
        cout << "2. virtual methods" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "--------------------------------\n" << endl;

        switch (choice) {
            case 1: Pointer_to_BASE_class(); break;
            case 2: Virtual_methods(); break;
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
            int width, hight;
            void set_values (int a, int B) {width = a; hight = B;}
            void show_area() {std::cout << "Polygon" << std::endl; }
    };


    class rectangle : public polygon {
        public:
        int area() {return width * hight;}
            void show_area() {std::cout << "Area of rectangle: " << area() << std::endl;}
    };


    class triangle : public polygon {
        public:
            int area() {return width * hight / 2;}
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
    };

    class triangle : public polygon {
        public:
            triangle (float w, float h) {set_values(w, h);}
            float area() {return width * hight / 2;}
            void show_area() {std::cout << "Area of triangle: " << area() << std::endl;}
    };
}